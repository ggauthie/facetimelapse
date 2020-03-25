#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include "functions.h"
#include "structures.h"

int test_same_image(Image* image1, Image* image2);
int test_create_image(Image* image); //La fonction retourne 0 si l'image est créée sinon -1
void print_values_RGB(Pixel* pixel); //La fonction affiche les valeurs RGB du pixel pixel
void print_values_Image(Image * image); //La fonction affiche les valeurs RGB des pixels de l'image

#endif // TEST_H_INCLUDED
