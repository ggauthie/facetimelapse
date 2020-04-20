#include <stdio.h>
#include <stdlib.h>
#include "BMPFile.h"

//#include "test.h"

#define IMAGE_WIDTH  3
#define IMAGE_HEIGHT  3


int main()
{   //Pixel pixel1={255,255,255};
    //Pixel pixel2={0,0,0};
    int nombre_image=4;

    Image * image1 = readBMPFile("tiger.bmp",1);
    Image * image2 = readBMPFile("tiger.bmp",1);
    color_to_WB(image2);
    /*for(int x=0;x<300;x++){
      for(int y=0;y<300;y++){
        setPixel(image1,x,y,pixel1);
        setPixel(image2,x,y,pixel2);
      }
    }*/
    writeBMPFile("image1",image1,1);
    //color_to_WB(image1);
    writeBMPFile("image2",image2,1);

    Image* imageintermediaire;
    char *nb_image[] = {"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","22","23","24","25"};

    imageintermediaire = (imagesInter(image1,image2,nombre_image));
    writeBMPFile(nb_image[0],(imageintermediaire),1);

    for(int i=1;i<nombre_image;++i){

      writeBMPFile(nb_image[i],(imageintermediaire+(2*i)),1);//pk 2i ?
      //printf("size de i : %ld\n", sizeof(i));
    }

//printf("size de image : %ld\n", sizeof(Image));
//printf("size de long :%ld\n", sizeof(long));
}