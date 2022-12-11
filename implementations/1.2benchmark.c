//
// Created by Kirari Momobami on 10.12.2022.
//
#include <stdio.h>
#include <time.h>

void bubbleSort(int *arr, unsigned int size){
    int i, j, tmp;
    for (i = 0; i < size - 1; i++){
        for (j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

//use void bubbleSort with an array of size 10 and print the array
int bubblesorting(){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;
    bubbleSort(arr, 10);
    for (i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
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
}
