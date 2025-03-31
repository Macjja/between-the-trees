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
        void set_click_event(void (*)(Scene*, int, int));
        void set_key_press_event(void (*)(Scene*, int, int));
        void set_dialogue_end_event(void (*)(Scene*, int, int));
    private:
        void (*clickEvent)(Scene*, int, int);
        void (*keyPressEvent)(Scene*, int);
        void (*dialogueEndEvent)(Scene*);
        ALLEGRO_BITMAP* background;
};

#endif