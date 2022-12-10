#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    //Testarray um Funktion auf Korrektheit zu überrprüfen
    int arrUS[12] = {5,66,8,9,3,7,0,2,1,4,6,5,};
    //Testarray, sortierte version von oberem Array
    int arrS[12] = {};
    unsigned int size = 12;


    //Michi #1 START
    copyArr(arrUS, arrS, size );
    quickS(arrS, size);
    checkSort(arrS, 12, 1);

    //Michi #1 END

    // bubbleS(*arr, size);
    // inserS(*arr, size);

    //################Michi Test Quicksortfunktion######################
    //don't delete, comment out instead pls :)
    printf("\nPrintout of the UNSORTED ARRAY:\n");
    printArr(arrUS, 12);
    printf("\nPrintout of the QS-SORTED ARRAY:\n");
    printArr(arrS, 12);

    //END############Michi Test Qicksortfungktio#######################

    //====================EMAD TEST MERGESORT=====================
    // int pointer
    int *pRandArr1;
    //initalise array with 64 which is the maximum possible size in our case
    int randArr1[8] = { 0 };
    //actual size to which the array will be filled
    int arrSize1 = 8;
    //get the random numbers and save the pointers
    pRandArr1 = genRandNum(arrSize,randArr);
    //print the array with a function
    //printRandArr(pRandArr, arrSize);
    mergeS(randArr1, arrSize1);

    //==========================EOF===============================

    return 0;
}

