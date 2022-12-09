//
// Created by Michi on 30.11.2022.
//My Implementation of the quicksort algorithm
//

//STATUS Build in progress

#include "..\include\allfunclib.h"
#include "stdio.h"
#include "stdlib.h"

//TODO create error code for different runtime problems /errors
//TODO implement a check function to truly know if the array is sorted
//TODO make a shell script on anuminas which fethes the .c , compiles it and checks it with valgrind

//Used sub-functions, (further infos over implementation):
void pivotSide(int pivot,int * arr, unsigned int size,unsigned int pivInd,unsigned int *rollPivInd);
void sortLowPartition(int *arr,unsigned int size,unsigned int rollingPivot,short int *done );
void sortHighPartition(int *arr,unsigned int size, unsigned int rollingPivot, short int *done);
void sortLowPartitionPivot(int *arr, unsigned int newPivotIndex, unsigned int newpivotValue, unsigned int *newrollingpivot, unsigned int leftborder);


//Qicksortfunction, entered array will be sorted using the quicksort-alg
//"arr" is the chosen array of any size (edgecase size 0 behavior?)
// "size" is the value of the chosen array
void quickS (int *arr, unsigned int size){
unsigned int  initPivotindex = 0, rollingPivotIndex = 0;
int pivot = 0;

int Status = 0; //Statuscode for te status of the "checkWhereNextPivot" function
short int lSideDone = 0; //if 1: no further sorting needed on the left partition
short int rSideDone = 0; //if 1: no further sorting needed on the right partition


//''''''''''''''''''''''Chosing the Pivot''''''''''''''''''''''''''''''
//for now i will just select the first element, might change later

initPivotindex = 5;
pivot = *(arr + initPivotindex); //plus initPivotindex so i can change it later easily


//TEST Printf-function for test purposes, delete later
    printf("My Pivot is: %i, at Index: %i\n", pivot, initPivotindex);
//END''''''''''''''''''''''Chosing the Pivot''''''''''''''''''''''''''''''


    //'''''''''''''''''''''''''sort around first pivot'''''''''''''''''''''''''
    pivotSide(pivot, arr, size,initPivotindex, &rollingPivotIndex);
    //TEST
    printf("My new Pivot is: %i, \n", rollingPivotIndex);
    //END''''''''''''''''''sort around first pivot''''''''''''''''''''''''''

//sort lower Side
//commented out till so
    sortLowPartition(arr, size, rollingPivotIndex, &lSideDone);
   sortHighPartition(arr,size,rollingPivotIndex,&rSideDone);
//Sort higher Side


}//END QS Function




//######################SUBFUNCTIONS######################################




//pivotside function which puts the values lower than the pivot left of it,
//and values higher than the pivot right of it
//NOTE equal to pivot written on the left side of the pivot
//TODO test with equal values & edgecases

//    pivot, the unsorted array,size of the array,index of pivot bef. function,index of pivot aft. function
void pivotSide(int pivot ,int *arr, unsigned int size,unsigned  int pivInd,unsigned int *rollPivInd){

    //TEST here was 12 in the brackets and 0,0 in the curly brackets
    int *tempArr = malloc(sizeof(int)*size) ; //temporary working array, will be written into *arr at the end of the function
    if (tempArr == NULL) {
         printf("Out of Memory\n");
         }
    unsigned int tempRollingIndex = 0; //counter used for writing the values into the correct array index

    for (int i = 0; i < size; i++) { //insert lesser/equal then pivot
        if ((*(arr + i) <= pivot) && (i != pivInd)) {
            *(tempArr + tempRollingIndex) = *(arr + i);
            tempRollingIndex++;
        }
    }

//insert pivot into half sorted array
*(tempArr + tempRollingIndex) = pivot;
    *rollPivInd = (int)tempRollingIndex;
tempRollingIndex++;

    for(int i = 0; i  < size; i++) { //insert values greater then pivot
        if ((*(arr + i) > pivot) && (i != pivInd)) {
            *(tempArr + tempRollingIndex) = *(arr + i);
            tempRollingIndex++;
        }
    }

   copyArr(tempArr, arr, size); //copy temporarry input array into main array

    //TEST
    if(tempRollingIndex > size){ printf("ERROR quicksort pivotSide written too many values\n");}
    free(tempArr);
}//END Pivotside Function



//Function to sort the lower Partition
void sortLowPartition(int *arr,unsigned int size,unsigned int rollingPivot,short int *done ){
   unsigned int temp = (size - rollingPivot);
   unsigned int sizeLower = (size - temp-1); //find out size of lower partition, -1 so the Pivot wont be counted
    int offsetValue = 0; //value to offset shifts in array

    //:default -----this variables are all for the default part of the switch statement
    unsigned  int newPivotIndex = 0; // new pivot will be saved here if one is needed
    int newPivotValue = 0; //new pivot value will be saved here
    unsigned int newInternalRollingPivot = 0; //Value witch tracks where the Pivot will land after the function


    switch (sizeLower) { //switch case to determine action based on partition size
        case 0:
        case 1:*done = 1;
            break;
        case 2: //determine if elements in order, else swap
            if(*arr > *(arr+1)){
                swapi(arr, (arr+1));
                *done = 1;
                break;
            } else{
                *done = 1;
                break;
            }
        case 3:
            //first no smallest

            if((*(arr+offsetValue) <= *(arr+offsetValue+1)) && (*(arr+offsetValue) <= *(arr+offsetValue+2))) {
                if(*(arr+offsetValue+1) > *(arr+offsetValue+2)){
                    swapi((arr+offsetValue+1),(arr+offsetValue+2));
                }
                done = 1;
                break;
            }
            //second no smallest
            if((*(arr+offsetValue+1) <= *(arr+offsetValue)) && (*(arr+offsetValue+1) <= *(arr+offsetValue+2))) {
                swapi((arr + offsetValue), (arr + offsetValue+1));
                if (*(arr + offsetValue + 1) > *(arr + offsetValue + 2)) {
                    swapi((arr + offsetValue + 1), (arr + offsetValue + 2));
                }
                done = 1;
                printf("Printout arr+offsetno: %i\n", *(arr+offsetValue));
                printf("Printout arr+offsetno: %i\n", *(arr+offsetValue+1));
                printf("Printout arr+offsetno: %i\n", *(arr+offsetValue+2));
                break;
            }
            //third no smallest
            if((*(arr+offsetValue+2) <= *(arr+offsetValue)) && (*(arr+offsetValue+2) <= *(arr+offsetValue+1))) {
                swapi((arr + offsetValue), (arr + offsetValue+2));
                if (*(arr + offsetValue + 1) > *(arr + offsetValue + 2)) {
                    swapi((arr + offsetValue + 1), (arr + offsetValue));
                }
                done = 1;
                break;
            }


            //creating new partition if the number of left elements is larger then 3
        default:
            //The rightmost Pivot will always be chosen
            newPivotIndex = sizeLower;
           newPivotValue = *(arr+sizeLower);

//size is new Pivot index because the rightmost element is chosen
           // pivotSide(newPivotValue,arr,newPivotIndex,newPivotIndex,&newInternalRollingPivot);
        sortLowPartitionPivot(arr, newPivotIndex, newPivotValue, &newInternalRollingPivot, 0);
            break;
    }//endswith
}//end sortlower Function




//Function to sort the higher Partition
void sortHighPartition(int *arr,unsigned int size, unsigned int rollingPivot,short int *done){
    //offsetvalue: starts counting on the upper part of the array
//the minus 1 is because the highest index of the array is for example 10 but the size is 11
    unsigned int sizeHigher = (size - rollingPivot-1); //find out size of lower partition, -1 so the Pivot wont be counted
    unsigned int offsetValue = rollingPivot+1; //Value that needs to be added to the indexes so only the upper portion is sorted

    //:default -----this variables are all for the default part of the switch statement
    unsigned  int newPivotIndex = 0; // new pivot will be saved here if one is needed
    int newPivotValue = 0; //new pivot value will be saved here
    unsigned int newInternalRollingPivot = 0; //Value witch tracks where the Pivot will land after the function


    switch (sizeHigher) { //switch case to determine action based on partition size
        case 0:
        case 1:*done = 1;
            break;
        case 2: //determine if elements in order, else swap

            if(*(arr + offsetValue) > *(arr + 1 + offsetValue)){
                swapi((arr + offsetValue), (arr + 1 + offsetValue));
                *done = 1;
                break;
            } else{
                *done = 1;
                break;
            }

        case 3:

            //first no smallest
            if((*(arr+offsetValue) <= *(arr+offsetValue+1)) && (*(arr+offsetValue) <= *(arr+offsetValue+2))) {
                if(*(arr+offsetValue+1) > *(arr+offsetValue+2)){
                    swapi((arr+offsetValue+1),(arr+offsetValue+2));
                }
                done = 1;
                break;
            }
            //second no smallest
            if((*(arr+offsetValue+1) <= *(arr+offsetValue)) && (*(arr+offsetValue+1) <= *(arr+offsetValue+2))) {
                swapi((arr + offsetValue), (arr + offsetValue+1));
                if (*(arr + offsetValue + 1) > *(arr + offsetValue + 2)) {
                    swapi((arr + offsetValue + 1), (arr + offsetValue + 2));
                }
                done = 1;
                break;
            }
            //third no smallest
            if((*(arr+offsetValue+2) <= *(arr+offsetValue)) && (*(arr+offsetValue+2) <= *(arr+offsetValue+1))) {
                swapi((arr + offsetValue), (arr + offsetValue+2));
                if (*(arr + offsetValue + 1) > *(arr + offsetValue + 2)) {
                    swapi((arr + offsetValue + 1), (arr + offsetValue));
                }
                done = 1;
                break;
            }


            //creating new partition if the number of left elements is larger then 3
        default:
            //The rightmost Pivot will always be chosen
            newPivotIndex = sizeHigher;
            newPivotValue = *(arr+sizeHigher);

//size is new Pivot index because the rightmost element is chosen

            //sortLowPartitionPivot(arr, newPivotIndex, newPivotValue, &newInternalRollingPivot);
            break;
    }//endswith
}//end sortHigher Function



//this function sorts around a new pivot if there are too many elements on the left side
void sortLowPartitionPivot(int *arr, unsigned int newPivotIndex, unsigned int newpivotValue, unsigned int *newrollingpivot, unsigned int leftborder) {
unsigned int internalRollingPivotCounter = 0;

    //int *tempArr = malloc(sizeof(int)*newPivotIndex); //temporary array to store the Values sorted in the lower Portion
int *tempArr = calloc(newPivotIndex+1,sizeof(int)); //temporary array to store the Values sorted in the lower Portion

    for (int i = 0; i < newPivotIndex; ++i) { //write lower values below index
    if(*(arr+i) <= newpivotValue && i != newPivotIndex){ //writing the smaller Values into the temporary Array
    *(tempArr+internalRollingPivotCounter) = *(arr+i);
    internalRollingPivotCounter++;
    }
    }

    //writing the temporary index into the spot after the lower values
    *(tempArr+internalRollingPivotCounter) = *(arr+newPivotIndex);
    *newrollingpivot = internalRollingPivotCounter;
    internalRollingPivotCounter++;

    for (int i = 0; i <= newPivotIndex; ++i) { //write higher values above Index
        if(*(arr+i) > newpivotValue && i != newPivotIndex){
            *(tempArr+internalRollingPivotCounter) = *(arr+i);
            internalRollingPivotCounter++;
        }

    }
    //TEST debug printfs
    printf("\nTEST sort Partition low Pivot\n");
    printf("the second Partitioned Pivot value  is: %i \n", newpivotValue);
    printf("the second Partitioned Pivot index  is: %i \n", *newrollingpivot);

    //for-loop to write tempArr values to arr
    for (int i = 0; i <= newPivotIndex; ++i) {
        *(arr+i) = *(tempArr+i);
    }


    free(tempArr);
}


//tis function sorts around a new pivot if there are too many elements on the right side
//rightborder is the last actual index
void sortHIGHPartitionPivot(int *arr, unsigned int newPivotIndex, unsigned int newpivotValue, unsigned int *newrollingpivot, unsigned int rightborder){
    unsigned int firstIndex = newPivotIndex+1;
    unsigned int lastIndex = rightborder;
    unsigned int internalRollingPivotCounter = newPivotIndex+1;

    //int *tempArr = malloc(sizeof(int)*newPivotIndex); //temporary array to store the Values sorted in the lower Portion
    int *tempArr = calloc(newPivotIndex+1,sizeof(int)); //temporary array to store the Values sorted in the lower Portion

    for (int i = newPivotIndex; i < rightborder; ++i) { //write lower values below index
        if(*(arr+i) <= newpivotValue && i != newPivotIndex){ //writing the smaller Values into the temporary Array
            *(tempArr+internalRollingPivotCounter) = *(arr+i);
            internalRollingPivotCounter++;
        }
    }

    //writing the temporary index into the spot after the lower values
    *(tempArr+internalRollingPivotCounter) = *(arr+newPivotIndex);
    *newrollingpivot = internalRollingPivotCounter;
    internalRollingPivotCounter++;

    for (int i = 0; i <= newPivotIndex; ++i) { //write higher values above Index
        if(*(arr+i) > newpivotValue && i != newPivotIndex){
            *(tempArr+internalRollingPivotCounter) = *(arr+i);
            internalRollingPivotCounter++;
        }

    }
    //TEST debug printfs
    printf("\nTEST sort Partition HIGH Pivot\n");
    printf("the second Partitioned high Pivot value  is: %i \n", newpivotValue);
    printf("the second Partitioned high Pivot index  is: %i \n", *newrollingpivot);

    //for-loop to write tempArr values to arr
    for (int i = firstIndex; i <= lastIndex; ++i) {
        *(arr+i) = *(tempArr+i);
    }


    free(tempArr);
}

//Experimental sort around borders function
//void sortNPartitionIteration(int *arr,unsigned int size,unsigned int firstElement,unsigned int lastElement, )

//todo leftbortder, rightborder implementation in sortHIGHLOWpartitonpivot