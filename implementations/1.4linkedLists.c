//
// Created by Michi on 11.12.2022.
//
#include <stdio.h>
#include <time.h>
#include "..\include\allfunclib.h"
#include "stdlib.h"
// C function showing how to do time delay
#include <stdio.h>
// To use time library of C
#include <time.h>

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

void compareLinkedList() {

    clock_t begin, end;

    begin = clock();

    // int pointer
    int *pRandArr;
    int randArr[2048] = { 0 };
    int arrSize = 2048;
    //get the random numbers and save the pointers
    pRandArr = genRandNum(arrSize,randArr);

    end = clock();

    double time_taken = ((double)end - (double)begin) / CLOCKS_PER_SEC;

    printf("\nInitiasiation of int array took %f miliseconds to execute \n", time_taken);

//========insertionsort with linked list
    inserS_LL(pRandArr, arrSize);

/*
    printf("\nunsorted Array \n");
    printRandArr(pRandArr, arrSize);
*/
    clock_t t;
    t = clock();

    inserS (pRandArr, arrSize);

    t = clock() - t;
/*
    printf("\nsorted Array \n");
    printRandArr(pRandArr, arrSize);
*/
    time_taken = ((float)t)/CLOCKS_PER_SEC*1000;

    printf("\ninserS() with array took %f miliseconds to execute \n", time_taken);


}