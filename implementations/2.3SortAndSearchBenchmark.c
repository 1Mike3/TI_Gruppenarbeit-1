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

//generate a random struct with 30000 elements
//the max length of the string is 10
//the max value of the integer is 500

int genRanBigStruct(int valuesCount, struct data workingStruct[]){
    for(int i=0; i < valuesCount; i++) {
        workingStruct[i].number = randNumReturn(3000,0);
        //workingStruct[i].number = i;
        char randomletter[6]={};
        for(int c=0; c<5; c++){

            randomletter[c] = 'a' + (rand() % 26);
        }

        strcpy(workingStruct[i].string, randomletter);
    }

}

int cmpStruct(const void *a, const void *b) {
    struct data *ia = (struct data *)a;
    struct data *ib = (struct data *)b;
    return (ia->number - ib->number);
}

int main() {
    srand(time(NULL));
    int matchescounter = 0;
    int printingSize = 100;
    int tempArraySize = 500;
    int structDataCount = 30000;
    int *tempArr = malloc((sizeof(int) * tempArraySize));
    if(tempArr == NULL){
        printf("error Malloc 1");
        exit(1);
    }
    printf("=============================================LIB FUNCTIONS BEG =============================================\n");
    genRandPosNum(tempArraySize,tempArr,5000);
    struct data workingStruct[structDataCount];
    genRanBigStruct(structDataCount, workingStruct);
    printf("\n=========UNSORTED========\n");
    for (int i = 0; i < printingSize; i++) {
        printf("[i:%-3d] %-5d %s | ",i, workingStruct[i].number, workingStruct[i].string);
        if((i+1)%5 == 0)
            printf("\n");

    }
    printf("\n=========END UNSORTED========\n");
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    qsort(workingStruct,structDataCount,sizeof(struct data), cmpStruct);
    for(int i=0; i < tempArraySize; i++){
        //create a temporary struct to store the found element and fill it with the return of the binarysearch lib function
        struct data* structIndex = bsearch(&tempArr[i], workingStruct, structDataCount, sizeof(struct data), cmpStruct);
        //handle the output depending on what has been found
        if (structIndex != NULL) {
            matchescounter++;
        }
    }
    end = clock();
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
    struct data workingStruct2[structDataCount];
    genRanBigStruct(structDataCount, workingStruct2);
    printf("\n=========UNSORTED========\n");
    for (int i = 0; i < printingSize; i++) {
        printf("[i:%-3d] %-5d %s | ",i, workingStruct2[i].number, workingStruct2[i].string);
        if((i+1)%5 == 0)
            printf("\n");

    }
    printf("\n=========END UNSORTED========\n");
    start = clock();
    quickSortInt(workingStruct2, structDataCount);
    matchescounter = 0;
    for(int i=0; i < tempArraySize; i++){
        int returnIndex = binarySearchInteger(workingStruct2, tempArr[i], 0, structDataCount);
        if(returnIndex >= 0){
            matchescounter++;
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\n=========SORTED========\n");
    for (int i = 0; i < printingSize; i++) {
        printf("[i:%-3d] %-5d %s | ",i, workingStruct2[i].number, workingStruct2[i].string);
        if((i+1)%5 == 0)
            printf("\n");

    }
    printf("\n=========END SORTED========\n");
    printf("Time taken by our functions: %f\n", cpu_time_used);
    printf("Found %d matches.\n", matchescounter);
    printf("=============================================OWN FUNCTIONS END =============================================\n");
    return 0;
}




