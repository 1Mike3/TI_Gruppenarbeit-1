#include <stdio.h>

//include custom header file with all needed functions declared
#include "allfunclib.h"
#if activateAllMain
int main() {
int arrsdf[5] = {4,6,-2,-7,10};
    inserS(arrsdf, 5);
    //compareLinkedList();
    for (int i = 0; i < 5; ++i) {
        printf("%i\n", arrsdf[i]);
    }

    return 0;

}
# endif
