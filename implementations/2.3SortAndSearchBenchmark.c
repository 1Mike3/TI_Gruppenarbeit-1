//
// Created by osboxes on 16/01/23.
//
#include "generateRandomStruct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "quicksortInt.h"
#include "binarySearchAlgorithm.h"

//generate a random struct with given elements
void genRanBigStruct(int valuesCount, struct data workingStruct[]){
    for(int i=0; i < valuesCount; i++) {
        workingStruct[i].number = randNumReturn(3000,0);
        char randomletter[6]={};
        for(int c=0; c<5; c++){

            randomletter[c] = 'a' + (rand() % 26);
        }

        strcpy(workingStruct[i].string, randomletter);
    }

}

//compare function for the qsort to use
int cmpStruct(const void *a, const void *b) {
    struct data *ia = (struct data *)a;
    struct data *ib = (struct data *)b;
    return (ia->number - ib->number);
}
#if 1

int main() {
    //set seed for rand funcion
    srand(time(NULL));
    int matchescounter = 0;
    int printingSize = 100;
    int tempArraySize = 500;
    int structDataCount = 30000;
    //allocate memory for temporary array
    int *tempArr = malloc((sizeof(int) * tempArraySize));
    if(tempArr == NULL){
        printf("error Malloc 1");
        exit(1);
    }
    printf("=============================================LIB FUNCTIONS BEG =============================================\n");

    //generate given number of random positive numbers in the array
    genRandPosNum(tempArraySize,tempArr,5000);
    //create structure
    struct data workingStruct[structDataCount];
    //fill structure with random values
    genRanBigStruct(structDataCount, workingStruct);

    printf("\n=========UNSORTED========\n");
    for (int i = 0; i < printingSize; i++) {
        printf("[i:%-3d] %-5d %s | ",i, workingStruct[i].number, workingStruct[i].string);
        if((i+1)%5 == 0)
            printf("\n");

    }
    printf("\n=========END UNSORTED========\n");

    //measure time taken
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    //use lib qsort to sort the first struct
    qsort(workingStruct,structDataCount,sizeof(struct data), cmpStruct);
    //for every element in the array search the struct
    for(int i=0; i < tempArraySize; i++){
        //create a temporary struct to store the found element and fill it with the return of the binarysearch lib function
        struct data* structIndex = bsearch(&tempArr[i], workingStruct, structDataCount, sizeof(struct data), cmpStruct);
        //handle the output depending on what has been found
        if (structIndex != NULL) {
            matchescounter++;
        }
    }
    end = clock();
    //calculate time taken
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\n=========SORTED========\n");
    for (int i = 0; i < printingSize; i++) {
        printf("[i:%-3d] %-5d %s | ",i, workingStruct[i].number, workingStruct[i].string);
        if((i+1)%5 == 0)
            printf("\n");

    }
    printf("\n=========END SORTED========\n");
    printf("Time taken by library functions: %f\n", cpu_time_used);
    printf("Found %d matches.\n", matchescounter);
    printf("=============================================LIB FUNCTIONS END =============================================\n");

    printf("=============================================OWN FUNCTIONS BEG =============================================\n");

    //regenerate structure
    genRanBigStruct(structDataCount, workingStruct);

    printf("\n=========UNSORTED========\n");
    for (int i = 0; i < printingSize; i++) {
        printf("[i:%-3d] %-5d %s | ",i, workingStruct[i].number, workingStruct[i].string);
        if((i+1)%5 == 0)
            printf("\n");

    }
    printf("\n=========END UNSORTED========\n");

    //measure time taken
    start = clock();
    //sort struct with our own quicksort
    quickSortInt(workingStruct, structDataCount);
    matchescounter = 0;
    //for every element in the array search the struct
    for(int i=0; i < tempArraySize; i++){
        int returnIndex = binarySearchInteger(workingStruct, tempArr[i], 0, structDataCount);
        if(returnIndex >= 0){
            matchescounter++;
        }
    }
    end = clock();
    //calculate time taken
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\n=========SORTED========\n");
    for (int i = 0; i < printingSize; i++) {
        printf("[i:%-3d] %-5d %s | ",i, workingStruct[i].number, workingStruct[i].string);
        if((i+1)%5 == 0)
            printf("\n");

    }
    printf("\n=========END SORTED========\n");
    printf("Time taken by our functions: %f\n", cpu_time_used);
    printf("Found %d matches.\n", matchescounter);
    printf("=============================================OWN FUNCTIONS END =============================================\n");

    //free allocated memory
    free(tempArr);
    return 0;
}


#endif

