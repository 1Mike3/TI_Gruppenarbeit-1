//
// Created by osboxes on 02/01/23.
//
#include "allfunclib.h"
#include "binarySearchAlgorithm.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#include "generateRandomStruct.h"
#if 1//activateAllMain
int main(){

    struct data s1[401];
    int structDataCount = 400;
    genRanStruct(structDataCount, s1);

    for(int i=0; i<=structDataCount;i++){
        printf("%d %s | ", s1[i].number, s1[i].string);
    }

    int userInput;
    printf("\nEnter Integer: ");

    printf("\n");

   int returnIndex = binarySearchInteger(s1, -8, 0, 400);
    printf("\nThe Retutnindex is: %i", returnIndex);
}
#endif

/* VON MARKUS
//print data
void print_data(struct data data[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Number: %d, String: %s \n", data[i].number, data[i].string);
    }
}

 //sort the data by number
void sort_by_number(struct data data[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (data[j].number > data[j + 1].number) {
                struct data temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}


 //sort the data by string
void sort_by_string(struct data data[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (strcmp(data[j].string, data[j + 1].string) > 0) {
                struct data temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

 //random
int main() {
    struct data data[5];
    data[0].number = 5;
    strcpy(data[0].string, "Hello!");
    data[1].number = 2;
    strcpy(data[1].string, "THIS");
    data[2].number = 3;
    strcpy(data[2].string, "IS");
    data[3].number = 1;
    strcpy(data[3].string, "SPARTA");
        data[4].number = 4;
    strcpy(data[4].string, "!!!1!1!1");
    print_data(data, 5);
    sort_by_number(data, 5);
    print_data(data, 5);
    sort_by_string(data, 5);
    print_data(data, 5);
    return 0;
}

 */