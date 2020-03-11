#ifndef  FUNCTIONS_C
#define  FUNCTIONS_C

#include "stuctures.h"
#include "functions.h"


ImageRGB * createImage(int width, int height){
    ImageRGB *new_image = (ImageRGB*) malloc(sizeof(ImageRGB));
    new_image->width = h;
    new_image->height = l;
    new_image->raw_data = (PixelRGB*)malloc(l*h*sizeof(PixelRGB));
    return new_image;
}

void modifyPixelToWB(ImageRGB * image, int witdh, int height, PixelRGB pixel){
	double GRIS;
	GRIS = 0.2125*(image->rawdata[width*image->width + height]->red)+0.7154*(image->rawdata[width*image->width + height]->green)+0.0721*(image->rawdata[width*image->width + height]->blue);
	pixel->blue = GRIS;
	pixel->green= GRIS;
	pixel->red  = GRIS;
	image->rawdata[width*image->width + height]= pixel;
}
	
	

ImageRGB * color_to_WB(ImageRGB * image){
	int i=0;
	int j=0;
	PixelRGB pixel =(pixel)malloc(sizeof(pixel));
    for(i; i<= image->width; i++){
	for(j; j<= image->height; j++){
	 modifyPixeltoWB(image,i,j,pixel);
	 }
	}
	return image;
}


void  freeImage(ImageRGB * image)
{
    free(image->raw_data);
    free(image);
}