//
// Created by Emad on 30/11/2022.
//
//Emad finished ============DONT CHANGE!!!
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *genRandNum(int size, int *randArr){

    //define upper and lower
    int upper = 32767;
    int lower = -32768;
    int num = 0;
    int i;

    for (i = 0; i < size; i++) {
        num = (rand() % (upper - lower + 1) + lower / 2) * 2;
        randArr[i] = num;
    }

    return randArr;
}

