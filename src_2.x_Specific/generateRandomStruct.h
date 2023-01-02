//
// Created by osboxes on 02/01/23.
//

#ifndef GRUPPENARBEIT_TI_GENERATERANDOMSTRUCT_H

#define GRUPPENARBEIT_TI_GENERATERANDOMSTRUCT_H

typedef struct data {
    int number;
    char string[5];
}data;

int genRanStruct(int valuesCount, struct data workingStruct[]);
#endif //GRUPPENARBEIT_TI_GENERATERANDOMSTRUCT_H
