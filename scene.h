/* Declarations for the Scene class */

#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include <allegro5/allegro.h>

class Scene
{
    public:
        Scene(ALLEGRO_BITMAP*, void (*)(const Scene*), void (*)(const Scene*, int, int), void (*)(const Scene*, int), void (*)(const Scene*));
        void click_event(int, int) const;
        void key_press_event(int) const;
        void dialogue_end_event() const;
        void set_click_event(void (*)(const Scene*, int, int));
        void set_key_press_event(void (*)(const Scene*, int));
        void set_dialogue_end_event(void (*)(const Scene*));
        void draw();
    private:
        void (*clickEvent)(const Scene*, int, int);
        void (*keyPressEvent)(const Scene*, int);
        void (*dialogueEndEvent)(const Scene*);
        ALLEGRO_BITMAP* background;
};

#endif