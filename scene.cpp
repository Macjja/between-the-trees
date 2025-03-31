/* Implementation of the Scene class */

#include "scene.h"

Scene::Scene(ResourceLoader* data, void (*ce)(Scene*, int, int), void (*kpe)(Scene*, int), void (*dee)(Scene*), int bgIndex)
{
    clickEvent = ce;
    keyPressEvent = kpe;
    dialogueEndEvent = dee;
    background = data.backgrounds[bgIndex];
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

void Scene::set_click_event(void (*ce)(Scene*, int, int))
{
    clickEvent = ce;
}
void Scene::set_key_press_event(void (*kpe)(Scene*, int))
{
    keyPressEvent = kpe;
}
void Scene::set_dialogue_end_event(void (*dee)(Scene*))
{
    dialogueEndEvent = dee;
}
