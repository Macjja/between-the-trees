/* Implementation of the Scene class */

#include "scene.h"

Scene::Scene(ResourceLoader* data, void (*ce)(Scene*, int, int), void (*kpe)(Scene*, int), void (*dee)(Scene*), int bgIndex)
{
    clickEvent = ce;
    keyPressEvent = kpe;
    dialogueEndEvent = dee;
    plot = 0;
    background = data.backgrounds[bgIndex];
}

void Scene::click_event(int x, int y)
{
    if (clickEvent != NULL)
        clickEvent(this, x, y);
}
void Scene::key_press_event(int keyCode)
{
    if (keyPressEvent != NULL)
        keyPressEvent(this, keyCode);
}
void Scene::dialogue_end_event()
{
    if (dialogueEndEvent != NULL)
        dialogueEndEvent(this);
}
int& Scene::get_plot()
{
    return plot;
}
