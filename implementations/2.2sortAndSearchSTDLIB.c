#include "binarySearchAlgorithm.h"
#include <stdio.h>
#include <stdlib.h>
#include "quicksortString.h"
#include "generateRandomStruct.h"

#if 1

//Create compare function to compare the numbers in the struct
//this is used by the LIB qsort
int cmpStruct(const void *a, const void *b) {
    struct data *ia = (struct data *)a;
    struct data *ib = (struct data *)b;
    return (ia->number - ib->number);
}

int main() {

    //Show menu until user chooses to exit
    int exit = 0;
    while(!exit){

        //create struct with given elements
        int structDataCount = 400;
        struct data s1[structDataCount];
        //generate the random structures with randon int and 5 random chars
        genRanStruct(structDataCount, s1);
        //choice handling
        int choice = 0;
        printf("\n\nPlease enter the number of choice.\n");
        printf("1. Search integer\n");
        printf("2. Quit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        int userInput=-1;
        switch (choice) {
            case 1:
                //print the unsorted array
                printf("\n=========UNSORTED========\n");
                for (int i = 0; i < structDataCount; i++) {
                    printf("[i:%-3d] %-5d %s | ",i, s1[i].number, s1[i].string);
                    if((i+1)%5 == 0)
                        printf("\n");

                }
                printf("\n=========END UNSORTED========\n");

                //get user input for the value to search for
                printf("\nEnter number: ");
                scanf("%d", &userInput);
                printf("\n");

                //use LIB qsort to sort the given struct
                qsort(s1,structDataCount,sizeof(struct data), cmpStruct);

                //print sorted struct
                printf("\n=========SORTED========\n");
                for (int i = 0; i < structDataCount; i++) {
                    printf("[i:%-3d] %-5d %s | ",i, s1[i].number, s1[i].string);
                    if((i+1)%5 == 0)
                        printf("\n");

                }
                printf("\n ========= END SORTED========\n");

                //create a temporary struct to store the found element and fill it with the return of the binarysearch lib function
                struct data* structIndex = bsearch(&userInput, s1, structDataCount, sizeof(struct data), cmpStruct);
                //handle the output depending on what has been found
                if (structIndex != NULL) {
                    printf("\nElement found: %d with string value %s\n", structIndex->number, structIndex->string);
                } else {
                    printf("Element not found\n");
                }

                break;
            case 2:
                //stop the menu loop if user chooses
                exit = 1;
                break;
            default:
                //if no valid input is given
                printf("Invalid input\n");
                break;
        }
    }
    return 0;
}

#endif