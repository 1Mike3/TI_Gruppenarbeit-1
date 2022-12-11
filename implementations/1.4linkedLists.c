//
// Created by Michi on 11.12.2022.
//
#include <stdio.h>
#include <time.h>
#include "..\include\allfunclib.h"
#include "stdlib.h"

void compareLinkedList() {

    clock_t t;
    t = clock();
    basicCheck1_1(3, arrSizePar, 3);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("inserS() took %f seconds to execute \n", time_taken);
    return 0;

}