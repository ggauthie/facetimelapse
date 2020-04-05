#include <stdio.h>
#include <stdlib.h>
#include <cmocka.h>

#include "structures.h"
#include "functions.h"


static int setup(void **state){
    int i=0;
    Image *image_1 = createImage(3,4);
    Image *image_2 = createImage(3,4);
    if(image_1 ==NULL || image_2==NULL || image_1->ptrPixel ==NULL || image_2->ptrPixel==NULL){
        return -1;
    }
    for(i;i<(image_1->width)*(image_1->height);i++){
        image_1->ptrPixel[i];
    }
    i=0;
    for(i;i<(image_2->width)*(image_2->height);i++){
        image_2->ptrPixel[i];
    }
    return 0;
}

static int teardown(void **state){
    freeImage(image_1);
    freeImage(image_2);
    return 0;
}

static void test_createImage(void **state){
   	assert_int_equal (image_1->width,3);
	assert_int_equal (image_1->height,4);
    
}


/*test imageInter*/

static void test_imageInter(void **state){
    int i=0,j=0;
    Image* tab_images = imagesInter(image_1, image_2, 3);
    
         for(i; i<(image_1->width)*(image_1->height);i++){
             
             assert_memory_equal(tab_images[0]->ptrPixel[i]->blue,63);
             assert_memory_equal(tab_images[0]->ptrPixel[i]->red,63);
             assert_memory_equal(tab_images[0]->ptrPixel[i]->green,63);
             
             assert_memory_equal(tab_images[1]->ptrPixel[i]->blue,127);
             assert_memory_equal(tab_images[1]->ptrPixel[i]->red,127);
             assert_memory_equal(tab_images[1]->ptrPixel[i]->green,127);
             
             assert_memory_equal(tab_images[2]->ptrPixel[i]->blue,191);
             assert_memory_equal(tab_images[2]->ptrPixel[i]->red,191);
             assert_memory_equal(tab_images[2]->ptrPixel[i]->green,191);
             
        }
        
}

/*test colortoWB */

static void test_colortoWB(void **state){
    //si test set pixel correct
	Pixel* pixel_1 ={255,0,0};
	int i,k;
    for(i=0; i<(image_1->width);i++){
		for(k=0; k<(image_1->height);k++){
			setPixel(image_1,i, k, pixel_1);}}
			
	assert_ptr_equal(color_to_WB(image2),image1);
}

static void test_modifyPixel_to_WB(void **state){
	Pixel* pixel_1 ={128,256,75};
	Pixel* pixel_2 =modifyPixel_to_WB(pixel_1);
	
	assert_int_equal (pixel_2->blue,215);
	assert_int_equal (pixel_2->green,215);
	assert_int_equal (pixel_2->red,215);
	
}

static void test_setPixel(void **state){
    
    Pixel* pixel_1 ={128,256,75};
    
	setPixel(image_1,2, 2, pixel_1);
	
	assert_int_equal (image_1->ptrPixel[2*image_1->width+2]->blue,pixel_1->blue);
	assert_int_equal (image_1->ptrPixel[2*image_1->width+2]->green,pixel_1->green);
	assert_int_equal (image_1->ptrPixel[2*image_1->width+2]->red,pixel_1->red);
	
	assert_int_equal (setPixel(image,2, 12, pixel),-1);
	
	
}

static void test_getPixel(void **state){
    Pixel *pixel = getPixel(image_1, 2, 1);
    assert_ptr_equal(pixel, image_1->ptrPixel[2*image_1->width + 1])
}


static void test_freeImage(void **state){
    
	freeImage(image_1);
	assert_null (image_1); //vérifie si le pointeur image est NULL
}


static void test_calculateWeight(void **state){
	assert_float_equal	(calculateWeight (10, 1),0.09, 0.001);
	
	
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test_setup_teardown(test_createImage, setup, teardown), 
    	cmocka_unit_test_setup_teardown(test_modifyPixel_to_WB, setup, teardown),
	    cmocka_unit_test_setup_teardown(test_setPixel,setup, teardown),
	    cmocka_unit_test_setup_teardown(test_getPixel,setup, teardown),
	    cmocka_unit_test_setup_teardown(test_freeImage,setup, teardown),
	    cmocka_unit_test_setup_teardown(test_colortoWB,setup, teardown),
	    cmocka_unit_test_setup_teardown(test_imagesInter,setup, teardown),
	    cmocka_unit_test_setup_teardown(test_calculateWeignt,setup, teardown)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}