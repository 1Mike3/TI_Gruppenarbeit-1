//
// Created by Tae Takemi on 07.01.2023.
//

#include "quicksortInt.h"
#include "allfunclib.h"
#include "generateRandomStruct.h"

#include <string.h>

//Commented out old from Markus
/*
//Used sub-functions, (further infos over implementation):
//unsigned in for indexes chosen so don't waste space on negative array indexes
//lower technically not needed but added to be able to sort arrays partially
int chosePartition(data *dataStruct, int lower, int upper);
void sorting(data *dataStruct,int lower, int upper);


void swapStruct(data *pData, data *pData1);

//Qicksortfunction, entered array will be sorted using the quicksort-alg
//"arr" is the chosen array of any size (edgecase size 0 behavior?)
// "size" is the total number of elements the chosen array
//!!watch out size is total number of items AND NOT last array index...
void quicksortInt(data *dataStruct, int size){
    int upperValue = (size-1);
    sorting(dataStruct, 0, upperValue);
}

//######################SUBFUNCTIONS######################################

//function for choosing the Partition, will be recursively called in the "sorting function"
//the lower and upper
int chosePartition(data *dataStruct,int lower,int upper){
    int pivot = dataStruct[upper].value;
    int i = (lower - 1);
    for (int j = lower; j <= upper - 1; j++) {
        if (dataStruct[j].value <= pivot) {
            i++;
            swapStruct(&dataStruct[i], &dataStruct[j]);
        }
    }
    swapStruct(&dataStruct[i + 1], &dataStruct[upper]);
    return (i + 1);
}

*/


//new Version -Michi

//Used sub-functions, (further infos over implementation):
//unsigned in for indexes chosen so don't waste space on negative array indexes
//lower technically not needed but added to be able to sort arrays partially
int chosePartitionI(data *dataStruct, int lower, int upper);
void sortingI(data *dataStruct,int lower, int upper);
void swapIntStruct(data *dataStruct1, data *dataStruct2);



//Qicksortfunction, entered array will be sorted using the quicksort-alg
//"arr" is the chosen array of any size (edgecase size 0 behavior?)
// "size" is the total number of elements the chosen array
//!!watch out size is total number of items AND NOT last array index...
void quickSortInt(data *dataStruct, int size){
    int upperValue = (size-1);
    sortingI(dataStruct, 0, upperValue); // OO arr
}

//######################SUBFUNCTIONS######################################

//function for choosing the Partition, will be recursively called in the "sorting function"
//the lower and upper
int chosePartitionI(data *dataStruct, int lower,int upper){
    int pivotValue = (dataStruct+upper)->number; //initialising Pivot, always chosen as upper element //OO *(arr+upper)
    int lowCounter = lower; // var which will be incremented in for loop

    for ( int i = lower; i <= upper; ++i) { //
        if ((dataStruct+i)->number < pivotValue){  // OO *arr+i

            if((dataStruct+lowCounter) != (dataStruct+i)) //checks the addresses so don't copy to same address
            swapIntStruct((dataStruct+lowCounter), (dataStruct+i));
            lowCounter++;
        }
    }
    swapIntStruct((dataStruct+lowCounter), (dataStruct+upper));
    return lowCounter;
}

//function which does the actual sorting
void sortingI(data *dataStruct,int lower, int upper){
    if(lower < upper){
        int temp = chosePartitionI(dataStruct, lower, upper);
        sortingI(dataStruct, lower, temp-1);
        sortingI(dataStruct, temp+1, upper);
    }

}

//swaps the Integer Value of two Structs of the type data
//added strcpy so also swaps the strings of the struct
void swapIntStruct(data *dataStruct1, data *dataStruct2){
    data tempStruct;

    //added strypy so whole part of data struct is copied -Michi

    tempStruct.number = dataStruct1->number;
    strcpy(tempStruct.string, dataStruct1->string);

    dataStruct1->number = dataStruct2->number;
    strcpy(dataStruct1->string, dataStruct2->string);

    dataStruct2->number = tempStruct.number;
    strcpy(dataStruct2->string, tempStruct.string);
}

