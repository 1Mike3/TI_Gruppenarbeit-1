#include <stdio.h>
#include "allfunclib.h"



//Prrint array values to console
void printArr(int *arr, int size){
    printf("Printarray:\n");
    for (int i = 0; i < size; ++i) {
        printf("[%i]: %i\n", i, *(arr+i));
    }

}

//copy values of array1 too array2
void copyArr(int *arr1, int *arr2, int size){
    for (int i = 0; i < size; ++i) {
        arr2[i] = arr1[i];
    }
}

//swap the values of two integer pointers
//functioncall example arrays:  swapi(arr,(arr+size-1)); !!don#t forget -1 at size to avoid writing outside array bounds
void swapi(int *val1, int *val2){
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}


//function which checks if an array is sorted (ascending)
//return 0 if sorted correctly
//return 1 if sorted incorrectly
//mode if mode is set to 1 it also prints out a info message to the console, if it is 0 only return value
int checkSort(int *arr, int size, short int mode){

    int tempLeftToComapare = 0;
    int largerElementFound = 0;
    for (int i = 0; i < (size); ++i) { //size -1 because don't need check for last element
        for (int j = (int)(size-1); j >= tempLeftToComapare; --j) {
            if(*(arr+i) <= (*(arr+j)) ){
                //debug Helper :)
                //printf("arr+ i =(%i)  <=  arr+j =(%i)\n",*(arr+i),*(arr+j));
                continue;
            } else{
                largerElementFound = 1;
            }
        }
        tempLeftToComapare++;
        if(largerElementFound == 1){
            if(mode == 1){
                printf("checkSort: the chosen array is UNSORTED. \n");
            }
            return 1;
        }
    }
    if(mode == 1){
        printf("checkSort: the chosen array is SORTED. \n");
    }
    return 0;
}

//print array pointer (for rand arraygen)
//print the array
void printRandArr(int *arrToPrint, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        printf(" %d", *(arrToPrint + i));
    }
}
