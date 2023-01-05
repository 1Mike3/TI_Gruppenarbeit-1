//
// Created by osboxes on 05/01/23.
//

#include "quicksortString.h"
#include "allfunclib.h"
#include "generateRandomStruct.h"
#include "string.h"
#include <stdlib.h>
#include "stdio.h"
#include "binarySearchAlgorithm.h"

//will be changed to string

//Used sub-functions, (further infos over implementation):
//unsigned in for indexes chosen so don't waste space on negative array indexes
//lower technically not needed but added to be able to sort arrays partially
int chosePartition(data *dataArray, int lower, int upper);
void sorting(data *dataArray ,int lower, int upper);



//Qicksortfunction, entered array will be sorted using the quicksort-alg
//"arr" is the chosen array of any size (edgecase size 0 behavior?)
// "size" is the total number of elements the chosen array
//!!watch out size is total number of items AND NOT last array index...
void quickSortString(data *dataArray, int size){
    int upperValue = (size-1);
    sorting( dataArray, 0, upperValue);
}

//######################SUBFUNCTIONS######################################

//function for choosing the Partition, will be recursively called in the "sorting function"
//the lower and upper
int chosePartition(data *dataArray,int lower,int upper){

    //initialising Pivot, always chosen as upper element
    char *pivotValue = calloc(strlen((dataArray+upper)->string), sizeof(char ));
    strcpy(pivotValue, (dataArray+upper)->string);

    int lowCounter = lower; // var which will be incremented in for loop

    for ( int i = lower; i <= upper; ++i) { //
        if (checkOrderString(pivotValue, (dataArray+i)->string)){ // OO (*(arr+i) < pivotValue){
            swapi((arr+lowCounter), (arr+i));                     // OO swapi((arr+lowCounter), (arr+i));
            lowCounter++;
        }
    }
    swapi((arr+lowCounter), (arr+upper));
    return lowCounter;
}

//function which does the actual sorting
void sorting(data *dataArray,int lower, int upper){
    if(lower < upper){
        int temp = chosePartition(arr , lower, upper);
        sorting(arr, lower, temp-1);
        sorting(arr, temp+1, upper);
    }
}

//function to swap two strings in an array
//!!Untested
void swapStr(char *val1,char *val2){
    char *temp  = val1;
    *val1 = *val2;
    *val2 = temp;
}
