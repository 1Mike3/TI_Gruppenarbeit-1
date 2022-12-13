//
// Created by Michi on 11.12.2022.
//
#include <stdio.h>
#include <time.h>
#include "allfunclib.h"

void compareLinkedList() {

    //===================Calculate time taken by array init
    clock_t begin, end;
    begin = clock();
    // int pointer
    int *pRandArr;
    int randArr[2048] = { 0 };
    int arrSize = 2048;
    //get the random numbers and save the pointers
    pRandArr = genRandNum(arrSize,randArr);
    end = clock();
    double init_time_taken2 = ((double)end - (double)begin) / CLOCKS_PER_SEC;
    //===================END

    //===================Calculate time taken by struct init
    //by calling insertionsort and "returning" the values
    //Also sort the struct filled with the values of above generated array
    double timetaken_real;
    double *init_time_taken = &timetaken_real;
    double timetaken_real_sort;
    double *sort_time_taken = &timetaken_real_sort;
    //========insertionsort with linked list
    inserS_LL(pRandArr, arrSize, init_time_taken, sort_time_taken);
    //===================END


    //===================Calculate time taken by insertionsort of array
    begin = clock();

    inserS (pRandArr, arrSize);

    end = clock();

    double sort_time_taken2 = (((double)end - (double)begin) / CLOCKS_PER_SEC * 1000);
    //====================END
    //====================Print only 15 values of sorted array
    printf("\nSorted Array \n");
    //may throw a warning since it is "always" true (arrSize is not changed in the program)
    //printRandArr(pRandArr, 15) : printRandArr(pRandArr, arrSize); //not used since warning and arrSize is not dynamic
    printRandArr(pRandArr, 15);
    //====================END
    printf("\n\n");
    //===================Print the init values
    printf("\nInitialisation of\t\tTime needed (ms)\n");
    printf("-------------------------------------------\n");
    (init_time_taken2 < 0) ? printf("\nArray of size[%d]\t\t <1ms\n", arrSize) : printf("\nArray of size[%d]\t\t%.2f \n", arrSize, init_time_taken2);
    (*init_time_taken < 0) ? printf("\nStruct\t\t\t\t <1ms \n") : printf("\nStruct\t\t\t\t%.2f \n", *init_time_taken);

    printf("\n");
    //===================END

    //====================Print the values of time taken by sorting algs
    printf("\nSorting algorithm\t\tTime needed (ms) \n");
    printf("-------------------------------------------\n");
    (sort_time_taken2 < 0) ? printf("\nInsertionsort array\t\t <1ms \n") : printf("\nInsertionsort array\t\t%.2f \n", sort_time_taken2);
    (*sort_time_taken < 0) ? printf("\nInsertionsort linked list\t <1ms \n") : printf("\nInsertionsort linked list\t%.2f \n", *sort_time_taken);
    //====================END
//
}