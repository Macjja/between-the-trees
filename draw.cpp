/* Implementation of the drawing thread */

#include "draw.h"

void* drawer(ALLEGRO_THREAD* thr, void* arg)
{
    Game* game = (Game*)arg;
    Window& window = game->get_window();
    ResourceLoader& data = game->get_data();
    Scene* scene;
    Dialogue* dialogue;
    
    al_set_target_backbuffer(window.get_display());
    window.update();
    
    ALLEGRO_TIMER* fpsTimer = al_create_timer(1.0 / 60.0);
    ALLEGRO_EVENT_QUEUE* fpsQueue = al_create_event_queue();
    al_register_event_source(fpsQueue, al_get_timer_event_source(fpsTimer));
    ALLEGRO_EVENT event;
    
    al_start_timer(fpsTimer);
    
    while (true)
    {
        al_set_target_bitmap(window.get_bitmap());
        window.clear();
        
        scene = game->get_scene();
        if (scene != NULL)
        {
            scene->draw();
        }
        
        dialogue = game->get_dialogue_box();
        if (dialogue != NULL)
        {
            dialogue->draw(360);
        }
        
        al_set_target_backbuffer(window.get_display());
        window.update();
        
        if (game->should_stop())
        {
            break;
        }
        al_wait_for_event(fpsQueue, &event);
    }
    
    al_destroy_event_queue(fpsQueue);
    al_destroy_timer(fpsTimer);
    
    return NULL;
}
