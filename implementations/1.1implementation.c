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
            printf("\n###### MERGESORT-IMPLEMENTATION #####\n\n");
            printf("printout randomly initialized Array:\n");
            genRandNum(*(sizeArr+0),arr8) ;
            printRandArr(arr8, *(sizeArr+0));
            printf("printout mergesort sorted Array:\n");
            mergeS(arr8, *(sizeArr+0));
            printRandArr(arr8, *(sizeArr+0));
          //  printf("before emad randnum\n");
          //  printArr(arr8, 8);

          //  printf("after emad randnum \n");
           // printArr(arr8, 8);
            mergeS(arr8, *(sizeArr+0));
        break;
        //quicksort
        case 2:
        break;
        //Bubblesort
        case 3:
        //Insertion-sort
        break;
        case 4:
        break;

        default:
            break;
    }

}//END Basic1.1 Call