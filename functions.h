##ifndef FUNCTIONS_H
#define  FUNCTIONS_H

#include "stuctures.h"


ImageRGB * createImage(int width, int height); /*création d'image noir et blanc/RGB*/
void freeImage(ImageRGB * image); /*libération mémoire image noir et blanc*/
ImageRGB * color_to_WB(ImageRGB * image);/*conversion image couleur vers noir et blanc*/
PixelRGB getPixel(ImageRGB * image, int width, int height);/*recupération d'un pixel noir et blanc avec ses coordonnées*/
void modifyPixel(ImageRGB * image, int witdh, int height, PixelRGB pixel); /*modification d'un pixel noir et blanc / si image couleur PixelRGB*/
Image[] imagesInter(ImageBW * image1, ImageRGB * image2, int nombre_image); /*Renvoi un tableau d'image intermédiaire à partir de deux images et du nombre voulu*/
int calculateWeight (int nbImage, int numeroImage); /*calcul du poids de l'image*/

//Fonction conversion
Image* readBMPFile(char* filename, int verbose);
void writeBMPFile(char* filename, Image* im, int verbose);

#endif
