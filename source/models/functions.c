#include "stuctures.h"
#include "functions.h"


Image * createImage(int width, int height){
    Image *new_image = (Image*) malloc(sizeof(Image));
    new_image->width = h;
    new_image->height = l;
    new_image->ptrPixel = (Pixel*)malloc(l*h*sizeof(Pixel));
    return new_image;
}

Pixel * modifyPixel_to_WB(Pixel* pixel){
	unsigned char GRIS;
	GRIS = 0.2125*(pixel->red)+0.7154*(pixel->green)+0.0721*(pixel->blue);
	pixel->blue = GRIS;
	pixel->green= GRIS;
 	pixel->red  = GRIS; 
 	return pixel;
}

	
void setPixel(Image* image, int x, int y, Pixel* pixel){
	image->rawdata[x*image->y + height] = pixel;
    
}

Image * color_to_WB(Image * image){
	int i=0;
	int j=0;
	unsigned char GRIS;
	Image imageWB = createimage(image->width, image->height);
	Pixel* pixel =(Pixel)malloc(sizeof(Pixel));
    for(i; i<= image->width; i++){
	for(j; j<= image->height; j++){
	 pixel = modifypixel_to_WB(image->rawdata[i*(image->width)+j]);   
	 setPixel(image,i,j,pixel);
	 }
	}
	return imageWB;
}


void  freeImage(Image * image)
{
    free(image->ptrPixel);
    free(image);
}

Image* imagesInter(Image * image1, Image * image2, int nombre_image){
    int i=0;
	float a,b,c,d,e,f;
    Image* tab_images = (Image*)malloc(nombre_image*sizeof(Image));
    for(i;i<nombre_image;i++){
        a=calculateWeight(nbImage,i)*tab_images[i]->ptrPixel->blue;
		b=calculateWeight(nbImage,i)*tab_images[i]->ptrPixel->green;
		c=calculateWeight(nbImage,i)*tab_images[i]->ptrPixel->red;
		d=(1-calculateWeight(nbImage,i))*tab_images[i]->ptrPixel->blue;
		e=(1-calculateWeight(nbImage,i))*tab_images[i]->ptrPixel->green;
		f=(1-calculateWeight(nbImage,i))*tab_images[i]->ptrPixel->red;
		tab_images[i]->ptrPixel->blue=(a+d)/2;
		tab_images[i]->ptrPixel->green=(b+e)/2;
		tab_images[i]->ptrPixel->red=(c+f)/2;
    }
	return tab_images;
}
    
} /*Renvoi un tableau d'image intermédiaire à partir de deux images et du nombre voulu*/
float calculateWeight (int nbImage, int numeroImage){
    return (numeroImage/nbImage+1); //nbImage commence à 1
}


Image* readBMPFile(char* filename, int verbose);
void writeBMPFile(char* filename, Image* im, int verbose);
