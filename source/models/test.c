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

    *state = image_1;
    return 0;
}

/*static int setup_1(void **state){
    
    Image *image_2 = createImage(3,3);
    Image *image_3 = createImage(3,3);

    Pixel pixel_1 ={0,0,0};
    Pixel pixel_2={255,255,255};
    
    int i,j;

    for(i=0; i< 3; i++){
	     for(j=0; j< 3; j++){
		setPixel(image_2,i,j,pixel_1);
		setPixel(image_3,i,j,pixel_2);
	      }
}
Image *tab[]={image_2,image_3};
*state =tab;
return 0;

}*/

static int teardown(void **state){
    free(((Image*)*state)->ptrPixel);
    free(*state);
    return 0;
}

/*static int teardown_1(void **state){
    free(((Image*)*state)->ptrPixel);
    free(*state);
    return 0;
}*/

/* test creatImage*/

static void test_createImage(void **state){
	Image *image_1 = createImage(3,4);
	assert_int_equal (image_1->width,3);
	assert_int_equal (image_1->height,4);

}


/*test imageInter*/

static void test_imageInter(void **state){

    Image *image_2 = createImage(3,3);
    Image *image_3 = createImage(3,3);

    Pixel pixel_1 ={0,0,0};
    Pixel pixel_2={255,255,255};
    
    int i,j;

    for(i=0; i< 3; i++){
         for(j=0; j< 3; j++){
        setPixel(image_2,i,j,pixel_1);
        setPixel(image_3,i,j,pixel_2);
          }
      }
    Image** tab_images = imagesInter(image_2, image_3, 3);

    for(i=0; i<(image_2->width)*(image_2->height);i++){
     
     assert_int_equal((tab_images[0])->ptrPixel[i].blue,63);
     assert_int_equal((tab_images[0])->ptrPixel[i].red,63);
     assert_int_equal((tab_images[0])->ptrPixel[i].green,63);

     assert_int_equal((tab_images[1])->ptrPixel[i].blue,127);
     assert_int_equal((tab_images[1])->ptrPixel[i].red,127);
     assert_int_equal((tab_images[1])->ptrPixel[i].green,127);

     assert_int_equal((tab_images[2])->ptrPixel[i].blue,191);
     assert_int_equal((tab_images[2])->ptrPixel[i].red,191);
     assert_int_equal((tab_images[2])->ptrPixel[i].green,191);

 }

}

/*test colortoWB */

static void test_colortoWB(void **state){
	Image* image_1 =(Image*)(*state);	
	Pixel pixel_1 ={255,120,120}; 
	int i,k;

    for(i=0; i<(image_1->width);i++){
      for(k=0; k<(image_1->height);k++){
       setPixel(image_1,i, k, pixel_1);}}
       color_to_WB(image_1);
       for(i=0; i<(image_1->width);i++){
          for(k=0; k<(image_1->height);k++){
           assert_int_equal(image_1->ptrPixel[k*(image_1->width)+i].red,148);
           assert_int_equal(image_1->ptrPixel[k*(image_1->width)+i].green,148);
           assert_int_equal(image_1->ptrPixel[k*(image_1->width)+i].blue,148);

       }
   }
}


/*test setPixel */

static void test_setPixel(void **state){
 Image* image_1 =(Image*)(*state);
 Pixel pixel_1 ={100,255,100};

 setPixel(image_1,2, 2, pixel_1);

 assert_int_equal(image_1->ptrPixel[2*image_1->width+2].blue,pixel_1.blue);
 assert_int_equal(image_1->ptrPixel[2*image_1->width+2].green,pixel_1.green);
 assert_int_equal(image_1->ptrPixel[2*image_1->width+2].red,pixel_1.red);


}

/* test getPixel*/

static void test_getPixel(void **state){
    Image* image_1 =(Image*)(*state);
    Pixel *pixel = getPixel(image_1, 2, 1);
    assert_ptr_equal(pixel, &image_1->ptrPixel[2*image_1->width + 1]);
}

/*test calculateWeight*/

static void test_calculateWeight(void **state){
	assert_int_equal(calculateWeight(9, 2)*10,0.2*10);

}

static void test_freeImage(void **state){
    Image* image_1 =(Image*)(*state);

    freeImage(image_1);

    assert_int_equal(image_1->width, 0);
    assert_int_equal(image_1->height, 0);
    assert_ptr_equal(image_1->ptrPixel,NULL);

}



int main(void) {
    const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_createImage),
      cmocka_unit_test_setup_teardown(test_setPixel,setup, teardown),
      cmocka_unit_test_setup_teardown(test_getPixel,setup, teardown),
      cmocka_unit_test_setup_teardown(test_colortoWB,setup, teardown),
      cmocka_unit_test_setup_teardown(test_calculateWeight,setup, teardown),
      cmocka_unit_test(test_imageInter),
      cmocka_unit_test_setup_teardown(test_freeImage, setup, teardown)
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
