//
// Created by osboxes on 02/01/23.
//
#include "binarySearchAlgorithm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quicksortString.h"


#include "generateRandomStruct.h"

int main() {
    int exit = 0;
    while(!exit){
        struct data s1[401];
        int structDataCount = 400; // highest index not dataCount misleading --Michi
        genRanStruct(structDataCount, s1);
        int choice = 0;
        printf("\n\nPlease enter the number of choice.\n");
        printf("1. Search string\n");
        printf("2. Search integer\n");
        printf("3. Quit\n");
        scanf("%d", &choice);
        char userInput[6];
        switch (choice) {
            case 1:
                printf("\n=========UNSORTED========\n");
                for (int i = 0; i <= structDataCount; i++) {
                    printf("%d %s | ", s1[i].number, s1[i].string);
                }
                printf("\n=========UNSORTED========\n");
                printf("\nEnter String: ");
                scanf("%s", userInput);
                printf("\n");
                quickSortString(s1, structDataCount + 1);
                printf("\n=========SORTED========\n");
                for (int i = 0; i <= structDataCount; i++) {
                    printf("%d %s | ", s1[i].number, s1[i].string);
                }
                printf("\n=========SORTED========\n");
                int returnIndex = binarySearchString(s1, userInput, 0, 400);
                if(returnIndex >= 0){
                    int foundValue = s1[returnIndex].number;
                    printf("\nThe Retutnindex is: %i", returnIndex);
                    printf("\nThe value for the index is: %d", foundValue);
                } else {
                    printf("No macth in struct for &s", userInput);
                }


                break;
            case 2:
                printf("\n=========UNSORTED========\n");
                for (int i = 0; i <= structDataCount; i++) {
                    printf("%d %s | ", s1[i].number, s1[i].string);
                }
                printf("\n=========UNSORTED========\n");
                printf("Case 2");
                break;
            case 3:
                exit = 1;
                break;
            default:
                printf("Invalid input\n");
        }
    }
}