//
// Created by Michi on 11.12.2022.
//
#include <stdio.h>
#include <time.h>
#include "..\include\allfunclib.h"
#include "stdlib.h"

void compareLinkedList() {


    // int pointer
    int *pRandArr;
    int randArr[8] = { 0 };
    int arrSize = 8;
    //get the random numbers and save the pointers
    pRandArr = genRandNum(arrSize,randArr);
    printRandArr(pRandArr, arrSize);

    clock_t t;
    t = clock();
    //inserS (pRandArr, arrSize);
    mergeS (pRandArr, 0, arrSize);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC*1000;
    printf("\ninserS() took %f miliseconds to execute \n", time_taken);

    printf("\n");
    printRandArr(pRandArr, arrSize);


}