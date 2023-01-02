#include "generateRandomStruct.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int genRanStruct(int valuesCount, struct ranStruct workingStruct[]){
    for(int i=0; i <= valuesCount; i++) {
        workingStruct[i].index = i;
        char randomletter[6];
        for(int i=0; i<5; i++){

            randomletter[i] = 'a' + (rand() % 26);
        }

        strcpy(workingStruct[i].ranChar, randomletter);
    }

}
