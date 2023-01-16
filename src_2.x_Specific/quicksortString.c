//
// Created by osboxes on 05/01/23.
//


#include "string.h"
#include <stdlib.h>
#include "binarySearchAlgorithm.h"

//Changed our old quicksortfunction to compart stings in Data --Michi

//Used sub-functions, (further infos over implementation):
//unsigned in for indexes chosen so don't waste space on negative array indexes
//lower technically not needed but added to be able to sort arrays partially
int chosePartition(data *dataArray, int lower, int upper);
void sortings(data *dataArray ,int lower, int upper);
void swapStr(data *dataStr1 , data *dataStr2);



//Qicksortfunction, entered array will be sorted using the quicksort-alg
//"arr" is the chosen array of any size (edgecase size 0 behavior?)
// "size" is the total number of elements the chosen array
//!!watch out size is total number of items AND NOT last array index...
void quickSortString(data *dataArray, int size){
    int upperValue = (size-1);
    sortings( dataArray, 0, upperValue);
}

//######################SUBFUNCTIONS######################################

//function for choosing the Partition, will be recursively called in the "sorting function"
//the lower and upper
int chosePartitions(data *dataArray,int lower,int upper){

    //initialising Pivot, always chosen as upper element
    char *pivotValue = calloc((strlen((dataArray+upper)->string)+1), sizeof(char ));
    strcpy(pivotValue, (dataArray+upper)->string);

    int lowCounter = lower; // var which will be incremented in for loop

    for ( int i = lower; i <= upper; ++i) { //
        if (orderString_secondStringLess == checkOrderString(pivotValue, (dataArray+i)->string)){ // OO (*(arr+i) < pivotValue){


             if((dataArray + i) != (dataArray+lowCounter)) //so don't swap same memory addresses!!
             swapStr((dataArray + i), (dataArray+lowCounter));            // OO swapi((arr+lowCounter), (arr+i));

            lowCounter++;
        }
    }

    swapStr((dataArray+lowCounter),(dataArray+upper)); // OO swapi((arr+lowCounter), (arr+upper));
    free(pivotValue);
    return lowCounter;
}

//function which does the actual sorting
void sortings(data *dataArray,int lower, int upper){
    if(lower < upper){
        int temp = chosePartitions(dataArray , lower, upper);
        sortings(dataArray, lower, temp-1);
        sortings(dataArray, temp+1, upper);
    }
}

/* old, only switches string but not integer
//function to swap two strings in an array
//!!Untested
void swapStr(char *val1,char *val2){
    char temp[6];
    strcpy(temp, val1);
    strcpy(val1, val2);
    strcpy(val2, temp);
}
*/

//function which swaps two dataStruct values
void swapStr(data *dataStr1,data *dataStr2){
    data tempStr;

    //copy values one to temp
    strcpy(tempStr.string, dataStr1->string);
    tempStr.number = dataStr1->number;

    //copy values two to one
    strcpy(dataStr1->string, dataStr2->string);
    dataStr1->number = dataStr2->number;

//copy valuees temp (one) to two
    strcpy(dataStr2->string, tempStr.string);
    dataStr2->number = tempStr.number;
}
