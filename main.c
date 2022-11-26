#include <stdio.h>
#include <stdlib.h>

void print_2d_array( int rows, int cols, int *arr){


    for (int i = 0; i < rows ; ++i) {
        printf("\n");


        for (int j = 0; j < cols; ++j) {
            printf("%d  ", *(arr+i*cols+j));
        }
    }

}


void Pointerswitch(int *a, int *b){

}


int main() {
    int a = 4;
    int b = 5;
    int matrix[4][2] = {{1, 2},
                         {3, 4},
                        {5, 6},
                         {7, 8}};

   // print_2d_array(4,2, matrix);
    Pointerswitch( &a ,&b);


    return 0;
}


