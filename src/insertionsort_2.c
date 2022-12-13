//
// Created by Emad on 11.12.2022.
//
#include "stdio.h"
#include <stdlib.h>
#include <time.h>


struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;
struct node* sorted = NULL;

void writeToList(int val)
{
    /* allocate node */
    struct node* newnode
            = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    /* link the old list of the new node */
    newnode->next = head;
    /* move the head to point to the new node */
    head = newnode;
}


void sortedInsert(struct node* newnode)
{
    /* Special case for the head end */
    if (sorted == NULL || sorted->data >= newnode->data) {
        newnode->next = sorted;
        sorted = newnode;
    }
    else {
        struct node* current = sorted;
        /* Locate the node before the point of insertion
        */
        while (current->next != NULL
               && current->next->data < newnode->data) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}

// function to sort a singly linked list

void insertionSort()
{

    struct node* current = head;

    // Traverse the given linked list and insert every
    // node to sorted
    while (current != NULL) {

        // Store next for next iteration
        struct node* next = current->next;

        // insert current in sorted linked list
        sortedInsert(current);

        // Update current
        current = next;
    }
    // Update head to point to sorted linked list
    head = sorted;
}


void printList(struct node* head)
{

    int i = 0;
    while (head != NULL && i < 15) {

        printf("%d ", head->data);
        head = head->next;
        i++;
    }
    printf("\n");
}
int inserS_LL (int *randArr, int sizeRandArr, double *timetakenArr, double *timetakenArr2){

    clock_t begin, end;

    begin = clock();

    for(int i = ( sizeRandArr - 1 ); i >= 0; ){
        writeToList(randArr[i]);
        i--;
    }

    end = clock();

    *timetakenArr = (((double)end - (double)begin) / CLOCKS_PER_SEC * 1000);

        //====================Print only 15 values of sorted list <- defined in printList();
        printf("\nUnsorted Array / List \n");
        printList(head);
        //====================END

        begin = clock();

        insertionSort(head);

        end = clock();
        *timetakenArr2 = (((double)end - (double)begin) / CLOCKS_PER_SEC * 1000);

        //====================Print only 15 values of sorted list <- defined in printList();
        printf("\nSorted List \n");
        printList(head);
        //====================END

}
