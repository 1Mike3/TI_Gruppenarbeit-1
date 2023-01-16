//
// Created by osboxes on 16/01/23.
//
#include "generateRandomStruct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "quicksortInt.h"

//generate a random struct with 30000 elements
//the max length of the string is 10
//the max value of the integer is 500

int genRanBigStruct(int valuesCount, struct data workingStruct[]) {
    int i;
    for (i = 0; i < valuesCount; i++) {
        workingStruct[i].number = randNumReturn(3000,0);
        int j;
        for (j = 0; j < 5; j++) {
            workingStruct[i].string[j] = (char) ('a' + (rand() % 26));
        }
    }
    return 0;
}

int cmpStruct(const void *a, const void *b) {
    struct data *ia = (struct data *)a;
    struct data *ib = (struct data *)b;
    return (ia->number - ib->number);
}

int main() {

    int tempArraySize = 500;
    int structDataCount = 30000;
    int *tempArr = malloc((sizeof(int) * tempArraySize));
    if(tempArr == NULL){
        printf("error Malloc 1");
        exit(1);
    }
    genRandPosNum(tempArraySize,tempArr);
    for(int i=0; i < tempArraySize; i++){
        printf("%d ", tempArr[i]);
    }
    struct data workingStruct[structDataCount];
    genRanBigStruct(structDataCount, workingStruct);
    printf("\n=========UNSORTED========\n");
    for (int i = 0; i < 100; i++) {
        printf("[i:%-3d] %-5d %s | ",i, workingStruct[i].number, workingStruct[i].string);
        if((i+1)%5 == 0)
            printf("\n");

    }
    printf("\n=========END UNSORTED========\n");
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    qsort(workingStruct,structDataCount,sizeof(struct data), cmpStruct);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by qsort: %f\n", cpu_time_used);
    start = clock();
    quickSortInt(workingStruct, structDataCount);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by quicksort: %f\n", cpu_time_used);
    return 0;
}




