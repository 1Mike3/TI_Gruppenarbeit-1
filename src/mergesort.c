//
// Created by Michi on 29.11.2022.
//
//Emad working ============DONT CHANGE!!!
#include <stdio.h>

//this fuction is the main implementation of the merge sort algorithm
void mergeS (int *arr, unsigned int size){
    int i, l, r, m;
    l = 0;
    r = size - 1;
    m = l + (r - l) / 2;
    int tmpArrSize1 = m - l + 1;
    int tmpArrSize2 = r - m;

    int arrL[tmpArrSize1], arrR[tmpArrSize2];
    printf("%d %d %d %d", tmpArrSize1, tmpArrSize2, r, m);

}