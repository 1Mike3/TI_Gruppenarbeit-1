//
// Created by Michi on 29.11.2022.
//
//Emad working ============DONT CHANGE!!!
#include <stdio.h>
#include "../include/allfunclib.h"

//this fuction is the main implementation of the merge sort algorithm
void mergeS (int *arr, unsigned int size){
    int i, j, l, r, m, k;
    l = 0; //left index
    r = size - 1; //right index = size -1
    m = l + (r - l) / 2; //middle index
    int tmpArrSize1 = m - l + 1;
    int tmpArrSize2 = r - m;

    int arrL[tmpArrSize1], arrR[tmpArrSize2];

    //copy arr to left and right temp arrays
    for (i = 0; i < tmpArrSize1; i++){
        arrL[i] = arr[l + i];
    }
    for (j = 0; j < tmpArrSize2; j++){
        arrR[j] = arr[m + 1 + j];
    }
    printf("\n");
    printRandArr(arrL, tmpArrSize1);
    printf("\n");
    printf("\n");
    printRandArr(arrR, tmpArrSize2);
    printf("\n");
    i = 0;
    j = 0;
    k = 1;

    //while array indexes are smaller than array size
    while (i < tmpArrSize1 && j < tmpArrSize2) {
        //when the number under left arrays index is smaller than the right then sort it
        // and add it to the k index of original array
        if (arrL[i] <= arrR[j]) {
            arr[k] = arrL[i];
            i++;
        }
        else {
            arr[k] = arrR[j];
            j++;
        }
        k++;
    }
    while (i < tmpArrSize1) {
        arr[k] = arrL[i];
        k++;
        i++;
    }

    while (j < tmpArrSize2) {
        arr[k] = arrR[j];
        j++;
        k++;
    }

    printf("%d %d %d %d", tmpArrSize1, tmpArrSize2, r, m);

}