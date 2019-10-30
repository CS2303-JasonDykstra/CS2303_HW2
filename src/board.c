/*
 * board.c
 *
 *  Created on: Sep 8, 2019
 *      Author: jasondykstra
 */

#include "board.h"

int rows = 0;
int cols = 0;


int* make2DArray(int r, int c){
	rows = r;
	cols = c;

	int* theArray_p = (int*) calloc(r*c, sizeof(int));

	return theArray_p;
}

struct coordinate createMarker(){
	int randomRow = rand()%rows;
	int randomCol = rand()%cols;
	struct coordinate c = {randomRow, randomCol};
	return c;
}


void display2DArray(int* theArray_p){
	//display array
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			printf("%d ", theArray_p[i*cols + j]);
		}
		printf("\n");
	}
}


void append(struct LLNode** head_ref, struct coordinate c){
	//allocate node
	struct LLNode* new_node = (struct LLNode*)malloc(sizeof(struct LLNode));

	struct LLNode* last = *head_ref; //used to determine if the list is empty

	//put in the data
	new_node->coord = c;

	//This new node is going to be the last node, so make next of it as NULL
	new_node->next = NULL;

	//If the Linked List is empty, make new node as head
	if (*head_ref == NULL) {
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}

	//Else traverse till the last node
	while (last->next != NULL)
		last = last->next;

	//Change the next of last node
	last->next = new_node;

	//Make last node as previous of new node
	new_node->prev = last;

	return;
}

void printList(struct LLNode* node){
	struct LLNode* last;
	printf("\nPath taken by marker (center is at (0,0)): \n");
	while (node != NULL)
	{
		printf("(%d, %d) \n", node->coord.x, node->coord.y);
		last = node;
		node = node->next;
	}
}

enum move moveMarker(){
	enum move nextMove;
	//srand(time(NULL));
	int randMove = rand()%NUM_MOVES;

	switch(randMove){
	case 0:
		nextMove = Up;
		break;
	case 1:
		nextMove = Down;
		break;
	case 2:
		nextMove = Left;
		break;
	case 3:
		nextMove = Right;
		break;
	default:
		printf("moveMaker generated a random number outside of possible move range\n");
	}
	return nextMove;
}
