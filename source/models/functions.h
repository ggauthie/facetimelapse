#ifndef FUNCTIONS_H
#define  FUNCTIONS_H

#include "structures.h"
#include <stdio.h>
#include <stdlib.h>


Image * createImage(int width, int height); /*création d'image noir et blanc/RGB*/

void freeImage(Image * image); /*libération mémoire image noir et blanc*/

Image * color_to_WB(Image * image);/*conversion image couleur vers noir et blanc*/

Pixel getPixel(Image * image, int width, int height);/*recupération d'un pixel noir et blanc avec ses coordonnées*/

void setPixel(Image* image, int x, int y, Pixel* pixel); /*remplace le pixel pixel aux coordonnées (x,y)de l'image image*/

Pixel* modifyPixel_to_WB(Pixel* pixel); /*modification d'un pixel noir et blanc*/

Image* imagesInter(Image * image1, Image * image2, int nombre_image); /*Renvoi un tableau d'image intermédiaire à partir de deux images et du nombre voulu*/

float calculateWeight (int nbImage, int numeroImage); /*calcul du poids de l'image*/

//Fonction conversion

Image* readBMPFile(char* filename, int verbose);
void writeBMPFile(char* filename, Image* im, int verbose);

#endif
