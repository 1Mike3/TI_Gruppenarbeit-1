//
// Created by Michi on 11.12.2022.
//
#include <time.h>
#include "stdio.h"
#include "stdlib.h"
#include "..\include\allfunclib.h"

//function which implements the 1.2 assignment
void comparison1_3(){
    const int arraySize = 2000;
    const int cycleCount = 20;
    int *arr[arraySize] = {};
    genRandNum(arraySize, arr);
    bubbleS(arr, arraySize);
    //x20 times
    for(int i = 0; i < cycleCount; i++){
        bubbleS(arr, arraySize);
    }
    //track time x20 bubbleS
    clock_t start = clock();
    for(int i = 0; i < cycleCount; i++){
        bubbleS(arr, arraySize);
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    //avarage = time_spent / cycleCount
    printf("The average time for 20 cycles of bubbleS is: %f seconds \n", time_spent / cycleCount);
    //short = time_spent
    printf("The shortest time for 20 cycles of bubbleS is: %f seconds \n", time_spent);
    ??? LONG_LONG_MAX ???