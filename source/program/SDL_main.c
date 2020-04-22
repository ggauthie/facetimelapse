
#include "SDL_fonction.h"
#include "BMPFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <SDL2/SDL_ttf.h>

#define MASQUE_ROUGE 0x000000ff
#define MASQUE_VERT  0x0000ff00
#define MASQUE_BLEU  0x00ff0000
#define MASQUE_ALPHA 0xff000000


//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gXOut = NULL;

void delays(int number_of_seconds)
{
// Converting time into milli_seconds
int milli_seconds = 1000 * number_of_seconds;
// Storing start time
clock_t start_time = clock();
// looping till required time is not achieved
while (clock() < start_time + milli_seconds) ;
}

int main( int argc, char* args[] )
{

	Image * image1 = readBMPFile("tiger.bmp",1);
	Image * image2 = readBMPFile("tiger.bmp",1);
	color_to_WB(image2);

	int nombre_image=20;

	Image* imageintermediaire;
	SDL_Surface** tableau = (SDL_Surface**) malloc(nombre_image*sizeof(SDL_Surface));



	for(int i=1;i<=nombre_image;i++){
		imageintermediaire = (imagesInter(image1,image2,nombre_image))+(2*(i-1));
		SDL_Surface* Surf =FTL_conversion_image_to_SDL(&imageintermediaire);
		tableau[i-1]=Surf;

	}

	//Start up SDL and create window
	if( !FTL_init(&gWindow,&gScreenSurface))
	{
		printf( "Failed to initialize!\n" );
	}

	else
	{
		//Load media
		if( !FTL_loadMedia(&gXOut) )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//TESTS de la conversion SDL vers image et sauvegarde sous format BMP

			//Image* im3 = FTL_conversion_SDL_to_image(&Surf);
			//writeBMPFile("test_conversionSDL.bmp", im3, 1);

			//While application is running
			while( !quit )
			{

				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = 1;
					}
				}
				//Initialisaton du temps
				//int tempsActuel = SDL_GetTicks ();
				//int temps_affichage= tempsActuel%5000;

				//Apply the image

					for(int j=0;j<nombre_image;j++){

				SDL_BlitSurface( tableau[j], NULL, gScreenSurface, NULL );

				//Update the surface
				SDL_UpdateWindowSurface( gWindow );
				delays(100);
				}

			}
		}
	}

	//Free resources and close SDL
	FTL_close(&gWindow, &gXOut);


	return 0;
}
