/* Author: Scott Choi, ascottychoi@gmail.com
 * Functionality: Request integers to place in array that you will print to standard output
 */

#include <stdlib.h>
#include <stdio.h>

struct IntArray { // Defines IntArray struct
	int length;
	int *dataPtr;
};

struct IntArray* mallocIntArray(int length) { // allocates memory
	struct IntArray *init_ptr = malloc(64 * sizeof(length));
	init_ptr->length = length;
	init_ptr->dataPtr = malloc(length * sizeof(int));	
	return init_ptr;
};

void freeIntArray(struct IntArray *arrayPtr) { // frees memory
	free(arrayPtr->dataPtr);
	free(arrayPtr);
}

void readIntArray(struct IntArray *array) { // creates the array
	int inputInt;
	int i, j;
	char name[64];
	long ret = 0;
	for (i = 0; i < (array->length); i++) {
		ret = 0;
		while (ret <= 0) { // condition that stdin must be an int > 0
			printf("Enter int: ");
			fgets(name, 64, stdin);
			ret = strtol(name, NULL, 10);
			if (ret <= 0) { // invalid input let them know
				printf("Invalid input\n");
			}
			else { // add to array
				(array->dataPtr)[i] = ret;
			}	
		}
	}	
}

void swap(int *xp, int *yp) { // swaps two int input values
	int store = *xp;
	*xp = *yp;
	*yp = store;
}

void sortIntArray(struct IntArray *array) { // sort from least to greatest
	int i = 0;
	int min;
	int j = 0;
	for (i = 0; i < (array->length - 1); i++) { 
		min = i; // initalize min to start of array
		for (j = i+1; j < array->length; j++) {
			if (array->dataPtr[j] < array->dataPtr[min]) {
				min = j; // if array[j] < array[min], jth spot becomes new min
			}
		}
		swap(&(array->dataPtr[min]), &(array->dataPtr[i])); // swap first member of curr array with minimum value
	}
}

void printIntArray(struct IntArray *array) { // print array values
	int i = 0;
	printf("[");
	for (i = 0; i < array->length; i++) {
		printf(" %d", array->dataPtr[i]);
		if (i < (array->length) - 1) {
			printf(",");
		}
	}
	printf(" ]\n");	
}

int main() {
	char length[64];
	int i, j;
	long ret = 0;
	while(ret <= 0) { // request how long the array should be
		printf("Enter length: ");
		fgets(length, 64, stdin);
		ret = strtol(length, NULL, 10);
		if (ret <= 0) {
			printf("Invalid input\n");
		}
		else {
			printf("%d\n", ret);
		}
	}	
	struct IntArray *array = mallocIntArray(ret); // memory allocate
	readIntArray(array); // build the array
	sortIntArray(array); // sort the array
	printIntArray(array); // print the array
	freeIntArray(array); // free the memory
	return 0;
};
