/* Implementation of the Game class */

#include "game.h"

Game::Game(void* (*event_proc)(ALLEGRO_THREAD*, void*), void* (*drawing_proc)(ALLEGRO_THREAD*, void*))
{
    al_init();
    al_install_keyboard();
    al_install_mouse();
    al_init_primitives_addon();
    al_init_image_addon();
    al_init_font_addon();
    
    al_set_new_display_flags(ALLEGRO_OPENGL | ALLEGRO_RESIZABLE);
    al_set_new_display_option(ALLEGRO_CAN_DRAW_INTO_BITMAP, 1, ALLEGRO_REQUIRE);
    al_set_new_bitmap_flags(ALLEGRO_VIDEO_BITMAP);
    
    window = new Window(640, 480, 1280, 960);
    window->set_title("Between the Trees");
    
    data = new ResourceLoader();
    data->load(0);
    
    eventThread = al_create_thread(event_proc, this);
    drawingThread = al_create_thread(drawing_proc, this);
    
    if (data->get_num_scenes() > 0)
        currentScene = 0;
    else
        currentScene = -1;
    
    dialogueBox = NULL;
    flags = 0;
    
    al_start_thread(eventThread);
    al_start_thread(drawingThread);
}
Game::~Game()
{
    al_destroy_thread(eventThread);
    al_destroy_thread(drawingThread);
    
    delete data;
    delete window;
    
    al_shutdown_font_addon();
    al_shutdown_image_addon();
    al_shutdown_primitives_addon();
    al_uninstall_keyboard();
    al_uninstall_mouse();
    al_uninstall_system();
}

Window& Game::get_window()
{
    return window;
}
ResourceLoader& Game::get_data()
{
    return data;
}
Scene& Game::get_scene()
{
    return data->get_scene(currentScene);
}
int& Game::get_scene_index()
{
    return currentScene;
}
Dialogue& Game::get_dialogue_box()
{
    return dialogueBox;
}

void Game::set_flag(int flag, bool val)
{
    int check = pow(2, flag);
    if (flag < 32)
    {
        if (check & flags == check) && !val)
            flags -= check;
        else if (!(check & flags == check) && val)
            flags += check;
    }
}
bool Game::get_flag(int flag)
{
    return (check & flags == check);
}