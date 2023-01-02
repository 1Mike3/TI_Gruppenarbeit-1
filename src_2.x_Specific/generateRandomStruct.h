//
// Created by osboxes on 02/01/23.
//
struct data {
    int number;
    char string[5];
};
typedef struct data ranStruct;
#ifndef GRUPPENARBEIT_TI_GENERATERANDOMSTRUCT_H
#define GRUPPENARBEIT_TI_GENERATERANDOMSTRUCT_H
int genRanStruct(int valuesCount, struct data workingStruct[]);
#endif //GRUPPENARBEIT_TI_GENERATERANDOMSTRUCT_H
