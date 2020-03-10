//
//  stuctures.h
//  
//
//  Created by Gwenael Jestin on 29/02/2020.
//

#ifndef stuctures_h
#define stuctures_h

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} Pixel;             /* Pixel in Red Green Blue */
                        /* Could be modified to another type of color space */


typedef struct {
    int width;          /* Nb of columns */
    int height;         /* Nb of rows */
    Pixel * ptrPixel;               /* Pixels of the image */
} Image;



#endif /* stuctures_h */
