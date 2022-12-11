//
// Created by Michi on 10.12.2022.
//
#include <stdio.h>
#include <time.h>
#include "..\include\allfunclib.h"
#include "stdlib.h"
#include "Stddef.h"


void selectSubFunction (char sortAlgName[], const int *sizeArr, int sizeNo, int call, int choseInit);
void initAscending (int *arr, unsigned int size);
void initDescending (int *arr, int size);
void printSortingMethod(int index);
void printArrSizesAndSortAlgUsed(char *algName);

//call sorting function 1 = mergesort, 2 = quicksort, 3 = Bubblesort, 4 = Insertion-sort
//sizeArr contains teh sizes of the arrays in the order they are passed thorough as parameters
//arraynumber = number of arrays in size arr
void benchmark1_2(int call){

    //selectInitialization 1 = ascending, 2 = descending, 3 = random generated
    int selectInitialization = 1;


    //arrays for the benchmark
    int arr8[8] = {0};
    int arr32[32] = {0};
    int arr128[128] = {0};
    int arr512[512] = {0};
    int arr2048[2048] = {0};
    int arr8192[8192] = {0};
    int arr32768[32768] = {0};
    const int size = 7;
    const int sizeArrPar[7] = {8,32,128,512,2048, 8192, 32768};



//strings for insertion into the sorting & output function
    char mergeSort[] = "MERGESORT";
    char quickSort[] = "QUICKSORT";
    char bubbleSort[] = "BUBBLESORT";
    char insertionSort[] = "INSERTION-SORT";

    //switch case for the different sorting algs.:
    //i will only explain what this stuff does in the first case
    switch (call) {

        //mergesort
        case 1:
            printArrSizesAndSortAlgUsed(mergeSort); //prints the Table header
            for (int i = 1; i < 4; ++i) {
                printSortingMethod(i); //Prints the used sorting method into the table
                selectSubFunction(mergeSort, sizeArrPar, size, call, i);
            }

            break;


            //quicksort
        case 2:
             printArrSizesAndSortAlgUsed(quickSort);
            for (int i = 1; i < 4; ++i) {
                printSortingMethod(i);
                selectSubFunction(quickSort, sizeArrPar, size, call,i );
            }


            break;
            //Bubblesort
        case 3:
            printArrSizesAndSortAlgUsed(bubbleSort);
            for (int i = 1; i < 4; ++i) {
                printSortingMethod(i);
                selectSubFunction(bubbleSort, sizeArrPar, size, call,i );
            }


            //Insertion-sort
            break;
        case 4:
            printArrSizesAndSortAlgUsed(insertionSort);
            for (int i = 1; i < 4; ++i) {
                printSortingMethod(i);
                selectSubFunction(insertionSort, sizeArrPar, size, call,i );
            }


            break;

        default:
            break;
    }

}//END Benchmark2_2 Call

//function which will be called in every switch-case to do the actual printing and sorting













void selectSubFunction(char *sortAlgName, const int *sizeArr, int sizeNo, int call,int choseInit) {
    clock_t t;


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
                break;
        }


//END####### Switch case for selection of initialization ############

        //printf("\nprintout %s sorted Array (SIZE: | %i |):\n", sortAlgName, *(sizeArr+i));

        switch(call){
            case 1:
                t = clock();
                mergeS(tempArr, 0, *(sizeArr+i));
                t = clock() - t;
                double time_taken = (((double)t)/CLOCKS_PER_SEC)*100000 ;
                printf("%f[ns]  ", time_taken);
                break;
            case 2:
              //  quickS(tempArr, *(sizeArr+i));
                break;
            case 3:
              //  bubbleS(tempArr, *(sizeArr+i));
                break;
            case 4:
              //  inserS(tempArr, *(sizeArr+i));
                break;
            default:
                break;
        }
/*
        printArr(tempArr, *(sizeArr+i));
        printf("Check if the array is correctly sorted:\n");
        checkSort(tempArr,*(sizeArr+i),1);
*/


    }//end main for loop
    printf("\n");

    free(tempArr);
}


/*
//generate random numbers
void fillArrWithRanNum(int size, int *randArr){
    //define upper and lower

}
*/



//sort array in ascending order
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

//sort array in descending order
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

void printArrSizesAndSortAlgUsed(char *algName){
    printf("\n###### %s-IMPLEMENTATION #####\n\n", algName);
    printf("The Array Sizes and their required sorting(%s) time with different initialization:\n", algName);
    printf("Size    :   8      32    128    512     2048       8192      32768\n");
}

void printSortingMethod(int index){
    switch (index) {
        case 1:
            printf("ascend. :    ");
            break;
        case 2:
            printf("descend.:    ");
            break;
        case 3:
            printf("random  :    ");
            break;
        default:
            break;
    }
}
/*
//calculate the time from bubblesorting() and print it
int time(){
    clock_t t;
    t = clock();
    //bubblesorting();
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("bubbleSort() took %f seconds to execute \n", time_taken);
    return 0;

}
*/

