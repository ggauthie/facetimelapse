#include "fichier.h"
#include <stdlib.h>


FILE* ouvrirFichier(char* nom, char* mode, TypeRetour t)
{
    FILE* fic = fopen(nom, mode);

    if(fic == NULL)
    {
        if(t == ARRET)
            exit(1);
        return NULL;
    }

    return fic;
}

int fermerFichier(FILE* f)
{
    if(f == NULL)
        return 1;

    return fclose(f);
}
