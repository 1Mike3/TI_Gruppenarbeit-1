//
// Created by Michi on 30.11.2022.
//Mein quicksort Algorithmus, eigenständige Funktion die ein übergebenes Array mit dem Quicksortalgorithmus Sortiert
//
#include "stdio.h"

//definiere niedrigste unterteilung im array
#define  mindiv 3

//"arr" ist das übergebene Array beliebiger größe
// "size" ist die größe des übergebenen Arrays
//TODO error code für diverse Laufzeitfehler erstellen

//Testarray um Funktion auf Korrektheit zu überrprüfen
int arrayUS[12] = {5,66,8,3,3,7,0,2,1,4,6,9,};
//Testarray, sortierte version von oberem Array
int arrayS[12] = {};


void printarr2(int *arr, int size){
    for (int i = 0; i < size; ++i) {
        printf("Printarray:\n");
        printf("[%i]: %i\n", i, *(arr+i));
    }
}
//Kopiert arr1 nach arr2
void copyarr2(int *arr1, int *arr2, int size){
    for (int i = 0; i < size; ++i) {
        arr2[i] = arr1[i];
    }
}


//Qicksortfinktion, es werden zwei Arrays übergeben ein unsortiertes und ein leeres gleicher größe in das geschrieben wird
void quickS (int *arrUS, int *arrS, unsigned int size){
    int arrayUT[12] = {5,66,8,3,3,7,0,2,1,4,6,9,};
    //copyarr2(*arrUS, *arrS, 12 );
    printarr2(arrayUT, 12);

}

