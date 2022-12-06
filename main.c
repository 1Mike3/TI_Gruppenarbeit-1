#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//include custom lib
#include "include/allfunclib.h"

int main() {

    //Testarray um Funktion auf Korrektheit zu überrprüfen
    int arrUS[12] = {5,66,8,3,3,7,0,2,1,4,6,9,};
    //Testarray, sortierte version von oberem Array
    int arrS[12] = {};
    unsigned int size = 12;

    //mergeS(*arr, size);
    //quickS(arrUS, size);
    // bubbleS(*arr, size);
    // inserS(*arr, size);


    //=====================FERTIG DONTDELETE =======GETRANNUM
    //int pointer
    int *pRandArr;
    //initalise array with 64 which is the maximum possible size in our case
    int randArr[64] = { 0 };
    //actual size to which the array will be filled
    int arrSize = 8;
    //get the random numbers and save the pointers
    pRandArr = genRandNum(arrSize,randArr);
    //print the array with a function
    printRandArr(pRandArr, arrSize);
    //===================== EOF=====================GETRANNUM

    return 0;
}

