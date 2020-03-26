
#include "SDL_fonction.h"

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gXOut = NULL;

//Frees media and shuts down SDL
void close()
{
	//Deallocate surface
	SDL_FreeSurface(gXOut);
	gXOut = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	//SDL_Quit();

}


int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init(&gWindow,&gScreenSurface))
	{
		printf( "Failed to initialize!\n" );
	}

	else
	{
		//Load media
		if( !loadMedia(&gXOut) )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

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

				//Apply the image
				SDL_BlitSurface( gXOut, NULL, gScreenSurface, NULL );

				//Update the surface
				SDL_UpdateWindowSurface( gWindow );

			}
		}
	}

	//Free resources and close SDL
	close();
    SDL_Quit();

	return 0;
}

