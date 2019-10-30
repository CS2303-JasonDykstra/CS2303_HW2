/*
 * production.c
 *
 *  Created on: Sep 8, 2019
 *      Author: jasondykstra
 */


#include "production.h"
#include "board.h"

bool production(int argc, char* argv[]){
	bool answer = false;
	int markerCounter = 1;
	int* theArray_p = make2DArray(ROWS, COLS);
	srand(time(NULL));

	struct coordinate marker = createMarker();
	//set the marker location in the 2D array to 1 initially
	theArray_p[marker.y*COLS + marker.x] = markerCounter;

	//append the starting position of the marker to the list
	struct LLNode* head = NULL;
	//create temp struct in order to center grid around (0,0)
	struct coordinate tempMarker = {marker.x - ROWS/2, -marker.y + COLS/2};
	append(&head, tempMarker);

	//move the marker in random directions a certain number of times
	for(int i = 0; i < MARKER_MOVES; i++){
		markerCounter++;
		markerCounter %= 10;
		enum move nextMove = moveMarker();
		switch(nextMove){
		case Up:
			marker.y -= 1;
			break;
		case Down:
			marker.y += 1;
			break;
		case Left:
			marker.x -= 1;
			break;
		case Right:
			marker.x += 1;
			break;
		default:
			printf("Invalid move in production.c");
		}

		//make sure the marker didnt go out of bounds
		if(marker.x < 0){
			marker.x = COLS - 1;
		}
		if(marker.x > COLS - 1){
			marker.x = 0;
		}
		if(marker.y < 0){
			marker.y = ROWS - 1;
		}
		if(marker.y > ROWS - 1){
			marker.y = 0;
		}


		//create temp coord to add to coordinate list
		struct coordinate temp = {marker.x - ROWS/2, -marker.y + COLS/2};
		append(&head, temp);
		theArray_p[marker.y*COLS + marker.x] = markerCounter;
	}

	display2DArray(theArray_p);

	printList(head);

	return answer;
}
