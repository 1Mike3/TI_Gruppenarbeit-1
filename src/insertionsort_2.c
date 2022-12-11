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
void push(int val)
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

void insertionsort()
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


void printlist(struct node* head)
{
    printf("Arr" );
    while (head != NULL) {

        printf("%d ", head->data);
        head = head->next;
    }
    printf("NULL");
}
void inserS_LL (int *randArr, int sizeRandArr){


        for(int i = ( sizeRandArr - 1 ); i >= 0; ){
            push(randArr[i]);
            i--;
        }
/*
        printf("\nLinked List before sorting:\n");
        printlist(head);
        printf("\n");
*/

        clock_t t;

        t = clock();


        insertionsort(head);

        t = clock() - t;
/*
        printf("\nLinked List after sorting:\n");
        printlist(head);
*/
        double time_taken = ((double)t)/CLOCKS_PER_SEC*1000;

        printf("\ninserS() with linked list took %f miliseconds to execute \n", time_taken);

}
