//
// Created by Michi on 10.12.2022.
//
#include <stdio.h>
#include <time.h>
#include "..\include\allfunclib.h"
#include "stdlib.h"


void printAndSort2 (char sortAlgName[],const int *sizeArr, int sizeNo, int call);

//arrays for the benchmark
int arr8[8] = {0};
int arr32[32] = {0};
int arr128[128] = {0};
int arr512[512] = {0};
int arr2048[2048] = {0};
int arr8192[8192] = {0};
int arr32768[32768] = {0};


//call sorting function 1 = mergesort, 2 = quicksort, 3 = Bubblesort, 4 = Insertion-sort
//sizeArr contains teh sizes of the arrays in the order they are passed thorough as parameters
//arraynumber = number of arrays in size arr
void benchmark1_2(int call,const int *sizeArr, int arrayNumber){

//strings for insertion into the sorting & output function
    char mergeSort[] = "MERGESORT";
    char quickSort[] = "QUICKSORT";
    char bubbleSort[] = "BUBBLESORT";
    char insertionSort[] = "INSERTION-SORT";

    //switch case for the different sorting algs.:
    switch (call) {
        //mergesort
        case 1:
            //  printAndSort2(mergeSort, sizeArr ,arrayNumber,call);
            break;


            //quicksort
        case 2:
            //the commented-out block below works, will keep if need to go back
/*
            printf("\n###### %s-IMPLEMENTATION #####\n\n", quickSort);
            printf("printout randomly initialized Array (SIZE: | %i |):\n",*(sizeArr+0));
            genRandNum(*(sizeArr+0),arr8) ;
            printArr(arr8, *(sizeArr+0));
            printf("printout %s sorted Array (SIZE: | %i |):\n", quickSort, *(sizeArr+0));
            quickS(arr8, *(sizeArr+0));
            printArr(arr8, *(sizeArr+0));
            printf("Check if the array is correctly sorted:\n");
            checkSort(arr8,*(sizeArr+0),1);
*/
            printAndSort2(quickSort, sizeArr ,arrayNumber,call);

            break;
            //Bubblesort
        case 3:
            printAndSort2(bubbleSort, sizeArr ,arrayNumber,call);


            //Insertion-sort
            break;
        case 4:

            printAndSort2(insertionSort, sizeArr ,arrayNumber,call);

            break;

        default:
            break;
    }

}//END Basic1.1 Call

//function which will be called in every switch-case to do the actual printing and sorting


void printAndSort2(char *sortAlgName,const int *sizeArr, int sizeNo, int call) {
    printf("\n###### %s-IMPLEMENTATION #####\n\n", sortAlgName);

    //the size of tempArr will be dyn. alloc. depending on the size of the current working arr
    int *tempArr = malloc(sizeof(int) * *(sizeArr+0));
    for (int i = 0; i < sizeNo; ++i) {
        if(i >= 1){
            tempArr = realloc(tempArr, sizeof (int )* *(sizeArr+i));
        }

        printf("printout randomly initialized Array (SIZE: | %i |):\n",*(sizeArr+i));
        genRandNum(*(sizeArr+i),tempArr) ;
        printArr(tempArr, *(sizeArr+i));
        printf("\nprintout %s sorted Array (SIZE: | %i |):\n", sortAlgName, *(sizeArr+i));

        switch(call){
            case 1:
                //mergeS(tempArr, *(sizeArr+i));
                break;
            case 2:
                quickS(tempArr, *(sizeArr+i));
                break;
            case 3:
                bubbleS(tempArr, *(sizeArr+i));
                break;
            case 4:
                inserS(tempArr, *(sizeArr+i));
                break;
            default:
                break;
        }

        printArr(tempArr, *(sizeArr+i));
        printf("Check if the array is correctly sorted:\n");
        checkSort(tempArr,*(sizeArr+i),1);

        printf("\n\n");
    }//end main for loop


    free(tempArr);
}


/*
//generate random numbers
void fillArrWithRanNum(int size, int *randArr){
    //define upper and lower

}
*/



//sort array in ascending order
void arrayUp (int *arr, unsigned int size){
    int i, j, temp;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (*(arr+j) > *(arr+j+1)) {
                int temp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
            }
        }
    }
}

//sort array in descending order
void arrayDown (int *arr, int size){
    int i, j, temp;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (*(arr+j) < *(arr+j+1)) {
                int temp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
            }
        }
    }

}

/*
//calculate the time from bubblesorting() and print it
int main(){
    clock_t t;
    t = clock();
    bubblesorting();
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("bubbleSort() took %f seconds to execute \n", time_taken);
    return 0;

}
*/


void initializeArray (){

}
