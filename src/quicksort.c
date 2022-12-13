#include "allfunclib.h"



//Used sub-functions, (further infos over implementation):
//unsigned in for indexes chosen so don't waste space on negative array indexes
//lower technically not needed but added to be able to sort arrays partially
int chosePartition(int *arr, int lower, int upper);
void sorting(int *arr,int lower, int upper);



//Qicksortfunction, entered array will be sorted using the quicksort-alg
//"arr" is the chosen array of any size (edgecase size 0 behavior?)
// "size" is the total number of elements the chosen array
//!!watch out size is total number of items AND NOT last array index...
void quickS(int *arr, int size){
    int upperValue = (size-1);
    sorting(arr, 0, upperValue);
}

//######################SUBFUNCTIONS######################################

//function for choosing the Partition, will be recursively called in the "sorting function"
//the lower and upper
int chosePartition(int *arr,int lower,int upper){
   int pivotValue = *(arr+upper); //initialising Pivot, always chosen as upper element
   int lowCounter = lower; // var which will be incremented in for loop

    for ( unsigned int i = lower; i <= upper; ++i) { //
        if (*(arr+i) < pivotValue){
            swapi((arr+lowCounter), (arr+i));
            lowCounter++;
        }
    }
    swapi((arr+lowCounter), (arr+upper));
    return lowCounter;
}

//function which does the actual sorting
void sorting(int *arr,int lower, int upper){
    if(lower < upper){
        int temp = chosePartition(arr , lower, upper);
        sorting(arr, lower, temp-1);
        sorting(arr, temp+1, upper);
    }

}



