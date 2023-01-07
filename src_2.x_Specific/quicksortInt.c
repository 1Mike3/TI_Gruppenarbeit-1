//
// Created by Tae Takemi on 07.01.2023.
//

#include "quicksortInt.h"
#include "allfunclib.h"
#include "generateRandomStruct.h"



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


