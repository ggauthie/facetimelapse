#include <stdio.h>
#include <stdlib.h>


#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <assert.h>
#include <cmocka.h>

#include "structures.h"
#include "functions.h"


static int setup(void **state){

    Image *image_1 = createImage(3,4);
    Image *image_2 = createImage(3,4);
    if(image_1 ==NULL || image_2==NULL || image_1->ptrPixel ==NULL || image_2->ptrPixel==NULL){
        return -1;
    }
    for(int i=0;i<(image_1->width)*(image_1->height);i++){
        image_1->ptrPixel[i];// a aucun effet sur l'image
    }

    for(int i=0;i<(image_2->width)*(image_2->height);i++){
        image_2->ptrPixel[i];// a aucun effet sur l'image
    }
    return 0;
}

static int teardown(void **state){
    Image *image_1 = createImage(3,4); //modif
    Image *image_2 = createImage(3,4); //modif
    freeImage(image_1);
    freeImage(image_2);
    return 0;
}

static void test_createImage(void **state){
  Image *image_1 = createImage(3,4); //modif
  //Image *image_2 = createImage(3,4); //modif
	assert_int_equal (image_1->width,3);
	assert_int_equal (image_1->height,4);

}


/*test imageInter*/

static void test_imageInter(void **state){
    int i=0,j=0;
    Image *image_1 = createImage(3,4); //modif
    Image *image_2 = createImage(3,4); //modif
    Image* tab_images = imagesInter(image_1, image_2, 3);

         for(i; i<(image_1->width)*(image_1->height);i++){

             assert_memory_equal((tab_images[0]).ptrPixel[i].blue,63,1);
             assert_memory_equal((tab_images[0]).ptrPixel[i].red,63,1);
             assert_memory_equal((tab_images[0]).ptrPixel[i].green,63,1);

             assert_memory_equal((tab_images[1]).ptrPixel[i].blue,127,1);
             assert_memory_equal((tab_images[1]).ptrPixel[i].red,127,1);
             assert_memory_equal((tab_images[1]).ptrPixel[i].green,127,1);

             assert_memory_equal((tab_images[2]).ptrPixel[i].blue,191,1);
             assert_memory_equal((tab_images[2]).ptrPixel[i].red,191,1);
             assert_memory_equal((tab_images[2]).ptrPixel[i].green,191,1);

        }

}

/*test colortoWB */

static void test_colortoWB(void **state){
    //si test set pixel correct
    Image *image_1 = createImage(3,4); //modif
    Image *image_2 = createImage(3,4); //modif
	Pixel pixel_1 ={255,0,0}; //modif
	int i,k;
    for(i=0; i<(image_1->width);i++){
		for(k=0; k<(image_1->height);k++){
			setPixel(image_1,i, k, pixel_1);}}

	assert_ptr_equal(color_to_WB(image_2),image_1); //mùodif
}

static void test_modifyPixel_to_WB(void **state){
/*
  Image *image_1 = createImage(3,4);
  image_1->ptrPixel->blue = 128;
  image_1->ptrPixel->green = 255;
  image_1->ptrPixel->red = 75;*/

  Pixel pixel_1 = {128,255,75};
	Pixel * pixel_2 = modifyPixel_to_WB(pixel_1);

	assert_int_equal(pixel_2->blue,215);
	assert_int_equal(pixel_2->green,215);
  assert_int_equal(pixel_2->red,215);

}

static void test_setPixel(void **state){
  Image *image_1 = createImage(3,4); //modif
  //Image *image_2 = createImage(3,4); //modif
    Pixel pixel_1 ={128,255,75};// c'était écrit 256 au lieu de 255

	setPixel(image_1,2, 2, pixel_1);

	assert_int_equal (image_1->ptrPixel[2*image_1->width+2].blue,pixel_1.blue);
	assert_int_equal (image_1->ptrPixel[2*image_1->width+2].green,pixel_1.green);
	assert_int_equal (image_1->ptrPixel[2*image_1->width+2].red,pixel_1.red);
// pas compris la ligne en dessous
	//assert_int_equal (setPixel(image_1, 2, 2, pixel_1),-1);// image_1 ou image_2 // pixel ?? pixel_1 ??


}

static void test_getPixel(void **state){
  Image *image_1 = createImage(3,4); //modif
  //Image *image_2 = createImage(3,4); //modif
    Pixel *pixel = getPixel(image_1, 2, 1);
    assert_ptr_equal(pixel, &image_1->ptrPixel[2*image_1->width + 1]);//modif
}


static void test_freeImage(void **state){
  Image *image_1 = createImage(3,4); //modif
//  Image *image_2 = createImage(3,4); //modif
	freeImage(image_1);

	assert_null(image_1); //vérifie si le pointeur image est NULL
}

 j'arrive pas à récupérer assert_float_equal
/*static void test_calculateWeight(void **state){
	assert_float_equal(calculateWeight (10, 1),0.09, 0.001);

}*/

int main(void) {
    const struct CMUnitTest tests[] = {
      cmocka_unit_test_setup_teardown(test_createImage, setup, teardown),
    	cmocka_unit_test_setup_teardown(test_modifyPixel_to_WB, setup, teardown),
	    cmocka_unit_test_setup_teardown(test_setPixel,setup, teardown),
	    cmocka_unit_test_setup_teardown(test_getPixel,setup, teardown),
	    cmocka_unit_test_setup_teardown(test_freeImage,setup, teardown),
	    cmocka_unit_test_setup_teardown(test_colortoWB,setup, teardown),
	    cmocka_unit_test_setup_teardown(test_imageInter,setup, teardown),
	   // cmocka_unit_test_setup_teardown(test_calculateWeignt,setup, teardown)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}