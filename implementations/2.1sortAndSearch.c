//
// Created by osboxes on 02/01/23.
//
#include "binarySearchAlgorithm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quicksortString.h"
#include "quicksortInt.h"

#include "generateRandomStruct.h"
#if 1
int main() {
    int exit = 0;
    struct data s1[40];
    int structDataCount = 40;
    genRanStruct(structDataCount, s1);
    int choice = 0;
    char userInput[6];
    int userInputInt = 0;

    while(!exit){

        printf("\n\nPlease enter the number of choice.\n");
        printf("1. Search string\n");
        printf("2. Search integer\n");
        printf("3. Quit\n");
        scanf("%d", &choice);



        //switch case depending on user Input
        switch (choice) {


            case 1: //case for string selected
                printf("\n=========UNSORTED========\n");
                for (int i = 0; i < structDataCount; i++) {
                    printf("%d %s | ", s1[i].number, s1[i].string);
                    //Michi, added so printout looks better
                    if(i%15 == 0 && i != 0)
                        printf("\n");

                }
                printf("\n=========END UNSORTED========\n");
                printf("\nEnter String: ");
                scanf("%s", userInput);


                printf("\n");
                quickSortString(s1, structDataCount);
                printf("\n=========SORTED========\n");
                for (int i = 0; i < structDataCount; i++) {
                    printf(" [i:%d] %d %s | ", i,s1[i].number, s1[i].string);
                    //Michi, added so printout looks better
                    if(i%15 == 0 && i != 0)
                        printf("\n");
                }
                printf("\n=========END SORTED========\n");


                int returnIndex = binarySearchString(s1, userInput, 0, structDataCount);
                if(returnIndex >= 0){
                    int foundValue = s1[returnIndex].number;
                    printf("\nThe Returnindex is: %i", returnIndex);
                    printf("\nThe value for the index is: %d", foundValue);
                } else {
                    printf("No match in struct for %s", userInput);
                }
                break;




            case 2: //case search for integer selected

                printf("\n=========UNSORTED========\n");
                for (int i = 0; i < structDataCount; i++) {
                    printf("%d %s | ", s1[i].number, s1[i].string);
                    //Michi, added so printout looks better
                    if(i%15 == 0 && i != 0)
                        printf("\n");
                }
                printf("\n=========END UNSORTED========\n");


                printf("\nEnter Integer: ");
                scanf("%d", &userInputInt);

                printf("\n");

                //quickSortInt(s1, structDataCount);
                quickSortInt(s1,structDataCount);

                printf("\n=========SORTED========\n");
                for (int i = 0; i < structDataCount; i++) {
                    printf(" [i:%d] %d %s | ", i,s1[i].number, s1[i].string);
                    //Michi, added so printout looks better
                    if(i%15 == 0 && i != 0)
                        printf("\n");
                }
                printf("\n=========END SORTED========\n");


                break;



            case 3:
                printf("\nYou chose to quit the Program!\n");
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