#include <stdio.h>

#include "stdlib.h"
#include "time.h"

#include "include/allfunclib.h"

//implementation in main.c function
unsigned int genRandNum();

//Test
#include "stdio.h"

void af ();
void ah ();


int main() {
    printf("Hello, World! - A\n");
    int arr[2] = {};
    unsigned  int size;

    mergeS(arr, size);

    ah();
    af();

    return 0;
}

//not finished: function which returns a random number on a selected range
unsigned int genRandNum(){
    time_t t;
    srand((unsigned) time(&t));
int rand();
}