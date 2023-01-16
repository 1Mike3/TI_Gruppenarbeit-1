#include "binarySearchAlgorithm.h"
#include <stdio.h>
#include <string.h>
#include "quicksortString.h"
#include "quicksortInt.h"
#include "generateRandomStruct.h"

#if 1
int main() {
    int exit = 0;
    int structDataCount = 400;
    struct data s1[structDataCount];
    int choice = 0;
    char userInput[6];
    int userInputInt = 0;
    char foundValueString[10];
    int foundValue = 0;

    while(!exit){

        genRanStruct(structDataCount , s1);

        printf("\n\nPlease enter the number of choice.\n");
        printf("1. Search string\n");
        printf("2. Search integer\n");
        printf("3. Quit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        fflush(stdin);


        //switch case depending on user Input
        switch (choice) {


            case 1: //case for string selected


                printf("\n=========UNSORTED========\n");
                for (int i = 0; i < structDataCount; i++) {
                    printf("[i:%-3d] %-5d %s | ",i, s1[i].number, s1[i].string);
                    if((i+1)%5 == 0)
                        printf("\n");

                }
                printf("\n=========END UNSORTED========\n");
                printf("\nEnter String: ");
                scanf("%s", userInput);
                fflush(stdin);
                printf("\n");


                quickSortString(s1, structDataCount);



                printf("\n=========SORTED========\n");
                for (int i = 0; i < structDataCount; i++) {
                    printf("[i:%-3d] %-5d %s | ",i, s1[i].number, s1[i].string);
                    if((i+1)%5 == 0)
                        printf("\n");
                }
                printf("\n=========END SORTED========\n");


                int returnIndex = binarySearchString(s1, userInput, 0, structDataCount);
                if(returnIndex >= 0){
                   foundValue = s1[returnIndex].number;
                    strcpy(foundValueString, s1[returnIndex].string );
                    printf("\nThe Returnindex is: %i", returnIndex);
                    printf("\nThe integer value for the index is: %d", foundValue);
                    printf("\nThe string value for the index is: %s", foundValueString);
                } else {
                    printf("No match in struct for %s", userInput);
                }
                break;




            case 2: //case search for integer selected

                printf("\n=========UNSORTED========\n");
                for (int i = 0; i < structDataCount; i++) {
                    printf("[i:%-3d] %-5d %s | ",i, s1[i].number, s1[i].string);
                    if((i+1)%5 == 0)
                        printf("\n");
                }
                printf("\n=========END UNSORTED========\n");


                printf("\nEnter Integer: ");
                scanf("%d", &userInputInt);
                fflush(stdin);
                printf("\n");

                //quickSortInt(s1, structDataCount);
                quickSortInt(s1,structDataCount);

                printf("\n=========SORTED========\n");
                for (int i = 0; i < structDataCount; i++) {
                    printf("[i:%-3d] %-5d %s | ",i, s1[i].number, s1[i].string);
                    if((i+1)%5 == 0)
                        printf("\n");
                }
                printf("\n=========END SORTED========\n");

                returnIndex = binarySearchInteger(s1, userInputInt, 0, structDataCount);
                if(returnIndex >= 0){
                    foundValue = s1[returnIndex].number;
                    strcpy(foundValueString, s1[returnIndex].string );
                    printf("\nThe Returnindex is: %i", returnIndex);
                    printf("\nThe integer value for the index is: %d", foundValue);
                    printf("\nThe string value for the index is: %s", foundValueString);
                } else {
                    printf("No match in struct for %d", userInputInt);
                }


                break;



            case 3:
                printf("\nYou chose to quit the Program!\n");
                fflush(stdin);
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