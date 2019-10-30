/*
 * board.h
 *
 *  Created on: Sep 8, 2019
 *      Author: jasondykstra
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_MOVES 4


int* make2DArray(int rows, int cols);
void display2DArray(int* theArray_p);
struct coordinate createMarker();



struct coordinate{
	int x, y;
};

struct LLNode{
	struct coordinate coord;
	struct LLNode* prev;
	struct LLNode* next;
};


void append(struct LLNode** head_ref, struct coordinate c);
void printList(struct LLNode* node);

enum move{
	Up,
	Down,
	Left,
	Right
};

enum move moveMarker();

#endif /* BOARD_H_ */
