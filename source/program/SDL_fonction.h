#ifndef SDL_FONCTION_H

//Using SDL and standard IO

//#include <SDL.h>
#include<SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SDL_FONCTION_H


//Starts up SDL and creates window
bool init(SDL_Window** gWindow, SDL_Surface** gScreenSurface);

//Loads media
bool loadMedia(SDL_Surface** gXOut);

#endif
