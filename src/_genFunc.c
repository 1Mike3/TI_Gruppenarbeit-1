//
// Created by Emad on 30/11/2022.
//
#include <stdio.h>
#include "stdlib.h"

//==========Michi
//Prrint array values to consoole
void printarr(int *arr, unsigned int size){
    for (int i = 0; i < size; ++i) {
        printf("Printarray:\n");
        printf("[%i]: %i\n", i, *(arr+i));
    }
}
//copy values of array1 too array2
void copyarr(int *arr1, int *arr2, unsigned int size){
    for (int i = 0; i < size; ++i) {
        arr2[i] = arr1[i];
    }
}

//swap the values of two integer pointers
void swapi(int *val1, int *val2){
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

//===========EMAD
//print array pointer (for rand arraygen)
//print the array
void printRandArr(int *arrToPrint, int arrSize) {
    printf("Arr ");
    for (int i = 0; i < arrSize; i++) {
        printf(" %d", *(arrToPrint + i));
    }
}