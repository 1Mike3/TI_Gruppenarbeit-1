//
// Created by Tae Takemi on 07.01.2023.
//

#include "quicksortInt.h"
#include "allfunclib.h"
#include "generateRandomStruct.h"

#include <string.h>


//new Version -Michi

//Used sub-functions, (further infos over implementation):
int chosePartitionI(data *dataStruct, int lower, int upper);
void sortingI(data *dataStruct,int lower, int upper);
void swapIntStruct(data *dataStruct1, data *dataStruct2);



//Qicksortfunction integer
//Rewritten to handle arrays of data-structs
// "size" is the total number of elements the chosen struct array
//!!watch out size is total number of items AND NOT last array index...
void quickSortInt(data *dataStruct, int size){
    //turns size of array into the highest index
    int upperValue = (size-1);
    sortingI(dataStruct, 0, upperValue); // OO arr
}

//######################SUBFUNCTIONS######################################

//function for choosing the Partition, will be recursively called in the "sorting function"
//the lower and upper
int chosePartitionI(data *dataStruct, int lower,int upper){
    //now chosing Pivot middle value instead of rightmost
    //old int pivotValue = (dataStruct+upper)->number;
    //new
    //assign pivot value from middle data struct number element
    int pivotValue = (dataStruct+((upper+lower)/2))->number;
    int lowCounter = lower; // var which will be incremented in for loop

    //shifts all the elements smaller than the pivot value left of it
    for ( int i = lower; i <= upper; ++i) { //
        if ((dataStruct+i)->number < pivotValue){  // OO *arr+i

            if((dataStruct+lowCounter) != (dataStruct+i)) //checks the addresses so don't copy to same address
            swapIntStruct((dataStruct+lowCounter), (dataStruct+i));
            lowCounter++;
        }
    }

    //insert pivot after smaller elements
    swapIntStruct((dataStruct+lowCounter), ( dataStruct+( (upper+lower)/2) ) ); // changed from upper
    return lowCounter;
}

//function which does the actual sorting
void sortingI(data *dataStruct,int lower, int upper){
    // calls itselve recursively and sorts the partitions until the indexes meet
    if(lower < upper){
        //choses a new partition
        int temp = chosePartitionI(dataStruct, lower, upper);
        sortingI(dataStruct, lower, temp-1);
        sortingI(dataStruct, temp+1, upper);
    }

}

//swaps the Integer and string Values of two Structs of the type data
//added strcpy so also swaps the strings of the struct
void swapIntStruct(data *dataStruct1, data *dataStruct2){
    //temp struct used
    data tempStruct;

    //added strypy so whole part of data struct is copied -Michi
    // cpy elements 1 to tempp
    tempStruct.number = dataStruct1->number;
    strcpy(tempStruct.string, dataStruct1->string);

    //cpy elements 2 to 1
    dataStruct1->number = dataStruct2->number;
    strcpy(dataStruct1->string, dataStruct2->string);

    //cpy elements tmp(1) to 2
    dataStruct2->number = tempStruct.number;
    strcpy(dataStruct2->string, tempStruct.string);
}

