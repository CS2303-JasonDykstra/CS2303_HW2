/*
 ============================================================================
 Name        : HW2.c
 Author      : Jason Dykstra
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "production.h"

int main(int argc, char* argv[]) {
	if(tests()){
		production(argc, argv);
	} else {
		puts("tests did not pass.");
	}

	return EXIT_SUCCESS;
}
