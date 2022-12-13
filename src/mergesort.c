//
// Created by Michi on 29.11.2022.
//
//Emad working ============DONT CHANGE!!!
#include <stdio.h>
#include "allfunclib.h"

void merge(int arr[], int l, int m, int r) {

    int i, j, k;
    // Create temp arrays with half the size
    int tmpArrSize1 = m - l + 1;
    int tmpArrSize2 = r - m;

    int arrL[tmpArrSize1], arrR[tmpArrSize2];

    for (int i = 0; i < tmpArrSize1; i++)
        arrL[i] = arr[l + i];
    for (int j = 0; j < tmpArrSize2; j++)
        arrR[j] = arr[m + 1 + j];



    i = 0;
    j = 0;
    k = l;

    // Sort the elements if left larger than right write to left
    while (i < tmpArrSize1 && j < tmpArrSize2) {
        if (arrL[i] <= arrR[j]) {
            arr[k] = arrL[i];
            i++;
        } else {
            arr[k] = arrR[j];
            j++;
        }
        k++;
    }

    // Write remeaining elements to the array
    while (i < tmpArrSize1) {
        arr[k] = arrL[i];
        i++;
        k++;
    }

    while (j < tmpArrSize2) {
        arr[k] = arrR[j];
        j++;
        k++;
    }
}


void mergeS (int *arr, int l, int r){
    if (l < r) {

        // m is the middle
        int m = l + (r - l) / 2;

        //sort left
        mergeS(arr, l, m);
        //sort right
        mergeS(arr, m + 1, r);

        // Merge sorted arrays
        merge(arr, l, m, r);
    }

}