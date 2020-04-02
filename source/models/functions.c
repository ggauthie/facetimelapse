#include "structures.h"
#include "functions.h"
#include <math.h>


Image * createImage(int width, int height){
    Image *new_image = (Image*) malloc(sizeof(Image));
    new_image->width = width;
    new_image->height = height;
    new_image->ptrPixel = (Pixel*)malloc(width*height*sizeof(Pixel));
    return new_image;
}

Pixel * create_pixel(int red, int green, int blue){

	Pixel* pixel =(Pixel*)malloc(sizeof(Pixel));
	pixel->red =red;
	pixel->blue =blue;
	pixel->green=green;

	return pixel;

}

}
Pixel* modifyPixel_to_WB(Pixel* pixel){
	int GRIS;
	GRIS = (unsigned char)floor(0.2125*(pixel->red)+0.7154*(pixel->green)+0.0721*(pixel->blue));
	pixel->blue = GRIS;
	pixel->green= GRIS;
 	pixel->red  = GRIS;
 	return pixel;
}

void setPixel(Image* image, int x, int y, Pixel* pixel){
    if((x>=image->width) || (y>=image->height || (image == NULL)){
        printf("Error : en dehors de l'image ou image null");
        return -1;
    }else{
	image->ptrPixel[x*image->width +y].blue=pixel->blue;
	image->ptrPixel[x*image->width +y].red=pixel->red;
	image->ptrPixel[x*image->width +y].green=pixel->green;
}
}

Image * color_to_WB(Image * image){
	int i=0;
	int j=0;
	Image *imageWB = createImage(image->width, image->height);
	Pixel* pixel =(Pixel*)malloc(sizeof(Pixel));
    for(i; i<= image->width; i++){
	for(j; j<= image->height; j++){
	 pixel = modifypixel_to_WB(image->ptrPixel[i*(image->width)+j]);
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
    int i=1;
    int j=0;
    int k=0;
	float a,b,c,d,e,f;

    Image* tab_images = (Image*)malloc(nombre_image*sizeof(Image));
    for(i;i<=nombre_image;i++){
        for(j; j<image1->width; j++){
        for(k; k<image1->height;k++){

            Pixel *pixel =(Pixel*)malloc(sizeof(Pixel));

            a=calculateWeight(nombre_image,i)*image1->ptrPixel[j*(image1->width)+k].blue;
		    b=calculateWeight(nombre_image,i)*image1->ptrPixel[j*(image1->width)+k].green;
		    c=calculateWeight(nombre_image,i)*image1->ptrPixel[j*(image1->width)+k].red;
		    d=(1-calculateWeight(nombre_image,i))*image2->ptrPixel[j*(image1->width)+k].blue;
		    e=(1-calculateWeight(nombre_image,i))*image2->ptrPixel[j*(image1->width)+k].green;
		    f=(1-calculateWeight(nombre_image,i))*image2->ptrPixel[j*(image1->width)+k].red;
		    pixel->blue=(unsigned char)floor((a+d)/2);
		    pixel->green=(unsigned char)floor((b+e)/2);
		    pixel->red=(unsigned char)floor((c+f)/2);
		    setPixel(tab_images, j, k, pixel);
		    tab_images++;
    }
}
}
	return tab_images;
}

/*Renvoi un tableau d'image intermédiaire à partir de deux images et du nombre voulu*/
float calculateWeight (int nbImage, int numeroImage){
    return (numeroImage/nbImage+1); //nbImage commence à 1
}


Image* readBMPFile(char* filename, int verbose);
void writeBMPFile(char* filename, Image* im, int verbose);
