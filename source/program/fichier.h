#ifndef FICHIER_H
#define FICHIER_H

#include <stdio.h>
#include <stdlib.h>


#define MAX_NOM 255
#define NBIDMAX 2048


typedef enum {ARRET, RETOUR} TypeRetour;

FILE* ouvrirFichier(char* nom, char* mode, TypeRetour t);
int fermerFichier(FILE* f);

#endif // FICHIER_H
