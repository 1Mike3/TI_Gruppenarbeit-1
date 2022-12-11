#include <stdio.h>

//include custom lib
#include "include/allfunclib.h"

int main() {



    //=============EMAD FERTIG DONTDELETE =======GETRANNUM
    // int pointer
    int *pRandArr;
    //initalise array with 64 which is the maximum possible size in our case
    int randArr[64] = { 0 };
    //actual size to which the array will be filled
    int arrSize = 8;
    //get the random numbers and save the pointers
    pRandArr = genRandNum(arrSize,randArr);
    //print the array with a function
    //printRandArr(pRandArr, arrSize);
    //=====================EOF===================GETRANNUM

/*
    //Testarray to check function on correctness
    int arrUS[12] = {5,66,8,9,3,7,0,2,1,4,6,5,};
    //Testarray, sorted version of the array below
    int arrS[12] = {5,66,8,9,3,7,0,-2,1,4,6,5,};
    unsigned int size = 12;
*/

    //Michi attempt at implementation 1.1

    //created the th arrays but have not initialized them, this will happen in the "basicCheck1_1 function with Emads rand func"
    printf("\nSTART implementation 1.1\n");
        int call = 1; //Variable that stands for the different sorting algorithms see 1.1implementation.c for further detail
        const int arrSizePar[3] = {8, 16,64}; //size parameter, determines the tested array sizes in the basic check function

        while (call < 5) { //while loop which increments the call variable so that a different sort. alg. is used every cycle.
            basicCheck1_1(call, arrSizePar, 3);
            call++;
        }
        printf("\nEND implementation 1.1\n");
    //Michi END attempt at implementation 1.1

    // bubbleS(*arr, size);
    // inserS(*arr, size);


    //################Michi Test Quicksortfunktion######################
    //don't delete, comment out instead pls :)
    /*
    quickS(arrS,12);
    printf("\nPrintout of the UNSORTED ARRAY:\n");
    printArr(arrUS, 12);
    printf("\nPrintout of the QS-SORTED ARRAY:\n");
    printArr(arrS, 12);
    */
    //END############Michi Test Qicksortfungktio#######################

/*

    //====================EMAD TEST MERGESORT=====================
    // int pointer
    int *pRandArr1;
    //initalise array with 64 which is the maximum possible size in our case
    int randArr1[64] = { 0 };
    //actual size to which the array will be filled
    int arrSize1 = 8;
    //get the random numbers and save the pointers
    pRandArr1 = genRandNum(arrSize1,randArr);
    //print the array with a function
    //printRandArr(pRandArr, arrSize);
    printf("\n");
    printRandArr(pRandArr1, arrSize1);
    printf("\n");

    //mergeS(pRandArr1, arrSize1);
    mergeS(pRandArr1, 0, arrSize1 - 1);

    printf("\n");
    printRandArr(pRandArr1, arrSize1);
    printf("\n");

    //==========================EOF===============================
*/
    return 0;
}

