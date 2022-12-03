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

//Qicksortfunktion, es werden zwei Arrays übergeben ein unsortiertes und ein leeres gleicher größe in das geschrieben wird
//copyarr und printarr funktionieren
void quickS (int *arrUS, int *arrS, unsigned int size){

    //an dieser Stelle wird das unsortierte Array kopiert
    copyarr(arrUS, arrS, size );

    //Ausgabe des sortierten Arrays an die Konsole
    printarr(arrS, size);
}

