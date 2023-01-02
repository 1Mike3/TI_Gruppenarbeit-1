#include <stdio.h>

//takes two values in the array, compares them and swaps them if the first value is larger than the second value
void bubbleS (int *arr, int size){
    int i, j, temp;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (*(arr+j) > *(arr+j+1)) {    //if the first value is larger than the second value
                temp = *(arr+j);            //swap the values
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
            }
        }
    }
}
