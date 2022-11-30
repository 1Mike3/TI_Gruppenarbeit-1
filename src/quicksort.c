//
// Created by Michi on 30.11.2022.
//Mein quicksort Algorithmus, eigenständige Funktion die ein übergebenes Array mit dem Quicksortalgorithmus Sortiert
//
#include "stdio.h"
//deviniere niedrigste unterteilung im array
#define  mindiv 3

//"arr" ist das übergebene Array beliebiger größe
// "size" ist die größe des übergebenen Arrays
//TODO error code für diverse Laufzeitfehler erstellen

//INFO Testarray um Funktion auf Korrektheit zu überrprüfen
int array[12] = {5,66,8,3,3,7,0,2,1,4,6,9,44};

void quickS (int *arr, unsigned int size){
    for(unsigned int i = 0;i < size; i++){
        if (3 >= size/2){
            printf("test");
        }
    }

}