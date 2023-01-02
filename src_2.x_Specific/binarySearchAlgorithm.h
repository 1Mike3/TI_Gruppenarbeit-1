//
// Created by osboxes on 02/01/23.
//

#ifndef GRUPPENARBEIT_TI_BINARYSEARCHALGORITHM_H
#define GRUPPENARBEIT_TI_BINARYSEARCHALGORITHM_H

#endif //GRUPPENARBEIT_TI_BINARYSEARCHALGORITHM_H

//typedef of the struct used to do the sorting
typedef struct data {
    int number;
    char string[30];
}data;

//enum for return value of checkOrderChar function
enum retCheckOrderChar {
    orderChar_charsEqual = 0,
    orderChar_firstCharLess = 1,
    orderChar_secondCharLess = 3,
    orderChar_inputCharValueInvalid = 4,
};

//enum for return value of checkOrderString function
enum retCheckOrderString {
    orderString_stringsEqual = 0,
    orderString_firstStringLess = 1,
    orderString_secondCharLess = 3,
    orderString_inputStringValueInvalid = 4,
};
