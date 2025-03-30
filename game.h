/* Declarations for the Game class */

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <allegro5/allegro.h>
#include <cmath>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include "window.cpp"
#include "resource.cpp"
#include "scene.h"
#include "dialogue.h"

class Game {
    public:
        Game(void* (*)(ALLEGRO_THREAD*, void*), void* (*)(ALLEGRO_THREAD*, void*));
        ~Game();
        Window& get_window();
        ResourceLoader& get_data();
        Scene& get_scene();
        int& get_scene_index();
        Dialogue& get_dialogue_box();
        void set_flag(int, bool);
        bool get_flag(int) const;
    private:
        Window* window;
        ResourceLoader* data;
        ALLEGRO_THREAD* eventThread;
        ALLEGRO_THREAD* drawingThread;
        int currentScene;
        Dialogue* dialogueBox;
        int flags;
};

#endif