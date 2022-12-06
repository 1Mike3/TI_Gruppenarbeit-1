//
// Created by Emad on 30/11/2022.
//
//not finished: function which returns a random number on a selected range
#include <stdio.h>
#include <stdlib.h>
#include <time.h>




int *genRandNum(int size, int *randArr){

/* WORKS!!! DONT DELETE
    int randArr8[8] = { 0 };
    int randArr16[16] = { 0 };
    int randArr64[64] = { 0 };

    int upper = 32767;
    int lower = -32768;
    int num = 0;
    int i;

    for (i = 0; i < 8; i++) {
        //num = (rand() % (upper - lower + 1)) + lower;
        //num = (rand() % (upper * 2 + 1)) + lower;
        num = (rand() % (upper - lower + 1) + lower / 2) * 2;
        randArr8[i] = num;
    }
    for (i = 0; i < 16; i++) {
        //num = (rand() % (upper - lower + 1)) + lower;
        //num = (rand() % (upper *2 - lower  + 1) + lower) ;
        num = (rand() % (upper - lower + 1) + lower / 2) * 2;
        randArr16[i] = num;
    }
    for (i = 0; i < 64; i++) {
        //num = (rand() % (upper - lower + 1)) + lower;
        num = (rand() % (upper - lower + 1) + lower / 2) * 2;
        randArr64[i] = num;
    }
    //print them
    printf("Arr8 ");
    for (i = 0; i < 8; i++) {
        printf("%d ", randArr8[i]);
    }
    printf("\n");
    printf("Arr16 ");
    for (i = 0; i < 16; i++) {
        printf("%d ", randArr16[i]);
    }
    printf("\n");
    printf("Arr64 ");
    for (i = 0; i < 64; i++) {
        printf("%d ", randArr64[i]);
    }
    */



    int upper = 32767;
    int lower = -32768;
    int num = 0;
    int i;

    for (i = 0; i < size; i++) {
        //num = (rand() % (upper - lower + 1)) + lower;
        //num = (rand() % (upper * 2 + 1)) + lower;
        num = (rand() % (upper - lower + 1) + lower / 2) * 2;
        randArr[i] = num;
    }

    return randArr;
}