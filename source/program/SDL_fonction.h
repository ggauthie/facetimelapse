#ifndef SDL_FONCTION_H

//Using SDL and standard IO

//#include <SDL.h>
#include<SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BMPFile.h"

#define SDL_FONCTION_H


//Starts up SDL and creates window
bool FTL_init(SDL_Window** gWindow, SDL_Surface** gScreenSurface);

//Loads media
bool FTL_loadMedia(SDL_Surface** gXOut);

//Frees media and shuts down SDL
void FTL_close(SDL_Window** gWindow, SDL_Surface** gXOut);

//conversion SDL to image structure function
Image * FTL_conversion_SDL_to_image(SDL_Surface** gXOut);

//conversion image to SDL structure function
SDL_Surface* FTL_conversion_image_to_SDL(Image ** image);

#endif
