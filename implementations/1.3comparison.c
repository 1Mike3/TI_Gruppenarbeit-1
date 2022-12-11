//
// Created by Michi on 11.12.2022.
//
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
}