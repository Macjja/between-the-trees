/* Implementation of the Scene class */

#include "scene.h"

Scene::Scene(ALLEGRO_BITMAP* bg, void (*startingFunc)(const Scene*), void (*ce)(const Scene*, int, int), void (*kpe)(const Scene*, int), void (*dee)(const Scene*))
{
    clickEvent = ce;
    keyPressEvent = kpe;
    dialogueEndEvent = dee;
    background = bg;
    
    startingFunc(this);
}

void Scene::click_event(int x, int y) const
{
    if (clickEvent != NULL)
        clickEvent(this, x, y);
}
void Scene::key_press_event(int keyCode) const
{
    if (keyPressEvent != NULL)
        keyPressEvent(this, keyCode);
}
void Scene::dialogue_end_event() const
{
    if (dialogueEndEvent != NULL)
        dialogueEndEvent(this);
}

void Scene::set_click_event(void (*ce)(const Scene*, int, int))
{
    clickEvent = ce;
}
void Scene::set_key_press_event(void (*kpe)(const Scene*, int))
{
    keyPressEvent = kpe;
}
void Scene::set_dialogue_end_event(void (*dee)(const Scene*))
{
    dialogueEndEvent = dee;
}

void Scene::draw()
{
    al_draw_bitmap(background, 0, 0, 0);
}
