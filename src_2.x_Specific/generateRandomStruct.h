//
// Created by osboxes on 02/01/23.
//
struct ranStruct {
    int index;
    char ranChar[5];
};
typedef struct ranStruct ranStruct;
#ifndef GRUPPENARBEIT_TI_GENERATERANDOMSTRUCT_H
#define GRUPPENARBEIT_TI_GENERATERANDOMSTRUCT_H
int genRanStruct(int valuesCount, struct ranStruct workingStruct[]);
#endif //GRUPPENARBEIT_TI_GENERATERANDOMSTRUCT_H
