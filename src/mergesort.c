//
// Created by Michi on 29.11.2022.
//
//Emad working ============DONT CHANGE!!!
#include <stdio.h>
#include "../include/allfunclib.h"

void merge(int arr[], int l, int m, int r) {

    // Create L ← A[p..q] and M ← A[q+1..r]
    int tmpArrSize1 = m - l + 1;
    int tmpArrSize2 = r - m;

    int arrL[tmpArrSize1], arrR[tmpArrSize2];

    for (int i = 0; i < tmpArrSize1; i++)
        arrL[i] = arr[l + i];
    for (int j = 0; j < tmpArrSize2; j++)
        arrR[j] = arr[m + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = l;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
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

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
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
//this fuction is the main implementation of the merge sort algorithm
//void mergeS (int *arr, unsigned int size){
void mergeS (int *arr, int l, int r){
    if (l < r) {

        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeS(arr, l, m);
        mergeS(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
    /*
    int i = 0, j = 0, l, r, m, k;
    l = 0; //left index
    r = size - 1; //right index = size -1
    m = l + (r - l) / 2; //middle index
    int tmpArrSize1 = m - l + 1;
    int tmpArrSize2 = r - m;

    int halfSize = size;
    int arrSize[100] = { 0 };
    int halfSArrSize = 0;
    do{
        arrSize[j] = halfSize;
        j++;
        halfSize = halfSize / 2;
        halfSArrSize++;
        if(halfSize == 1){
            arrSize[j] = halfSize;
            halfSArrSize++;
            i = 1;
        }
    } while( i == 0 );
    for(i = 0; i < halfSArrSize; i++){
        printf("%d ", arrSize[i]);
    }

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
    k = 0;

    //while array indexes are smaller than array size
    while (i < tmpArrSize1 && j < tmpArrSize2) {
        //when the number under left arrays index is smaller than the right then sort it
        // and add it to the k index of original array
        if (arrR[i] <= arrL[j]) {
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
*/
}