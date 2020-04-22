#ifndef FUNCTIONS_H
#define  FUNCTIONS_H

#include "structures.h"
#include <stdio.h>
#include <stdlib.h>

/*création d'image noir et blanc avec une largeur et une hauteur*/
/*return: pointeur sur l'image créee*/
Image * createImage(int width, int height);

/*libération mémoire image noir et blanc*/
void freeImage(Image * image);

/*conversion image couleur vers noir et blanc avec un pointeur vers une image donnée en paramètre*/
/*return: pointeur vers une nouvelle image*/
void color_to_WB(Image * image);

/*recupération d'un pixel noir et blanc avec ses coordonnées (x,y)*/
/*return: la valeur du pixel*/
Pixel * getPixel(Image * image, int width, int height);

/*remplace le pixel aux coordonnées (x,y) de l'image par une valeur de pixel donnée en paramètre*/
void setPixel(Image* image, int x, int y, Pixel pixel);

/*modification d'un pixel couleur vers noir et blanc*/
/*return: la valeur en noir et blanc du pixel*/
Pixel* modifyPixel_to_WB(Pixel pixel);

/*Création d'images intermédiaire à partir de deux images de référence (pointeurs donnés en paramètre) et du nombre voulu d'image*/
/*return: Renvoi un pointeur vers un tableau d'image*/
Image** imagesInter(Image * image1, Image * image2, int nombre_image);


//Fonction conversion
/*calcul du poids de l'image avec un nombre d'image et un numéro d'image donnés en paramètre*/
/*return:  le poids de l'image entre une image de début et une image de fin (on calculera le poids par rapport à l'image de départ, donc aura l'autre poids par rapport à l'image de fin en faisant 1-(le poids par rapport à la première image)*/
float calculateWeight (int nbImage, int numeroImage);

/*Fonction de lecture d'un fichier bmp*/
/*return: pointeur vers image*/
Image* readBMPFile(char* filename, int verbose);

/*Fonction d'écriture d'un fichier bmp*/
void writeBMPFile(char* filename, Image* im, int verbose);

#endif