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

int genRanStruct(int valuesCount, struct data workingStruct[]) {
    int i;
    for (i = 0; i < valuesCount; i++) {
        workingStruct[i].number = rand() % 500;
        int j;
        for (j = 0; j < 5; j++) {
            workingStruct[i].string[j] = (char) (rand() % 26 + 65); //ASCII 65-90 = A-Z
        }
    }
    return 0;
}

int compare(const void *a, const void *b)
{
    struct data *ia = (struct data *)a;
    struct data *ib = (struct data *)b;
    return ia->number - ib->number;
}

int main() {
    struct data workingStruct[30000];
    genRanStruct(30000, workingStruct);
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    qsort(workingStruct, 30000, sizeof(struct data), compare);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by qsort: %f\n", cpu_time_used);

    start = clock();
   // quicksort(workingStruct, 0, 30000);
   //sortieren von integern -Michi
    quickSortInt(workingStruct, 3000);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by quicksort: %f\n", cpu_time_used);
    return 0;
}




