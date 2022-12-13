#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *genRandNum(int size, int *randArr){

    //define max upper and lower
    const int upper = 32767;
    const int lower = -32768;

    //integer for temporary storage of the generated number
    int num = 0;
    int i;

    for (i = 0; i < size; i++) {

        //calculate a random number | % = modulo
        num = (rand() % (upper - lower + 1) + lower / 2) * 2;

        //write random num to array
        randArr[i] = num;
    }

    return randArr;
}

