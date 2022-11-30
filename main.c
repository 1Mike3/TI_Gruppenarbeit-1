#include <stdio.h>
#include "stdlib.h"
#include "time.h"

//include custom lib
#include "include/allfunclib.h"

int main() {

    int arr[2] = {};
    unsigned int size;

    mergeS(arr, size);
    quickS(arr, size);
    bubbleS(arr, size);
    inserS(arr, size);


    return 0;
}

