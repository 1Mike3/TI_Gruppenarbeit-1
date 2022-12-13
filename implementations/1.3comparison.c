//
// Created by Michi on 11.12.2022.
//
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "allfunclib.h"

/*
void comparison1_3();
        int main(){
    comparison1_3();
}
*/

//function which implements the 1.2 assignment
void comparison1_3() {
    const int arraySize = 2000;
    const int cycleCount = 20;
    int *arr = malloc(arraySize * sizeof(int));
    genRandNum(arraySize, arr);
    bubbleS(arr, arraySize);
    //bubble sort x20 cycles - store values in array
    int *bubbleSortTimes = malloc(cycleCount * sizeof(int));
    for (int i = 0; i < cycleCount; i++) {
        clock_t start = clock();
        bubbleS(arr, arraySize);
        clock_t end = clock();
        bubbleSortTimes[i] = (int) ((end - start) * 1000 / CLOCKS_PER_SEC);
    }
    //average x20 cycles from the array
    int bubbleSortAverage = 0;
    for (int i = 0; i < cycleCount; i++) {
        bubbleSortAverage += bubbleSortTimes[i];
    }
    bubbleSortAverage /= cycleCount;
    //minimum x20 cycles from the array
    int bubbleSortMin = bubbleSortTimes[0];
    for (int i = 0; i < cycleCount; i++) {
        if (bubbleSortTimes[i] < bubbleSortMin) {
            bubbleSortMin = bubbleSortTimes[i];
        }
    }
    //maximum x20 cycles from the array
    int bubbleSortMax = bubbleSortTimes[0];
    for (int i = 0; i < cycleCount; i++) {
        if (bubbleSortTimes[i] > bubbleSortMax) {
            bubbleSortMax = bubbleSortTimes[i];
        }
    }
    //
    printf("Bubble Sort:\n");
    //print the results of all 20 cycles
    printf("Cycle\t\tTime (ms)\n");
    for (int i = 0; i < cycleCount; i++) {
        printf("%d\t\t%d ms\n", i + 1, bubbleSortTimes[i]);
    }
    printf("\n");
   printf("Minimum of 20 Cycles: %d ms\n", bubbleSortMin);
    printf("Maximum of 20 Cycles: %d ms\n", bubbleSortMax);
    printf("Average of 20 Cycles: %d ms\n", bubbleSortAverage);
    //free the memory
    free(bubbleSortTimes);
}