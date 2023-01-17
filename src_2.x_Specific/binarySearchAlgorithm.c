//
// Created by osboxes on 02/01/23.
//

#include "binarySearchAlgorithm.h"
#include <string.h>
#include <stdio.h>

//Michi , function to sort a struct containing an integer and a string using binary search
//split int two functions to differentiate between the integer and the string elements
// the searched elements must be sorted ascendingly, if they are not the search alg. doesn't work

//searches a sorted array for an integer value
//returns the index of the array at the place where the element has been found
//if no element found return -1
int binarySearchInteger(data *sortedStructArray,int searchedInteger,int leftmostIndex,  int rightmostIndex){

     int workingMiddleIndex = ((rightmostIndex + leftmostIndex) / 2);

    // #### check if middle was a hit, if so return the middle index  ####
    if( (sortedStructArray+workingMiddleIndex)->number == searchedInteger)
        return workingMiddleIndex;

    // #### check if the whole array has been checked and return if it was ####
    if(leftmostIndex > rightmostIndex)
        return  -1;

    // ##### case searched value is smaller than middle value  ####

    if( (sortedStructArray+workingMiddleIndex)->number > searchedInteger)

       return binarySearchInteger(sortedStructArray, searchedInteger, leftmostIndex, (workingMiddleIndex -1));

    // #### case searched value is smaller than middle value  ####
    if( (sortedStructArray+workingMiddleIndex)->number < searchedInteger)
   return binarySearchInteger(sortedStructArray, searchedInteger, (workingMiddleIndex+1), rightmostIndex);


}



//searches a sorted array for s string value
//returns the index of the array at the place where the element has been found
//if no element found return -1
int binarySearchString(data *sortedStructArray,char *searchedString,int leftmostIndex, int rightmostIndex){
    int workingMiddleIndex = ((rightmostIndex + leftmostIndex) / 2);

    // #### check if middle was a hit, if so return the middle index  ####
    if (0 == strcmp((sortedStructArray+workingMiddleIndex)->string, searchedString))
        return workingMiddleIndex;

    // #### check if the whole array has been checked and return if it was ####
    if(leftmostIndex > rightmostIndex)
        return  -1;


    //Debug helpers
    volatile char string[6];
    strcpy(string,(sortedStructArray+workingMiddleIndex)->string) ;

     //##### case searched value is smaller than middle value  ####
     //FIRST  == SEARCHED STRING
     //FIRST LESS
   if( orderString_firstStringLess == checkOrderString(searchedString, (sortedStructArray+workingMiddleIndex)->string))
    return binarySearchString(sortedStructArray, searchedString, leftmostIndex, (workingMiddleIndex -1));

    // #### case searched value is larger than middle value  ####
    //SECOND LESS
 if(  orderString_secondStringLess == checkOrderString(searchedString, (sortedStructArray+workingMiddleIndex)->string))
     return binarySearchString(sortedStructArray, searchedString, (workingMiddleIndex+1), rightmostIndex);


}

//the checkOrder functions assume that a string consists of lowercase ASCII alphabetical character

int checkOrderString(const char *string1,const char *string2){

    //return immediately if strings are equal
    if(0 == strcmp(string1, string2))
        return  orderString_stringsEqual;

    //get the length of both input strings
   unsigned long lengthString1 = strlen(string1);
   unsigned long lengthString2 = strlen(string2);
   unsigned long maxCompareLength;
   short int equalLengthMarker = 0;


   // estimate the length of the shorter string, so you get the number of chars which should be compared
   if(lengthString1 < lengthString2)
       maxCompareLength = lengthString1;

    if(lengthString1 > lengthString2)
        maxCompareLength = lengthString2;

    if(lengthString1 == lengthString2){
        maxCompareLength = lengthString1;
        equalLengthMarker = 1;
    }

    int tempCheckOrderCharRetVal;
    for (int i = 0; i < maxCompareLength; ++i) {
        tempCheckOrderCharRetVal  = checkOrderChar(string1[i], string2[i]);
        switch (tempCheckOrderCharRetVal) {
            case orderChar_charsEqual:
                continue;
                break;
            case orderChar_firstCharLess:
                return orderString_firstStringLess;

            case orderChar_secondCharLess:
                return orderString_secondStringLess;

            case orderChar_inputCharValueInvalid:
                return orderString_inputStringValueInvalid;

            default:
                printf("Error default switch case tempOrderChar!!\n");
                break;
        }
    }// end for

  if(equalLengthMarker == 1)
      return orderString_stringsEqual;

  // at this point equalLength Marker == 0
  if(maxCompareLength == lengthString1)
          return orderString_firstStringLess;

  if(maxCompareLength == lengthString2)
              return orderString_secondStringLess;

    return orderString_inputStringValueInvalid;
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
