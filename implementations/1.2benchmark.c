//
// Created by Michi on 10.12.2022.
//
#include <stdio.h>
#include <time.h>
#include "..\include\allfunclib.h"
#include "stdlib.h"


void selectSubFunction (char sortAlgName[], const int *sizeArr, int sizeNo, int call, int choseInit);





//call sorting function 1 = mergesort, 2 = quicksort, 3 = Bubblesort, 4 = Insertion-sort
//sizeArr contains teh sizes of the arrays in the order they are passed thorough as parameters
//arraynumber = number of arrays in size arr
void benchmark1_2(int call){

    //selectInitialization 1 = ascending, 2 = descending, 3 = random generated
    int selectInitialization = 1;
    printf("\n======###### BENCHMARK TEST 1.2 #####=======\n\n");

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
    switch (call) {
        //mergesort
        case 1:
            selectSubFunction(mergeSort, sizeArrPar, size, call, 1);
            break;


            //quicksort
        case 2:

            selectSubFunction(quickSort, sizeArrPar, size, call,1 );

            break;
            //Bubblesort
        case 3:
            selectSubFunction(bubbleSort, sizeArrPar, size, call,1 );


            //Insertion-sort
            break;
        case 4:

            selectSubFunction(insertionSort, sizeArrPar, size, call,1 );

            break;

        default:
            break;
    }

}//END Benchmark2_2 Call

//function which will be called in every switch-case to do the actual printing and sorting


void selectSubFunction(char *sortAlgName, const int *sizeArr, int sizeNo, int call,int choseInit) {


    printf("\n###### %s-IMPLEMENTATION #####\n\n", sortAlgName);
//########## Switch case for selection of initialization ############



//END####### Switch case for selection of initialization ############
    //the size of tempArr will be dyn. alloc. depending on the size of the current working arr
    int *tempArr = malloc(sizeof(int) * *(sizeArr+0));
    for (int i = 0; i < sizeNo; ++i) {
        if(i >= 1){
            tempArr = realloc(tempArr, sizeof (int )* *(sizeArr+i));
        }


        genRandNum(*(sizeArr+i),tempArr) ;

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
