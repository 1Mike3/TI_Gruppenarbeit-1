//
// Created by osboxes on 02/01/23.
//

//
// Created by Asuka on 05.01.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "allfunclib.h"
#include "binarySearchAlgorithm.h"
#include "generateRandomStruct.h"




char string [30] = "This is sparta";
int searchedInteger;
int searchFlag;
struct data s1[401];
int structDataCount = 400;
struct data sortedStructArray[401];
int numberOfElements = 0;

int main (void) {
    printf("Please enter 1 if you want to search for a string or 2 if you want to search for an integer: ");
    scanf("%d", &searchFlag);
    printf("Please enter a string to be searched: ");
    scanf("%s", string);
    printf("Please enter an integer to be searched: ");
    scanf("%d", &searchedInteger);
    if(searchFlag != 1 && searchFlag != 2){
        printf("Invalid flag. Please enter 1 or 2. Program will exit now.");
        return 0;
    }
    if(searchFlag == 1){
        int stringIndex = binarySearchString(sortedStructArray, string, 0, (numberOfElements-1));
        if(stringIndex == -1){
            printf("The string %s was not found in the array.", string);
        }else{
            printf("The string %s was found in the array at index %d.", string, stringIndex);
        }
    }
    if(searchFlag == 2){
        int integerIndex = binarySearchInteger(sortedStructArray, searchedInteger, 0, (numberOfElements-1));
        if(integerIndex == -1){
            printf("The integer %d was not found in the array.", searchedInteger);
        }else{
            printf("The integer %d was found in the array at index %d.", searchedInteger, integerIndex);
        }
    }
    return 0;
}


#include "userInputSearch.h"
