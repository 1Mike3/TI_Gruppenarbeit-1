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

clock_t start, end;

// Measure the time taken for function1
start = clock();
function1(searchArray1, size);
end = clock();
double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Time taken by function1: %f\n", time_taken);

// Measure the time taken for function2
start = clock();
function2(searchArray2, size);
end = clock();
time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Time taken by function2: %f\n", time_taken);

return 0;
}
