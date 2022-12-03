#include <stdio.h>
#include "stdlib.h"
#include "time.h"

//include custom lib
#include "include/allfunclib.h"

int main() {

    //Testarray um Funktion auf Korrektheit zu überrprüfen
    int arrUS[12] = {5,66,8,3,3,7,0,2,1,4,6,9,};
    //Testarray, sortierte version von oberem Array
    int arrS[12] = {};
    unsigned int size = 12;

    //mergeS(*arr, size);
    quickS(arrUS, size);
   // bubbleS(*arr, size);
   // inserS(*arr, size);


    return 0;
}

