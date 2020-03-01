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
} PixelRGB;             /* Pixel in Red Green Blue */
                        /* Could be modified to another type of color space */

typedef struct {
    unsigned char value;
} PixelBW;              /* Pixel in Black & White */

typedef struct {
    int width;          /* Nb of columns */
    int height;         /* Nb of rows */
    PixelRGB * ptrPixel;               /* Pixels of the image */
} ImageRGB;

typedef struct {
    int width;          /* Nb of columns */
    int height;         /* Nb of rows */
    PixelBW* ptrPixel;               /* Pixels of the image */
} ImageBW;



#endif /* stuctures_h */
