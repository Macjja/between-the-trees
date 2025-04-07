/* Implementation of the Game class */

#include "game.h"

Game::Game(void* (*event_proc)(ALLEGRO_THREAD*, void*), void* (*drawing_proc)(ALLEGRO_THREAD*, void*))
{
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
    shouldStop = false;
    
    al_start_thread(eventThread);
    al_start_thread(drawingThread);
}
Game::~Game()
{
    al_join_thread(eventThread, NULL);
    al_join_thread(drawingThread, NULL);
    al_destroy_thread(eventThread);
    al_destroy_thread(drawingThread);
    
    delete data;
    delete window;
}

Window& Game::get_window()
{
    return *window;
}
ResourceLoader& Game::get_data()
{
    return *data;
}
Scene* Game::get_scene()
{
    if (currentScene >= 0)
        return data->get_scene(currentScene);
    return NULL;
}
int& Game::get_scene_index()
{
    return currentScene;
}
void Game::set_dialogue_box(Dialogue* db)
{
    dialogueBox = db;
}
Dialogue* Game::get_dialogue_box() const
{
    return dialogueBox;
}

void Game::set_flag(int flag, bool val)
{
    int check = pow(2, flag);
    if (flag < 32)
    {
        if (check & flags == check && !val)
            flags -= check;
        else if (check & flags != check && val)
            flags += check;
    }
}
bool Game::get_flag(int flag) const
{
    int check = pow(2, flag);
    return (check & flags == check);
}

void Game::set_mouse_coords(int x, int y)
{
    mouseX = x;
    mouseY = y;
}
int Game::get_mouse_x() const
{
    return mouseX;
}
int Game::get_mouse_y() const
{
    return mouseY;
}

void Game::stop()
{
    shouldStop = true;
}
bool Game::should_stop()
{
    return shouldStop;
}
