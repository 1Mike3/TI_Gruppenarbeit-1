#include <stdio.h>
#include "stdlib.h"
#include "time.h"

//implementation min merge.c file
void mergeS (int *arr, unsigned int size);
//implementation in main.c function
unsigned int genRandNum();

int main() {
    printf("Hello, World!\n");
    int arr[2] = {};
    unsigned  int size;

    mergeS(arr, size);

    return 0;
}

//not finished: function which returns a random number on a selected range
unsigned int genRandNum(){
    time_t t;
    srand((unsigned) time(&t));
int rand();
}