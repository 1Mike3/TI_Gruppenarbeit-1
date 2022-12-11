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
    int randArr[8192] = { 0 };
    int arrSize = 8192;
    //get the random numbers and save the pointers


    pRandArr = genRandNum(arrSize,randArr);

    inserS_LL(pRandArr, arrSize);

    clock_t t;

    t = clock();


    inserS (pRandArr, arrSize);

    t = clock() - t;

    //printRandArr(pRandArr, arrSize);
    double time_taken = ((double)t)/CLOCKS_PER_SEC*1000;


    printf("\n");
    //printRandArr(pRandArr, arrSize);

    printf("\ninserS() with array took %f miliseconds to execute \n", time_taken);


}