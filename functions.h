##ifndef FUNCTIONS_H
#define  FUNCTIONS_H

#include "stuctures.h"


ImageBW * createImage(int width, int height); /*création d'image noir et blanc*/
void freeImage(ImageBW * image); /*libération mémoire image noir et blanc*/
ImageBW * color_to_WB(ImageRGB * image);/*conversion image couleur vers noir et blanc*/
PixelBW getPixel(ImageBW * image, int width, int height);/*recupération d'un pixel noir et blanc avec ses coordonnées*/
void modifyPixel(ImageBW * image, int witdh, int height, PixelBW pixel); /*modification d'un pixel noir et blanc / si image couleur PixelRGB*/
Image[] imagesInter(ImageBW * image1, ImageBW * image2, int nombre_image); /*Renvoi un tableau d'image intermédiaire à partir de deux images et du nombre voulu*/
int calculateWeight (int nbImage, int numeroImage); /*calcul du poids de l'image*/

//Fonction conversion
/*Fonction read/write -> attente de validation des structures avant modification des fonctions vu en cours*/

#endif
