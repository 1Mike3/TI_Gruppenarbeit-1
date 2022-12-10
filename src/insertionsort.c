//
// Created by Michi on 30.11.2022.
// Edited by Mark on 10.12.2022.
//
#include "stdio.h"

void inserS (int *arr, unsigned int size){
    int i, j, temp;
    for (i = 1; i < size; i++) {
        temp = *(arr+i);
        j = i-1;
        while (j >= 0 && *(arr+j) > temp) {
            *(arr+j+1) = *(arr+j);
            j = j-1;
        }
        *(arr+j+1) = temp;
    }
}