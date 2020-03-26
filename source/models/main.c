#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "structures.h"
#include "test.h"

#define IMAGE_WIDTH  3
#define IMAGE_HEIGHT  3


int main()
{
    Image* image_1 = createImage(IMAGE_WIDTH, IMAGE_HEIGHT);
    Image* image_2 = createImage(IMAGE_WIDTH, IMAGE_HEIGHT);
    Pixel* pixel_1 =(Pixel*)malloc(sizeof(Pixel));
    Pixel* pixel_2 =(Pixel*)malloc(sizeof(Pixel));

    pixel_1->blue=50;
    pixel_1->green=200;
    pixel_1->red=235;

    pixel_2->blue=50;
    pixel_2->green=125;
    pixel_2->red=23;

    int i=0;

    for(i; i<IMAGE_WIDTH; i++){
            int j=0;
            for(j;j<IMAGE_HEIGHT;j++){
        setPixel(image_1,i,j,pixel_1);
        setPixel(image_2,i,j,pixel_2);
            }
    }

    print_values_Image(image_1);
    print_values_Image(image_2);
    return 0;
}
