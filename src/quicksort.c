//
// Created by Michi on 30.11.2022.
//My Implementation of the quicksort algorithm
//

//STATUS Build in progress

#include "C:\Users\Michi\CLionProjects\Gruppenarbeit_TI\include\allfunclib.h"
#include "stdio.h"

//define the lowest accepted division
#define  mindiv 3


//TODO create error code for different runtime problems /errors
//TODO implement a check function to truly know if the array is sorted
//TODO make a shell script on anuminas which fethes the .c , compiles it and checks it with valgrind

//Used sub-functions, (further infos over implementation):
void pivotSide(int pivot,int * arr, unsigned int size,int pivInd, int *rollPivInd);
void checkWhereNextPivot(unsigned int size,int *rollPivInd,int status);

//Qicksortfunction, entered array will be sorted using the quicksort-alg
//"arr" is the chosen array of any size (edgecase size 0 behavior?)
// "size" is the value of the chosen array
void quickS (int *arr, unsigned int size){
int first = arr[0], last = arr[(size-1)], temp = 0, pivot = 0, initPivotindex = 0, rollingPivotIndex = 0;

//0 == not executed, 1 = netxt Pivot chosen; 2 = function decided no further pivot placement neccesary
int checkWhNxtPivStatus = 0; //Statuscode for te status of the "checkWhereNextPivot" function
short int lSideDone = 0; //if 1: no further sorting needed on the left side
short int rSideDone = 0; //if 1: no further sorting needen on the right side


//''''''''''''''''''''''Chosing the Pivot''''''''''''''''''''''''''''''
//for now i will just select the first element, might change later

initPivotindex = 4;
pivot = *(arr + initPivotindex); //plus initPivotindex so i can change it later easily


//TEST Printf-function for test purposes, delete later
    printf("My Pivot is: %i, at Index: %i\n", pivot, initPivotindex);
//END''''''''''''''''''''''Chosing the Pivot''''''''''''''''''''''''''''''

//sort around first pivot
    pivotSide(pivot, arr, size,initPivotindex, &rollingPivotIndex);

    //TEST
    printf("My new Pivot is: %i, \n", rollingPivotIndex);





}


//pivotside function which puts the values lower than the pivot left of it,
//and values higher than the pivot right of it
//NOTE equal to pivot written on the left side of the pivot
//TODO test with equal values & edgecases

//    pivot, the unsorted array,size of the array,index of pivot bef. function,index of pivot aft. function
void pivotSide(int pivot ,int * arr, unsigned int size,int pivInd, int *rollPivInd){
int tempArr[12] = {0,0}; //temporary working array, will be written into *arr at the end of the function
    unsigned int tempRollingIndex = 0; //counter used for writing the values into the correct array index

    for (int i = 0; i < size; i++) { //insert lesser/equal then pivot
        if ((*(arr + i) <= pivot) && (i != pivInd)) {
            *(tempArr + tempRollingIndex) = *(arr + i);
            tempRollingIndex++;
        }
    }

//insert pivot into half sorted array
*(tempArr + tempRollingIndex) = pivot;
    *rollPivInd = tempRollingIndex;
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
}//END Pivotside Function


//this function decides where to put the next pivot
void checkWhereNextPivot(unsigned int size,int *rollPivInd, int status){

}