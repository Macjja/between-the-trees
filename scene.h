/* Declarations for the Scene class */

#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include <allegro5/allegro.h>
#include "resource.h"

class Scene
{
    public:
        Scene(ResourceLoader*, void (*)(Scene*, int, int), void (*)(Scene*, int), void (*)(Scene*), int);
        void click_event(int, int) const;
        void key_press_event(int) const;
        void dialogue_end_event() const;
        int& get_plot();
    private:
        void (*clickEvent)(Scene*, int, int);
        void (*keyPressEvent)(Scene*, int);
        void (*dialogueEndEvent)(Scene*);
        int plot;
        ALLEGRO_BITMAP* background;
};

#endif