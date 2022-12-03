//
// Created by Emad on 30/11/2022.
//
#include <stdio.h>
#include "stdlib.h"


//Michi
//Gibt Array an Konsole aus
//!! achtung wenn in funktion verwendet double pointer
void printarr(int *arr, int size){
    for (int i = 0; i < size; ++i) {
        printf("Printarray:\n");
        printf("[%i]: %i\n", i, *(arr+i));
    }
}
//Kopiert arr1 nach arr2
void copyarr(int *arr1, int *arr2, int size){
    for (int i = 0; i < size; ++i) {
        arr2[i] = arr1[i];
    }
}