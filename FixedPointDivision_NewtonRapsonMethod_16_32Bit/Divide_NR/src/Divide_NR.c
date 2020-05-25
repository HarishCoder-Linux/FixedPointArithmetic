/*
 ============================================================================
 Name        : Divide_NR.c
 Author      : Harish
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "Divide.h"
#include "div_l.h"
#include "div_s.h"
#include "norm_l.h"
#include "test_div_l.h"
#include "test_div_s.h"


int main(void) {
	float32_t max_diff_16 = 0.0;
	float32_t max_diff_32 = 0.0;

	//test_div_s(&max_diff_16);

	//printf("max_diff = %f\n", max_diff_16);

	test_div_s(&max_diff_32);

	printf("max_diff_32 = %f\n", max_diff_32);

	printf("the program ended successfully\n");

	int a = 5, b=15, result = 0;
	 int test = -(a < b);
	 printf("a^b = %d\n",test);
	result = b ^ ((a ^ b) & -(a < b));

	printf("min result = %d\n",result);
	result = a ^ ((a ^ b) & -(a < b));
	printf("max result = %d\n",result);

	int x = -15;
	x= x<<3;
	printf("x = %d\n",x);
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
