//
// Created by Michi on 11.12.2022.
//
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "..\include\allfunclib.h"
/*
//function which implements the 1.2 assignment
void comparison1_3(){
    const int arraySize = 2000;
    const int cycleCount = 20;
    int *arr[arraySize] = {};
    genRandNum(arraySize, arr);
    bubbleS(arr, arraySize);
    //do bubbleS 20 times
    clock_t start = clock();
    for (int i = 0; i < cycleCount; i++) {
        bubbleS(arr, arraySize);
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time spent for bubble sort: %f seconds for %d cycles with %d elements in the array \n", time_spent, cycleCount, arraySize);
    genRandNum(arraySize, arr);
    bubbleS(arr, arraySize);
    double minTime = time_spent;
    double maxTime = time_spent;
    for (int i = 0; i < cycleCount; i++) {
        start = clock();
        bubbleS(arr, arraySize);
        end = clock();
        time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        if (time_spent < minTime){
            minTime = time_spent;
        }
        if (time_spent > maxTime){
            maxTime = time_spent;
        }
    }
    printf("Min time for bubble sort: %f seconds for %d cycles with %d elements in the array \n", minTime, cycleCount, arraySize);
    printf("Max time for bubble sort: %f seconds for %d cycles with %d elements in the array \n", maxTime, cycleCount, arraySize);
*/