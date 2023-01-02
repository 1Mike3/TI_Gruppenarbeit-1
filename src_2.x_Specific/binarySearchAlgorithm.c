//
// Created by osboxes on 02/01/23.
//

#include "binarySearchAlgorithm.h"

#include <string.h>

//Michi , function to sort a struct containing an integer and a string using binary search
//split int two functions to differentiate between the integer and the string elements
// the searched elements must be sorted ascendingly, if they are not the search alg. doesn't work

//searches a sorted array for an integer value
//returns the index of the array at the place where the element has been found
//if no element found return -1
int binarySearchInteger(data *sortedStructArray,int searchedInteger,int leftmostIndex,  int rightmostIndex){

     int workingMiddleIndex = 1+ ((rightmostIndex -1) / 2);

    // #### check if middle was a hit, if so return the middle index  ####
    if( (sortedStructArray+workingMiddleIndex)->number == searchedInteger)
        return workingMiddleIndex;

    // #### check if the whole array has been checked and return if it was ####
    if(leftmostIndex > rightmostIndex)
        return  -1;

    // ##### case searched value is smaller than middle value  ####
    if( (sortedStructArray+workingMiddleIndex)->number < searchedInteger)
       return binarySearchInteger(sortedStructArray, searchedInteger, leftmostIndex, (workingMiddleIndex -1));

    // #### case searched value is smaller than middle value  ####
    if( (sortedStructArray+workingMiddleIndex)->number > searchedInteger)
   return binarySearchInteger(sortedStructArray, searchedInteger, (workingMiddleIndex+1), rightmostIndex);

}



//searches a sorted array for s string value
//returns the index of the array at the place where the element has been found
//if no element found return -1
int binarySearchString(data *sortedStructArray,char *searchedString,int leftmostIndex, int rightmostIndex){
    int workingMiddleIndex = 1+ ((rightmostIndex -1) / 2);

    // #### check if middle was a hit, if so return the middle index  ####
    if (0 == strcmp((sortedStructArray+workingMiddleIndex)->string, searchedString))
        return workingMiddleIndex;

    // #### check if the whole array has been checked and return if it was ####
    if(leftmostIndex > rightmostIndex)
        return  -1;

    // ##### case searched value is smaller than middle value  ####
   // if( 0 == strcmp((sortedStructArray+workingMiddleIndex)->string, searchedString))
    //    return binarySearchInteger(sortedStructArray, searchedInteger, leftmostIndex, (workingMiddleIndex -1));

    // #### case searched value is smaller than middle value  ####
 //   if( (sortedStructArray+workingMiddleIndex)->number > searchedInteger)
        //return binarySearchInteger(sortedStructArray, searchedInteger, (workingMiddleIndex+1), rightmostIndex);
}

//the checkOrder functions assume that a string consists of lowercase Ascii alphabetical character

int checkOrderString(const char *string1,const char *string2){

}

//returns value that signalizes which character is alphabetically sorted larger:
//return-value see enum in associated header
int checkOrderChar(const char char1, const char char2){
    char startCompareCharacter = 'a';
    char endCompareCharacter = 'z';

    //case input not lower alphabet char
    if(char1 < startCompareCharacter || char1 > endCompareCharacter)
        return orderChar_inputCharValueInvalid;
    if(char2 < startCompareCharacter || char2 > endCompareCharacter)
        return orderChar_inputCharValueInvalid;

    if(char1 == char2)
        return orderChar_charsEqual;

    if(char1 < char2)
        return  orderChar_firstCharLess;

    if(char1 > char2)
        return orderChar_secondCharLess;

}