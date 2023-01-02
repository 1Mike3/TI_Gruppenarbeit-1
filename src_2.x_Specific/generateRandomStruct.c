#include "generateRandomStruct.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "allfunclib.h"

int genRanStruct(int valuesCount, struct data workingStruct[]){
    for(int i=0; i <= valuesCount; i++) {
      //  workingStruct[i].number = randNumReturn(3000,0);
        workingStruct[i].number = i;
        char randomletter[6]={};
        for(int i=0; i<5; i++){

            randomletter[i] = 'a' + (rand() % 26);
        }

        strcpy(workingStruct[i].string, randomletter);
    }

}
