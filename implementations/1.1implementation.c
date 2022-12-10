//
// Created by Michi on 10.12.2022.
//
#include "stdio.h"
#include "..\include\allfunclib.h"
//read in three arrays of sizes 8,16 and 64 and initialize them with random numbers
//call sorting function 1 = mergesort, 2 = quicksort, 3 = Bubblesort, 4 = Insertion-sort
//although obvious will pass size so easier adapting if requirements change
//sizeArr contains teh sizes of the arrays in the order they are passed thorough as parameters
void basicCheck1_1(int call, int *arr8, int *arr16, int*arr64, int *sizeArr){
//switch case for the different sorting algs.:
    switch (call) {
        //mergesort
        case 1:
/*
            printf("\n###### MERGESORT-IMPLEMENTATION #####\n\n");
            printf("printout randomly initialized Array:\n");
            genRandNum(*(sizeArr+0),arr8) ;
            printArr(arr8, *(sizeArr+0));
            printf("printout mergesort sorted Array:\n");
            mergeS(arr8, *(sizeArr+0));
            printArr(arr8, *(sizeArr+0));
            printf("Check if the array is correctly sorted:\n");
            checkSort(arr8,*(sizeArr+0),1);
          //  printf("before emad randnum\n");
          //  printArr(arr8, 8);

          //  printf("after emad randnum \n");
           // printArr(arr8, 8);

        break;
             */

        //quicksort
        case 2:

            printf("\n###### Quicksort-IMPLEMENTATION #####\n\n");
            printf("printout randomly initialized Array:\n");
            int arr8test[8] = {2,4,7,2,8,5,3,3,};
            genRandNum(*(sizeArr+0),arr8) ;
            printArr(arr8test, 8);
            printf("printout quicksort sorted Array:\n");
            quickS(arr8test, 8);
            printArr(arr8test, 8);
            printf("Check if the array is correctly sorted:\n");
            checkSort(arr8test,8,1);



        break;
        //Bubblesort
        case 3:
/*
            printf("\n###### BUBBLESORT-IMPLEMENTATION #####\n\n");
            printf("printout randomly initialized Array:\n");
            genRandNum(*(sizeArr+0),arr8) ;
            printArr(arr8, *(sizeArr+0));
            printf("printout Bubblesort sorted Array:\n");
            bubbleS(arr8, 8);
            printArr(arr8, *(sizeArr+0));
            printf("Check if the array is correctly sorted:\n");
            checkSort(arr8,*(sizeArr+0),1);
*/
        //Insertion-sort
        break;
        case 4:
/*
            printf("\n###### INSERTIONSORT-IMPLEMENTATION #####\n\n");
            printf("printout randomly initialized Array:\n");
            genRandNum(*(sizeArr+0),arr8) ;
            printArr(arr8, *(sizeArr+0));
            printf("printout INSERTIONSORT sorted Array:\n");
            inserS(arr8, 8);
            printArr(arr8, *(sizeArr+0));
            printf("Check if the array is correctly sorted:\n");
            checkSort(arr8,*(sizeArr+0),1);
*/
        break;

        default:
            break;
    }

}//END Basic1.1 Call