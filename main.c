#include <stdio.h>

//include custom header file with all needed functions declared
#include "allfunclib.h"
#include "generateRandomStruct.h"


int main() {

    ranStruct s1[400];
    genRanStruct(400, s1);

    for(int i=0; i<=400;i++){
        printf("%d %s | ",s1[i].index, s1[i].ranChar);
    }

    return 0;
}

