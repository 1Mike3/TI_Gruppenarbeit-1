//
// Created by Kirari Momobami on 10.12.2022.
//
#include <stdio.h>
#include <time.h>
#include "..\include\allfunclib.h"

//many arrays for the benchmark
int arr8[8] = {0};
int arr32[32] = {0};
int arr128[128] = {0};
int arr512[512] = {0};
int arr2048[2048] = {0};
int arr8192[8192] = {0};
int arr32768[32768] = {0};

//generate random numbers
void genRandNum(int size, int *randArr){
    //define upper and lower
    int upper = 32767;
    int lower = -32768;
    int num = 0;
    int i;
    for (i = 0; i < size; i++) {
        num = (rand() % (upper - lower + 1) + lower / 2) * 2;
        randArr[i] = num;
    }
}

//sort array in ascending order
void arrayUp (int *arr, unsigned int size){
    int i, j, temp;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (*(arr+j) > *(arr+j+1)) {
                int temp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
            }
        }
    }
}

//sort array in descending order
void arrayDown (int *arr, unsigned int size){
    int i, j, temp;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (*(arr+j) < *(arr+j+1)) {
                int temp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
            }
        }
    }
<<<<<<< HEAD:implementations/1.2benchmark.c
    return 0;
}


//calculate the time from bubblesorting() and print it
int main(){
    clock_t t;
    t = clock();
    bubblesorting();
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("bubbleSort() took %f seconds to execute \n", time_taken);
    return 0;
=======
>>>>>>> 59b771949312e5f76865aab415715cf7a717ed41:implementations/1.2_benchmark.c
}

