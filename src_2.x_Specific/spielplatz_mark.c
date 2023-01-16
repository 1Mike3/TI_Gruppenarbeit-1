#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 10
#define NUM_ELEMENTS 30000
#define NUM_SEARCH_VALUES 500


struct myStruct {
    int value;
    char string[MAX_STRING_LENGTH];
};

//seed the random number generator
void seedRandom() {
    srand(time(NULL));
}

//create the array of structs
struct myStruct *createArray(int numElements) {
    struct myStruct *array = malloc(numElements * sizeof(struct myStruct));
    return array;
}

//fill the array with random values
void fillArray(struct myStruct *array, int numElements) {
    for (int i = 0; i < numElements; i++) {
        array[i].value = rand();
        for (int j = 0; j < MAX_STRING_LENGTH; j++) {
            array[i].string[j] = (char) (rand() % 26 + 65);
        }
    }
}

//create the array of search values
int *createSearchValues(int numSearchValues) {
    int *searchValues = malloc(numSearchValues * sizeof(int));
    return searchValues;
}

//Code for Benchmark goes here