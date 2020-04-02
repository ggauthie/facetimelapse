#include <stdio.h>
#include <stdlib.h>
#include <cmocka.h>

#include "structures.h"
#include "functions.h"

static void test_createImage(void **state){
	Image *image = (Image*) malloc(sizeof(Image));
	image=createImage(10,20);
   	assert_int_equal (image->width,10);
	assert_int_equal (image->height,20);
    
}

static void test_create_pixel(void **state){
	Pixel* pixel =(Pixel*)malloc(sizeof(Pixel));
	pixel = create_pixel(128,255,75);
   	assert_int_equal (pixel->red,128);
	assert_int_equal (pixel->green,256);
	assert_int_equal (pixel->blue,75);
    
}

/*test imageInter*/
/*test colortoWB */

static void test_modifyPixel_to_WB(void **state){
	Pixel* pixel =(Pixel*)malloc(sizeof(Pixel));
	pixel = modifyPixel(create_pixel(128,256,75));
	
	assert_int_equal (pixel->blue,215);
	assert_int_equal (pixel->green,215);
	assert_int_equal (pixel->red,215);
	
}

static void test_setPixel(void **state){

	Pixel* pixel =(Pixel*)malloc(sizeof(Pixel));
	image* image =(Image*)malloc(sizeof(Pixel));

	pixel=create_pixel(128,255,75);
	image=create_image(10,20);

	setPixel(image,5, 10, pixel);
	
	assert_int_equal (image->ptrPixel[5*10+10]->blue,pixel->blue);
	assert_int_equal (image->ptrPixel[5*10+10]->green,pixel->green);
	assert_int_equal (image->ptrPixel[5*10+10]-red,pixel->red);
	
	assert_int_equal (setPixel(image,50, 12, pixel),-1);
	
	
}

static void test_freeImage(void **state){
	Image *image = (Image*) malloc(sizeof(Image));
	image=createImage(10,20);
	
	freeImage(image);
	assert_null (image); //vérifie si le pointeur image est NULL
}


static void test_calculateWeight(void **state){
	void assert_float_equal	(calculateWeight (10, 1),0.09, 0.001);
	
	
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_createImage),
    	cmocka_unit_test(test_create_pixel),
    	cmocka_unit_test(test_modifyPixel_to_WB),
	    cmocka_unit_test(test_setPixel),
	    cmocka_unit_test(test_freeImage)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}