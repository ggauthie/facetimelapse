#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "functions.h"

int test_create_image(Image* image){
    if(image == NULL){
        return -1;
    }else{
        return 0;
    }
}

int test_same_image(Image* image1, Image* image2){
    if(image1!=NULL && image2!=NULL){
        if((image1->width==image2->width) && (image1->height==image2->height)){
            return 0;
        }else{
            return -1;
        }
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
