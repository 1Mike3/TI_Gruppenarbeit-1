//
// Created by Emad on 30/11/2022.
//

#ifndef TI_GRUPPENARBEIT_1_ALLFUNCLIB_H
#define TI_GRUPPENARBEIT_1_ALLFUNCLIB_H

#include <stdio.h>
//declare all functions below;

//implementation min merge.c file
//void mergeS (int *arr, unsigned int size);

void bubbleS (int *arr, unsigned int size);
void inserS (int *arr, unsigned int size);

//Michi
void printArr(int *arr, unsigned int size);
void copyArr(int *arr1, int *arr2,unsigned int size);
void quickS (int *arr, int size);
void swapi(int *, int *);
int checkSort(int *arr, unsigned int size, short int mode);


//Emad
void compareLinkedList();
int *genRandNum(int size, int *randArr);
void printRandArr(int *arrToPrint, int arrSize);
void merge(int arr[], int p, int q, int r);
void mergeS (int *arr, int l, int r);

//_________________Main implementations:
void basicCheck1_1(int call ,const int *sizeArr, int arrayNumber);
void benchmark1_2(int call);
void comparison1_3();

#endif //TI_GRUPPENARBEIT_1_ALLFUNCLIB_H


