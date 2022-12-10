//
// Created by Emad on 30/11/2022.
// Edited by Mark on 10.12.2022.
//

#include <stdio.h>

void bubbleS (int *arr, unsigned int size){
    int i, j, temp;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (*(arr+j) > *(arr+j+1)) {
                int temp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
            }
        }
    }
}
