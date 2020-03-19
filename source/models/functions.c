#include "stuctures.h"
#include "functions.h"


Image * createImage(int width, int height){
    Image *new_image = (Image*) malloc(sizeof(Image));
    new_image->width = h;
    new_image->height = l;
    new_image->ptrPixel = (Pixel*)malloc(l*h*sizeof(Pixel));
    return new_image;
}

unsigned char modifyPixel(int witdh, int height, Pixel pixel){
	double GRIS;
	GRIS = 0.2125*(image->ptrPixel[width*image->width + height]->red)+0.7154*(image->ptrPixel[width*image->width + height]->green)+0.0721*(image->ptrPixel[width*image->width + height]->blue);
	pixel->blue = GRIS;//image correspond à quoi vu qu'elle n'est pas dans les paramètres ?
	pixel->green= GRIS;
	pixel->red  = GRIS;
	image->ptrPixel[width*image->width + height]= pixel;
}
// JE CAPTE PAS TROP A QUOI ELLE SERT VRAIMENT CETTE FONCTION ?? RETOURNE UN UNSIGNED CHAR ?
	
	

Image * color_to_WB(Image * image){
	int i=0;
	int j=0;
	double GRIS;
	Pixel pixel =(Pixel)malloc(sizeof(Pixel));
    for(i; i<= image->width; i++){
	for(j; j<= image->height; j++){
	 GRIS = 0.2125*(image->ptrPixel[i*image->width + j]->red)+0.7154*(image->ptrPixel[i*image->width + j]->green)+0.0721*(image->ptrPixel[i*image->width + j]->blue);   
	 pixel->blue = GRIS;
	 pixel->green= GRIS;
 	 pixel->red  = GRIS; 
	 modifyPixel(image,i,j,pixel);
	 }
	}
	return imageWB;
}


void  freeImage(Image * image)
{
    free(image->ptrPixel);
    free(image);
}

Image[] imagesInter(Image * image1, Image * image2, int nombre_image){
    int i=0;
    Image* tab_images = (Image*)malloc(nombre_image*sizeof(Image));
    for(i;i<nombre_image;i++){
        image->ptrPixel = 
        tab_images[i]->ptrPixel[]
    }
    
} /*Renvoi un tableau d'image intermédiaire à partir de deux images et du nombre voulu*/
float calculateWeight (int nbImage, int numeroImage){
    return (numeroImage/nbImage); //nbImage commence à 1
}


Image* readBMPFile(char* filename, int verbose);
void writeBMPFile(char* filename, Image* im, int verbose);
