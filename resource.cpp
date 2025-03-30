/* Implementation of the ResourceLoader class
 *
 * The load function is incomplete since we don't yet
 * have any resources to load.
*/

#include "resource.h"

ResourceLoader::ResourceLoader()
{
    font = al_create_builtin_font();
    textContainer = al_create_bitmap(0, 0);
    nameContainer = al_create_bitmap(0, 0);
    numBackgrounds = 0;
    backgrounds = NULL;
}
ResourceLoader::~ResourceLoader()
{
    al_destroy_font(font);
    al_destroy_bitmap(textContainer);
    al_destroy_bitmap(nameContainer);
    for (int i = 0; i < numBackgrounds; i++)
        al_destroy_bitmap(backgrounds[i]);
}

void ResourceLoader::load(int bank)
{
    //more coming soon!
    switch (bank)
    {
        default:
            break;
    }
}

ALLEGRO_FONT* ResourceLoader::get_font() const
{
    return font;
}
ALLEGRO_BITMAP* ResourceLoader::get_text_container() const
{
    return textContainer;
}
ALLEGRO_BITMAP* ResourceLoader::get_name_container() const
{
    return nameContainer;
}
ALLEGRO_BITMAP* ResourceLoader::get_background(int index) const
{
    return backgrounds[index];
}
