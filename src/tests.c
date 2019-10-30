/*
 * tests.c
 *
 *  Created on: Sep 8, 2019
 *      Author: jasondykstra
 */


#include "tests.h"
#include "board.h"
#include "production.h"

bool tests(){
	srand(time(0));
	bool answer = true;
	bool ok1 = testMake2DArray();
	bool ok2 = testCreateMarker();
	bool ok3 = testDisplay2DArray();
	answer = ok1 && ok2 && ok3;
	return answer;
}

bool testMake2DArray(){
	bool ok = true;
	int* testArray = make2DArray(TEST_ROWS, TEST_COLS);
	if(testArray == NULL){
		puts("Malloc failed while initiating array\n");
		ok = false;
	}
	return ok;
}

bool testCreateMarker(){
	bool ok = true;
	struct coordinate c = createMarker();
	if(!(c.x >= 0 && c.x <= ROWS-1 && c.y >= 0 && c.y <= COLS-1)){
		puts("Coordinate marker out of range of the board dimensions\n");
		ok = false;
	}
	return ok;
}

bool testDisplay2DArray(){
	bool ok = true;
	char response;
	int* testArray = make2DArray(TEST_ROWS, TEST_COLS);
	display2DArray(testArray);
	printf("Does this look like a properly formatted %d by %d array, filled with 0's? (y/n)\n", TEST_ROWS, TEST_COLS);
	response = getchar();
	if(response == 'n'){
		ok = false;
	}

	return ok;
}

