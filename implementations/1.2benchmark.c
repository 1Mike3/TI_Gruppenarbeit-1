//
// Created by Michi on 10.12.2022.
//
#include <stdio.h>
#include <time.h>
#include "..\include\allfunclib.h"
#include "stdlib.h"


//function declarations, further information at definition
void selectSubFunction (const int *sizeArr, int sizeNo, int call, int choseInit);
void initAscending (int *arr, unsigned int size);
void initDescending (int *arr, int size);
void printSortingMethod(int index);
void printArrSizesAndSortAlgUsed(char *algName);
void timeMeasuringFixer();

//call sorting function 1 = mergesort, 2 = quicksort, 3 = Bubblesort, 4 = Insertion-sort
//chose init(further down): 1 = ascending, 2 = descending, 3 = random
void benchmark1_2(int call){
    //noSize = the number of different array sizes
    const int noSize = 7;
    //sizeArrPar = Array which contains the array-sizes which will be used for the tests
    const int sizeArrPar[7] = {8,32,128,512,2048, 8192, 32768};



//strings for insertion into the sorting & output function
    char mergeSort[] = "MERGESORT";
    char quickSort[] = "QUICKSORT";
    char bubbleSort[] = "BUBBLESORT";
    char insertionSort[] = "INSERTION-SORT";

    //switch case for the different sorting algs.:
    //i will only explain what this stuff does in the first case
    switch (call) {

        //#######MERGE-SORT#######

        case 1:
            printArrSizesAndSortAlgUsed(mergeSort); //prints the Table header
            for (int i = 1; i < 4; ++i) { //for loop which selects the three different types of array initialization (choseInit)
                printSortingMethod(i); //Prints the used sorting method into the table
                //subfunction: contains initialization, sorting, time-measurement and printing
                //(some of the tasks are outsourced to smaller functions which are defined below)
                selectSubFunction( sizeArrPar, noSize, call, i);
            }

            break;


            //######QUICK-SORT########

        case 2:
             printArrSizesAndSortAlgUsed(quickSort);
            for (int i = 1; i < 4; ++i) {
                printSortingMethod(i);
                selectSubFunction( sizeArrPar, noSize, call, i );
            }


            break;
            //#######BUBBLE-SORT#######

        case 3:
            printArrSizesAndSortAlgUsed(bubbleSort);
            for (int i = 1; i < 4; ++i) {
                printSortingMethod(i);
                selectSubFunction( sizeArrPar, noSize, call, i );
            }


            //#######INSERTION-SORT########

            break;
        case 4:
            printArrSizesAndSortAlgUsed(insertionSort);
            for (int i = 1; i < 4; ++i) {
                printSortingMethod(i);
                selectSubFunction(sizeArrPar, noSize, call, i );
            }


            break;

        default:
            printf("well... if you're here you did something wrong :(  (switch call)");
            break;
    }

}//END Benchmark2_2 Call



//function which will be called in every switch-case, main function to do the actual printing and sorting
void selectSubFunction(const int *sizeArr, int sizeNo, int call,int choseInit) {
    clock_t t;
    double time_taken;

    //the size of tempArr will be dyn. alloc. depending on the size of the current working arr
    int *tempArr = malloc(sizeof(int) * *(sizeArr+0));
    for (int i = 0; i < sizeNo; ++i) {
        if(i >= 1){
            tempArr = realloc(tempArr, sizeof (int )* *(sizeArr+i));
        }

        //########## Switch case for selection of initialization ############
                switch (choseInit) {
                    case 1:
                        //printf("The Initialization will be done in an ASCENDING:\n");
                        initAscending(tempArr, *(sizeArr+i));
                        break;
                    case 2:
                       // printf("The Initialization will be done in an DESCENDING order:\n");
                        initDescending(tempArr, *(sizeArr+i));
                        break;

                    case 3:
                        //printf("The Initialization will be done using RANDOM numbers:\n");
                        genRandNum(*(sizeArr+i),tempArr);
                break;

                default:
                    printf("well... if you're here you did something wrong :(  (switch chose int)");
                break;
        }

        //END####### Switch case for selection of initialization ############


//the call of the sorting algs. in the main for loop
        switch(call){
            case 1:
                t = clock();
                mergeS(tempArr, 0, *(sizeArr+i));
                timeMeasuringFixer();
                t = clock() - t;
                time_taken = (((double)t)/CLOCKS_PER_SEC)*1000 ;
                if(time_taken < 1){
                    printf("t < 1ms     "); // Print if time is less then 1ms
                } else{
                    printf("%07.0f     ", time_taken); //Print if time is larger then 1ms
                }

                break;
            case 2:

                t = clock();
                quickS(tempArr, *(sizeArr+i));
                timeMeasuringFixer();
                t = clock() - t;
                time_taken = (((double)t)/CLOCKS_PER_SEC)*1000 ;
                if(time_taken < 1){
                    printf("t < 1ms     "); // Print if time is less then 1ms
                } else{
                    printf("%07.0f     ", time_taken); //Print if time is larger then 1ms
                }

                break;
            case 3:

                t = clock();
                bubbleS(tempArr, *(sizeArr+i));
                timeMeasuringFixer();
                t = clock() - t;
                time_taken = (((double)t)/CLOCKS_PER_SEC)*1000 ;
                if(time_taken < 1){
                    printf("t < 1ms     "); // Print if time is less then 1ms
                } else{
                    printf("%07.0f     ", time_taken); //Print if time is larger then 1ms
                }

                break;
            case 4:

                t = clock();
                inserS(tempArr, *(sizeArr+i));
                timeMeasuringFixer();
                t = clock() - t;
                time_taken = (((double)t)/CLOCKS_PER_SEC)*1000 ;
                if(time_taken < 1){
                    printf("t < 1ms     "); // Print if time is less then 1ms
                } else{
                    printf("%07.0f     ", time_taken); //Print if time is larger then 1ms
                }

                break;
            default:
                break;
        }


    }//end main for loop

    //lonely printf :)
    printf("\n");

    //free the dynamically allocated Memory
    free(tempArr);
}




//initialize array in ascending order
void initAscending (int *arr, unsigned int size){
    int i, j;
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

//initialize array in descending order
void initDescending (int *arr, int size){
    int i, j;
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

//Print the Head of the Table
void printArrSizesAndSortAlgUsed(char *algName){
    printf("\n###### %s-IMPLEMENTATION #####\n\n", algName);
    printf("The Array Sizes and their required sorting(%s) time with different initialization:\n", algName);
    printf("Size        :       8          32          128         512        2048        8192        32768\n");
}
//only used for the Printing of the lower descriptors of the Tables
void printSortingMethod(int index){
    switch (index) {
        case 1:
            printf("ascend. [ms]:    ");
            break;
        case 2:
            printf("descend.[ms]:    ");
            break;
        case 3:
            printf("random  [ms]:    ");
            break;
        default:
            break;
    }
}

//inserts a small delay so no bug in time measurement
void timeMeasuringFixer(){
    int a = 3,b = 2,c = 1;
    for (int i = 0; i < 1000; ++i) {
        c = a+i;
        a = b+i;
        b = c+i;
    }
}

