//
// Created by Michi on 30.11.2022.
//Mein quicksort Algorithmus, eigenständige Funktion die ein übergebenes Array mit dem Quicksortalgorithmus Sortiert
//
#include "stdio.h"
void printarr(int *arr, int size);
void copyarr(int *arr1, int *arr2, int size);


//definiere niedrigste unterteilung im array
#define  mindiv 3

//"arr" ist das übergebene Array beliebiger größe
// "size" ist die größe des übergebenen Arrays
//TODO error code für diverse Laufzeitfehler erstellen

//Qicksortfunktion, eingegebenes array wird sortiert
//copyarr und printarr funktionieren
void quickS (int *arr, unsigned int size){
int first = arr[0], last = arr[(size-1)], temp = 0;
    //an dieser Stelle wird das unsortierte Array kopiert
    //copyarr(arrUS, arrS, size );


    //Ausgabe des sortierten Arrays an die Konsole
    printarr(arr, size);
}

