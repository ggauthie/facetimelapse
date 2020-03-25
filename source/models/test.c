#include <stdio.h>
#include <stdlib.h>

#include "fichier.h"
#include "image.h"
#include "BMPFile.h"

#define MY_FILENAME_MAX 16

int test_create_image(Image* image){
    if(image == NULL){
        return -1;
    }else{
        return 0;
    }
}


void print_values_RGB(Pixel* pixel){
    printf( "VALEURS R: %u /G: %u /B %u \n", pixel->red, pixel->green, pixel->blue);
} 

void print_values_Image(Image * image){
    int i=0;
    int nb_total_pixel = (image->width)*(image->height);
    if(image != NULL){
    for(i; i<nb_total_pixel; i++){
        print_values_RGB(image->ptrPixel[i]);
    }
    }
}