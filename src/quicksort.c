//
// Created by Michi on 30.11.2022.
//Mein quicksort Algorithmus, eigenständige Funktion die ein übergebenes Array mit dem Quicksortalgorithmus Sortiert
//
#include "stdio.h"
void printarr(int *arr, int size);
void copyarr(int *arr1, int *arr2, int size);
void swapi(int *val1, int *val2);


//definiere niedrigste unterteilung im array
#define  mindiv 3

//"arr" ist das übergebene Array beliebiger größe
// "size" ist die größe des übergebenen Arrays
//TODO error code für diverse Laufzeitfehler erstellen
//TODO wenn fertig code mit valgrind überprüfen

//Qicksortfunktion, eingegebenes array wird sortiert
//copyarr und printarr funktionieren
void quickS (int *arr, unsigned int size){
int first = arr[0], last = arr[(size-1)], temp = 0;
    //an dieser Stelle wird das unsortierte Array kopiert

    //swap first and last, works
    //swapi(arr,(arr+size-1));



}

