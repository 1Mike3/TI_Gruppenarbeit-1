//
// Created by Mark on 10.12.2022.
//
//Emad working ============DONT CHANGE!!!
#include <stdio.h>

//this fuction is the main implementation of the merge sort algorithm
void mergeS (int *arr, unsigned int size){
    int i, j, k;
    int n1 = m - 1 +1;
    int n2 = r - m;
    //create temp arrays
    int L[n1], R[n2];

    //copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    //merge the temp arrays back into arr[l..r]
    i = 0; //initial index of first subarray
    j = 0; //initial index of second subarray
    k = l; //initial index of merged subarray
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    //copy the remaining elements of L[], if there are any
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    //copy the remaining elements of R[], if there are any
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergesort(int *arr, int l, int r){
    if (l < r){
        //same as (l+r)/2, but avoids overflow for large l and h
        int m = l + (r - l) / 2;

        //sort first and second halves
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);

        mergeS(arr, l, m, r);
    }
}
