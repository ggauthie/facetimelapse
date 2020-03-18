#include "stuctures.h"
#include "functions.h"


Image * createImage(int width, int height){
    Image *new_image = (Image*) malloc(sizeof(ImageRGB));
    new_image->width = h;
    new_image->height = l;
    new_image->raw_data = (PixelRGB*)malloc(l*h*sizeof(PixelRGB));
    return new_image;
}

unsigned char modifyPixel(int witdh, int height, PixelRGB pixel){
	double GRIS;
	GRIS = 0.2125*(image->rawdata[width*image->width + height]->red)+0.7154*(image->rawdata[width*image->width + height]->green)+0.0721*(image->rawdata[width*image->width + height]->blue);
	pixel->blue = GRIS;
	pixel->green= GRIS;
	pixel->red  = GRIS;
	image->rawdata[width*image->width + height]= pixel;
}
// JE CAPTE PAS TROP A QUOI ELLE SERT VRAIMENT CETTE FONCTION ?? RETOURNE UN UNSIGNED CHAR ?
	
	

Image * color_to_WB(Image * image){
	int i=0;
	int j=0;
	double GRIS;
	PixelRGB pixel =(pixel)malloc(sizeof(pixel));
    for(i; i<= image->width; i++){
	for(j; j<= image->height; j++){
	 GRIS = 0.2125*(image->rawdata[i*image->width + j]->red)+0.7154*(image->rawdata[i*image->width + j]->green)+0.0721*(image->rawdata[i*image->width + j]->blue);   
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
    free(image->raw_data);
    free(image);
}

Image[] imagesInter(Image * image1, Image * image2, int nombre_image){
    int i=0;
    Image* tab_images = (Image*)malloc(nombre_image*sizeof(Image));
    for(i;i<nombre_image;i++){
        image->raw_data = 
        tab_images[i]->raw_data[]
    }
    
} /*Renvoi un tableau d'image intermédiaire à partir de deux images et du nombre voulu*/
float calculateWeight (int nbImage, int numeroImage){
    return (numeroImage/(nbImage+1));
}


Image* readBMPFile(char* filename, int verbose);
void writeBMPFile(char* filename, Image* im, int verbose);
