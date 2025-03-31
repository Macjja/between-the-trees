/* Implementation of the event thread */

void* event_reader(ALLEGRO_THREAD* thr, void* arg)
{
    Game* game = (Game*)arg;
    Window* window = game->get_window();
    
    bool shiftKey, ctrlKey, altKey;
    
    ALLEGRO_MOUSE_STATE mouseState;
    
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    al_register_event_source(events, al_get_display_event_source(window->get_display()));
    al_register_event_source(events, al_get_keyboard_event_source());
    al_register_event_source(events, al_get_mouse_event_source());
    ALLEGRO_EVENT event;
    
    while (true)
    {
        al_wait_for_event(queue, &event);
        
        al_get_mouse_state(&mouseState);
        Game->set_mouse_coords(
            (mouseState.x - window->get_bitmap_x()) / window->get_pix_width(),
            (mouseState.y - window->get_bitmap_y()) / window->get_pix_height()
        );
        
        Dialogue* dialogueBox = game->get_dialogue_box();
        
        if (event.type == ALLEGRO_EVENT_DISPLAY_RESIZE)
        {
            al_acknowledge_resize(window->get_display());
            window->fit_screen();
        }
        else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            delete game;
        }
        else if (event.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            if (event.keyboard.keycode == ALLEGRO_KEY_LSHIFT)
                shiftKey = true;
            else if (event.keyboard.keycode == ALLEGRO_KEY_LCTRL)
                ctrlKey = true;
            else if (event.keyboard.keycode == ALLEGRO_KEY_ALT)
                altKey = true;
            else if (event.keyboard.keycode == ALLEGRO_KEY_F11 || (altKey && event.keyboard.keycode == ALLEGRO_KEY_ENTER))
            {
                window->toggle_fullscreen();
                window->fit_screen();
            }
            else if (ctrlKey && altKey && event.keyboard.keycode == ALLEGRO_KEY_F)
            {
                window->set_fit_mode(w->get_fit_mode() + 1);
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_DOWN && dialogueBox != NULL)
            {
                //code here for choosing dialogue options
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_UP && dialogueBox != NULL)
            {
                //code here for choosing dialogue options
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && dialogueBox != NULL)
            {
                if (dialogueBox->get_state() == 0)
                    dialogueBox->get_state() = 1;
                else
                {
                    if (dialogueBox->next_line() == false)
                    {
                        delete dialogueBox;
                        game->set_dialogue_box(NULL);
                        game->get_scene().dialogue_end_event();
                    }
                }
            }
            else
                game->get_scene().key_press_event(event.keyboard.keycode);
        }
        else if (event.type == ALLEGRO_EVENT_KEY_UP)
        {
            if (event.keyboard.keycode == ALLEGRO_KEY_LSHIFT)
                shiftKey = false;
            else if (event.keyboard.keycode == ALLEGRO_KEY_LCTRL)
                ctrlKey = false;
            else if (event.keyboard.keycode == ALLEGRO_KEY_ALT)
                altKey = false;
        }
        else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            if (dialogueBox != NULL)
            {
                if (dialogueBox->get_state() == 0)
                    dialogueBox->get_state() = 1;
                else
                {
                    if (dialogueBox->next_line() == false)
                    {
                        delete dialogueBox;
                        game->set_dialogue_box(NULL);
                        game->get_scene().dialogue_end_event();
                    }
                }
            }
            else
                game->get_scene().click_event(mouseState.x, mouseState.y);
        }
        
        if (al_get_thread_should_stop(thr))
            break;
    }
    al_destroy_event_queue(queue);
    return NULL;
}
