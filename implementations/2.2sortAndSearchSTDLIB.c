#include "binarySearchAlgorithm.h"
#include <stdio.h>
#include <stdlib.h>
#include "quicksortString.h"
#include "generateRandomStruct.h"

#if 1

int cmpStruct(const void *a, const void *b) {
    struct data *ia = (struct data *)a;
    struct data *ib = (struct data *)b;
    return (ia->number - ib->number);
}

int main() {
    int exit = 0;
    while(!exit){
        struct data s1[400];
        int structDataCount = 400;
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
                    printf("[i:%-3d] %-5d %s | ",i, s1[i].number, s1[i].string);
                    if((i+1)%5 == 0)
                        printf("\n");

                }

                printf("\n=========END UNSORTED========\n");
                printf("\nEnter number: ");

                scanf("%d", &userInput);
                printf("\n");

                qsort(s1,structDataCount,sizeof(struct data), cmpStruct);
                printf("\n=========SORTED========\n");
                for (int i = 0; i < structDataCount; i++) {
                    printf("[i:%-3d] %-5d %s | ",i, s1[i].number, s1[i].string);
                    if((i+1)%5 == 0)
                        printf("\n");

                }
                printf("\n ========= END SORTED========\n");
                struct data* structIndex = bsearch(&userInput, s1, structDataCount, sizeof(struct data), cmpStruct);
                if (structIndex != NULL) {
                    printf("\nElement found: %d with string value %s\n", structIndex->number, structIndex->string);
                } else {
                    printf("Element not found\n");
                }

                break;
            case 2:
                exit = 1;
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    }
    return 0;
}

#endif