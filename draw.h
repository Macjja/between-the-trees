/* Declarations for the drawing thread */

#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

#include <ctime>
#include <allegro5/allegro.h>
#include "game.h"
#include "window.h"
#include "scene.h"
#include "dialogue.h"

void* drawer(ALLEGRO_THREAD*, void*);

#endif