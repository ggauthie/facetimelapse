//
//  structures.h
//  
//
//  Created by Gwenael Jestin on 29/02/2020.
//

#ifndef structures_h
#define structures_h

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;             /* Pixel in Red Green Blue */
                        /* Could be modified to another type of color space */


typedef struct {
    int width;          /* Nb of columns */
    int height;         /* Nb of rows */
    Pixel * ptrPixel;               /* Pixels of the image */
} Image;



#endif /* structures_h */
