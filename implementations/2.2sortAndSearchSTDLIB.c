//
// Created by osboxes on 02/01/23.
//
#include "binarySearchAlgorithm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quicksortString.h"
#include "generateRandomStruct.h"

#if 1

int main() {
    int exit = 0;
    while(!exit){
        struct data s1[40];  //Emad old 401
        int structDataCount = 40; //Emad old 400
        genRanStruct(structDataCount, s1);
        int choice = 0;
        printf("\n\nPlease enter the number of choice.\n");
        printf("1. Search integer\n");
        printf("2. Quit\n");
        scanf("%d", &choice);
        int userInput=-1;
        switch (choice) {
            case 1:
                printf("\n=========UNSORTED========\n");
                for (int i = 0; i < structDataCount; i++) {
                    printf("%d %s | ", s1[i].number, s1[i].string);
                    if(i%5 == 0)
                        printf("\n");

                }
                printf("\n=========END UNSORTED========\n");
                printf("\nEnter number: ");
                scanf("%d", userInput);
                printf("\n");

                printf("\n=========SORTED========\n");
                for (int i = 0; i < structDataCount; i++) {
                    printf(" [i:%d] %d %s | ", i,s1[i].number, s1[i].string);
                    if(i%5 == 0)
                        printf("\n");

                }
                printf("\n ========= END SORTED========\n");
                /*
                int returnIndex = binarySearchString(s1, userInput, 0, structDataCount);
                if(returnIndex >= 0){
                    int foundValue = s1[returnIndex].number;
                    printf("\nThe Returnindex is: %i", returnIndex);
                    printf("\nThe value for the index is: %d", foundValue);
                } else {
                    printf("No match in struct for %s", userInput);
                }
                */

                break;
            case 2:
                exit = 1;
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    }
}

#endif