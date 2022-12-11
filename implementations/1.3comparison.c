//
// Created by Michi on 11.12.2022.
//
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "..\include\allfunclib.h"

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
    printf("Average: %d\n", bubbleSortAverage);
    printf("Minimum: %d\n", bubbleSortMin);
    printf("Maximum: %d\n", bubbleSortMax);
    //print the results of all 20 cycles
    printf("All 20 cycles:\n");
    for (int i = 0; i < cycleCount; i++) {
        printf("%d\n", bubbleSortTimes[i]);
    }
    //free the memory
    free(bubbleSortTimes);
}