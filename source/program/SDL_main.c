
#include "SDL_fonction.h"
#include "BMPFile.h"

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


int main( int argc, char* args[] )
{
	//Création des images
	SDL_Surface* tableau[2];
	Image* im1 = readBMPFile("hello_world.bmp",1);
	Image* im2 = createImage(640,480);

				Pixel pixel1 = {255,0,255};
				Pixel pixel2 = {0,255,0};
				for(int x=0;x<im2->width;x++){
					for(int y=0;y<im2->height;y++){
						setPixel(im2,x,y,pixel2);
					}
				}
	//Conversion des images vers la structure SDL_Surface
	SDL_Surface* Surf1 =FTL_conversion_image_to_SDL(&im1);
	SDL_Surface* Surf2 =FTL_conversion_image_to_SDL(&im2);

	//Remplissage du tableau
	tableau[0]=Surf1;
	tableau[1]=Surf2;

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
				int tempsActuel = SDL_GetTicks ();
				int temps_affichage= tempsActuel%5000;

				//Apply the image
				if(temps_affichage==1){
				SDL_BlitSurface( tableau[1], NULL, gScreenSurface, NULL );

				//Update the surface
				SDL_UpdateWindowSurface( gWindow );}

				if(temps_affichage==2500){
				SDL_BlitSurface( tableau[0], NULL, gScreenSurface, NULL );

				//Update the surface
				SDL_UpdateWindowSurface( gWindow );}

			}
		}
	}

	//Free resources and close SDL
	FTL_close(&gWindow, &gXOut);


	return 0;
}
