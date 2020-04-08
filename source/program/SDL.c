#include "SDL_fonction.h"


//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool FTL_init(SDL_Window** gWindow, SDL_Surface** gScreenSurface)
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		*gWindow = SDL_CreateWindow( "SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( *gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Get window surface
			*gScreenSurface = SDL_GetWindowSurface( *gWindow );
		}
	}

	return success;
}

bool FTL_loadMedia(SDL_Surface** gXOut)
{
	//Loading success flag
	bool success = true;

	//Load splash image
	*gXOut = SDL_LoadBMP( "hello_world.bmp" );
	if( gXOut == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "03_event_driven_programming/x.bmp", SDL_GetError() );
		success = false;
	}

	return success;
}


//Frees media and shuts down SDL
void FTL_close(SDL_Window** gWindow,SDL_Surface** gXOut)
{
	//Deallocate surface
	SDL_FreeSurface(*gXOut);
	gXOut = NULL;

	//Destroy window
	SDL_DestroyWindow(*gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();

}

Image * FTL_conversion_SDL_to_image(SDL_Surface** gXOut){

	int x,y;
	//On transmet la hauteur et la largeur de l'image
	int height=(*gXOut)->h;
	int width=(*gXOut)->w;


	Image * im=createImage(width,height);

	for (x=0;x<width;x++)
	    {
	        for (y=0;y<height;y++)
	        {
					//définition du nombre d'octet par pixel et récupération du pixel de la surface
	        int nbOctetsParPixel = (*gXOut)->format->BytesPerPixel;
	        Uint8 *p = (Uint8 *)(*gXOut)->pixels + y * (*gXOut)->pitch + x * nbOctetsParPixel;
					//On complète les champs de la structure Pixel
	        im->ptrPixel[x +y*im->width].blue=*p;
	        im->ptrPixel[x +y*im->width].red=*p;
	        im->ptrPixel[x +y*im->width].green=*p;

	        }
	    }

	return im;
	}


	SDL_Surface* FTL_conversion_image_to_SDL(Image ** image){

	int height=(*image)->height;
	int width=(*image)->width;
	int x,y;
	SDL_Surface* Surf = NULL;

	Surf=SDL_CreateRGBSurface(SDL_SWSURFACE, width, height, 16, 0, 0, 0,0);

	for (y=0;y<height;y++)
			{
					for (x=0;x<width;x++)
					{

					Uint32 pixel;

							/*nbOctetsParPixel représente le nombre d'octets utilisés pour stocker un pixel.
					    En multipliant ce nombre d'octets par 8 (un octet = 8 bits), on obtient la profondeur de couleur
					    de l'image : 8, 16, 24 ou 32 bits.*/
					    int nbOctetsParPixel = Surf->format->BytesPerPixel;

							Uint8 b=(*image)->ptrPixel[x +y*(*image)->width].blue;
							Uint8 r=(*image)->ptrPixel[x +y*(*image)->width].red;
							Uint8 g=(*image)->ptrPixel[x +y*(*image)->width].green;
							Uint8 a=255;

							pixel=SDL_MapRGBA(Surf->format, r, g, b, a);//définition d'un pixel
					    Uint8 *p = (Uint8 *)Surf->pixels + y * Surf->pitch + x * nbOctetsParPixel;

					    /*Gestion différente suivant le nombre d'octets par pixel de l'image*/
					    switch(nbOctetsParPixel)
					    {
					        case 1:
					            *p = pixel;
					            break;

					        case 2:
					            *(Uint16 *)p = pixel;
					            break;

					        case 3:
					            /*Suivant l'architecture de la machine*/
					            if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
					            {
					                p[0] = (pixel >> 16) & 0xff;
					                p[1] = (pixel >> 8) & 0xff;
					                p[2] = pixel & 0xff;
					            }
					            else
					            {
					                p[0] = pixel & 0xff;
					                p[1] = (pixel >> 8) & 0xff;
					                p[2] = (pixel >> 16) & 0xff;
					            }
					            break;

					        case 4:
					            *(Uint32 *)p = pixel;
					            break;
					    }
			}
			}

	return Surf;

	}
