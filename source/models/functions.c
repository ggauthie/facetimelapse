#include "structures.h"
#include "functions.h"
#include <math.h>
#include <stdio.h>

Image * createImage(int width, int height){
    Image *new_image = (Image*) malloc(sizeof(Image));
    new_image->width = width;
    new_image->height = height;
    new_image->ptrPixel = (Pixel*)malloc(width*height*sizeof(Pixel));
    return new_image;
}

Pixel* getPixel(Image * image, int width, int height){
    return &(image->ptrPixel[width*image->width + height]);
}

void setPixel(Image* image, int x, int y, Pixel pixel){
    if((x>=image->width) || (y>=image->height) || (image == NULL)){
        printf("Error : en dehors de l'image ou image null");
      //  return -1; pas logique si c'est un void
    }else{
	image->ptrPixel[y*image->width +x].blue=pixel.blue;
	image->ptrPixel[y*image->width +x].red=pixel.red;
	image->ptrPixel[y*image->width +x].green=pixel.green;
}
}

void color_to_WB(Image * image){
	int i;
	int j;
	unsigned char gris;
  for(i=0; i< image->width; i++){
	     for(j=0; j< image->height; j++){
		gris = (unsigned char)floor(0.2125*(image->ptrPixel[j*image->width +i].red)+0.7154*(image->ptrPixel[j*image->width +i].green)+0.0721*(image->ptrPixel[j*image->width +i].blue));
	    	Pixel pixel ={gris,gris,gris};
		setPixel(image,i,j, pixel);
	      }
	}
}


void  freeImage(Image * image)
{
    free(image->ptrPixel);
    free(image);
}


Image* imagesInter(Image * image1, Image * image2, int nombre_image){

	float a,b,c,d,e,f;
        unsigned char red, blue, green;

    Image* tab_images = (Image*)malloc(nombre_image*sizeof(Image));
    for(int i=1;i<=nombre_image;i++){
        for(int j=0; j<image1->width; j++){
        for(int k=0; k<image1->height;k++){

       		    a=calculateWeight(nombre_image,i)*image1->ptrPixel[k*(image1->width)+j].blue;
		    b=calculateWeight(nombre_image,i)*image1->ptrPixel[k*(image1->width)+j].green;
		    c=calculateWeight(nombre_image,i)*image1->ptrPixel[k*(image1->width)+j].red;
		    d=(1-calculateWeight(nombre_image,i))*image2->ptrPixel[k*(image1->width)+j].blue;
		    e=(1-calculateWeight(nombre_image,i))*image2->ptrPixel[k*(image1->width)+j].green;
		    f=(1-calculateWeight(nombre_image,i))*image2->ptrPixel[k*(image1->width)+j].red;
		    blue=(unsigned char)floor((a+d)/2);
		    green=(unsigned char)floor((b+e)/2);
		    red=(unsigned char)floor((c+f)/2);
		    Pixel pixel = {red, blue, green};
		    setPixel(tab_images[i], j, k, pixel);
    }
}
}
	return tab_images;
}


/*Renvoi un tableau d'image intermédiaire à partir de deux images et du nombre voulu*/
float calculateWeight (int nbImage, int numeroImage){
    return (((float)numeroImage)/((float)(nbImage+1))); //nbImage commence à 1
}