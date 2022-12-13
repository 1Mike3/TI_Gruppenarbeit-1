#include <stdio.h>
#include "allfunclib.h"

void merge(int arr[], int l, int m, int r) {

    //declare counter variables
    int i, j, k;
    // Create temp arrays with half the size of arr[]
    int tmpArrSize1 = m - l + 1;
    int tmpArrSize2 = r - m;

    //declare temp arrays
    int arrL[tmpArrSize1], arrR[tmpArrSize2];

    //copy left and right values of arr[] into left and right temp array
    for (i = 0; i < tmpArrSize1; i++)
        arrL[i] = arr[l + i];
    for (j = 0; j < tmpArrSize2; j++)
        arrR[j] = arr[m + 1 + j];

    //reset counters
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

    // Write remaining elements to the array
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

//handle the mergesort request
void mergeS (int *arr, int l, int r){

    //only sort if array actually has a length
    if (l < r) {

        // m is the middle of *arr
        int m = l + (r - l) / 2;

        //sort left
        mergeS(arr, l, m);
        //sort right
        mergeS(arr, m + 1, r);

        // Merge sorted arrays
        merge(arr, l, m, r);
    }

}