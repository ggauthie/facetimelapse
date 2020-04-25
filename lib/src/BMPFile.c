/*!
 * \file fichier.c
 * \brief definition of functions to handle a BMP file using RGB colour space
 * \author ...
 * \date ...
 */

#include "BMPFile.h"

/*!
 * \fn void displayFileHeader(FileHeader* eFichier)
 *  displays the content of the FileHeader structure
 * \param[in] eFichier the FileHeader structure to print
 */

void displayFileHeader(FileHeader* eFichier){
   printf("Entete du fichier :\n");
   printf("identity : %c%c\n", eFichier -> identity[0],eFichier -> identity[1] );
   printf("taille du fichier : %u\n", eFichier->file_size);
   printf("Addresse data : %d\n", eFichier->raster_address);
   printf("\n");
}

/*!
 * \fn void displayDIBHeader(DIBHeader* eImage)
 *  displays the content of the DIBHeader structure
 * \param[in] eImage the DIBHeader structure to print
 */

void displayDIBHeader(DIBHeader* eImage){
    unsigned short int nb;

   printf("Entete de l'image :\n");
   printf("Taille : %d\n", eImage -> size_DIBHeader);
   printf("Dimensions : %d, %d\n", eImage -> image_width, eImage -> image_height);
   printf("Nb plan : %u\n", eImage -> nbColorPlanes);
   printf("Format (couleurs) (from nbBitperPixel): ");
   nb = eImage -> nbBitPerPixel;
   switch(nb){
               case 1:
                    printf("monochrome\n");
                    break;
               case 4:
                    printf("16 couleurs\n");
                    break;
               case 8:
                    printf("256 couleurs\n");
                    break;
               case 24:
                    printf("16 Millions couleurs\n");
                    break;
               default:
                    printf("Entete incorrecte : nbBitPerPixel %d ind�fini\n", nb);
                    break;
	}
   printf("Compression (doit etre nulle) : %d \n",  eImage -> typeCompression);
   printf("size_raw_image : %u\n", eImage -> size_raw_image);
   printf("hResolution, vResolution : %d, %d\n", eImage -> hResolution, eImage -> vResolution);
   printf("nbUsedColours, nbImportantColours : %u, %u\n", eImage -> nbUsedColours, eImage -> nbImportantColours);

  printf("\n");

}

void writeBMPFile(char* filename, Image* image, int verbose)
{
  /*
	const int FileHeaderSize = 14;
	const int DIBHeaderSize = 40;
	int size_im = im->width * im->height * sizeof(Pixel);
	FileHeader fh = {{'B', 'M'}, size_im + FileHeaderSize + DIBHeaderSize,\
					{0}, FileHeaderSize + DIBHeaderSize};
	DIBHeader dibh;
	dibh.size_DIBHeader = DIBHeaderSize;
	dibh.image_width = im->width; // modif�
	dibh.image_height = im->height; //modifi�
	dibh.nbColorPlanes = 1;
	dibh.nbBitPerPixel = sizeof(Pixel) * 8;
	dibh.typeCompression = 0;
	dibh.size_raw_image = size_im;
	dibh.hResolution = 2800;
	dibh.vResolution = 2800;
	dibh.nbUsedColours = 0;
	dibh.nbImportantColours = 0;

	//displayDIBHeader(&dibh);
	//displayFileHeader(&fh);

	FILE* f = fopen(filename, "wb+");
	if(f == NULL)
	{
		printf("error opening file");
		return;
	}



	fwrite(&fh, sizeof(FileHeader), 1, f);
	fwrite(&dibh, sizeof(DIBHeader), 1, f);

	for (int l = 0 ; l < im->height; l++)
	{
		for(int c =0 ; c < im->width ; c++)
		{
			//printf("%d %d %X \n", l, c,  (im->ptrPixel+(l * im->width +c) ));
			fwrite(im->ptrPixel+(l * im->width +c), sizeof(Pixel), 1, f);
		}
		for(unsigned int b = 0 ; b < im->width*sizeof(Pixel)%4 ; b++)
		{
			printf("print padding\n");
			fputc('\0', f);
		}
	}
	fclose(f);
  */

    int i;
    char buff[3] = {0,0,0};

    int padding = (image->width%4) ? 4 - (image->width*sizeof(Pixel))%4 : 0;

    const int headersize = 14;
    const int dibsize = 40;
    int imagesize = (image->width+padding)*image->height*sizeof(Pixel);

    FileHeader fileheader = {.identity={'B','M'}, .file_size=headersize+dibsize+imagesize, .application_id={0}, .raster_address=headersize+dibsize};

    DIBHeader dibheader = {.size_DIBHeader=dibsize, .image_width=image->width, .image_height=image->height, .nbColorPlanes=1, .nbBitPerPixel=24,
                           .typeCompression=0, .size_raw_image=imagesize, .hResolution=2800, .vResolution=2800, .nbUsedColours=0, .nbImportantColours=0
                          };

    FILE *f = fopen(filename, "w");

    fwrite(&fileheader,sizeof(FileHeader),1,f);
    fwrite(&dibheader,sizeof(DIBHeader),1,f);

    for(i=image->height; i>0; --i)
    {
        fwrite(&image->ptrPixel[i*image->width],sizeof(Pixel),image->width,f);
        fwrite(buff,sizeof(char),padding,f);
    }

    fclose(f);
}



Image* readBMPFile(char* filename, int verbose)
{
	FILE *f = fopen(filename, "rb");
	if (f== NULL)
	{
		printf("error opening file");
		return NULL;
	}

	FileHeader fh;
	DIBHeader dibh;
	readFileHeader(f, &fh);
	if(verbose)
		displayFileHeader(&fh);

	readDIBHeader(f, &dibh);
	if(verbose)
		displayDIBHeader(&dibh);
	Image* im = readRawImage(f,	fh.raster_address, dibh.image_height, dibh.image_width);

	fclose(f);
	return im;
}

void readFileHeader(FILE* f, FileHeader* fh)
{
	fread(&fh->identity, sizeof(fh->identity), 1, f);
	fread(&fh->file_size, sizeof(fh->file_size), 1, f);
	fread(&fh->application_id, sizeof(fh->application_id), 1, f);
	fread(&fh->raster_address, sizeof(fh->raster_address), 1, f);
}

void readDIBHeader(FILE* f, DIBHeader* dibh)
{
	fread(dibh, sizeof(DIBHeader), 1, f);
}

Image* readRawImage(FILE* f, unsigned int address, int h, int w)
{
	fseek(f, address, SEEK_SET);
	Image* im = createImage(w, h); // a �t� modifi�
	for (int i = h ; i >0 ; i--)
	{
		fread(im->ptrPixel+i*w, w*sizeof(Pixel), 1, f);
		fseek(f, w*sizeof(Pixel) % 4, SEEK_CUR);
	}

	return im;
}
