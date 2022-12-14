#ifndef TI_GRUPPENARBEIT_1_ALLFUNCLIB_H
#define TI_GRUPPENARBEIT_1_ALLFUNCLIB_H

#include <stdio.h>
//declare all functions below;

//Markus
void bubbleS (int *arr, int size);
void inserS (int *arr, int size);

//Michi
void printArr(int *arr, int size);
void copyArr(int *arr1, int *arr2, int size);
void quickS (int *arr, int size);
void swapi(int *, int *);
int checkSort(int *arr, int size, int mode);
//_________________Main implementations:
void basicCheck1_1(int call ,const int *sizeArr, int arrayNumber);
void benchmark1_2(int call);
void comparison1_3();

//Emad
void compareLinkedList();
int *genRandNum(int size, int *randArr);
void printRandArr(int *arrToPrint, int arrSize);
void merge(int arr[], int p, int q, int r);
void mergeS (int *arr, int l, int r);
void inserS_LL (int *randArr, int sizeRandArr, double *timetakenArr, double *timetakenArr2);



#endif //TI_GRUPPENARBEIT_1_ALLFUNCLIB_H


