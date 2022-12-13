#include "stdio.h"
#include <stdlib.h>
#include <time.h>

//declare linked list struct
struct data {
    int data;
    struct data* next;
};

//create structs for later use
struct data* unsorted = NULL;
struct data* sorted = NULL;

void insert(int val)
{
    //allocate memory for struct
    struct data* dataStru = (struct data*)malloc(sizeof(struct data));
    dataStru->data = val;
    //link the old list of the new data
    dataStru->next = unsorted;
    //move the unsorted to point to the new data
    unsorted = dataStru;
}


void fillinSorted(struct data* newnode)
{
    //Special case for the unsorted end
    if (sorted == NULL || sorted->data >= newnode->data) {
        newnode->next = sorted;
        sorted = newnode;
    }
    else {
        struct data* current = sorted;

        //Locate the data before the point of insertion
        while (current->next != NULL
               && current->next->data < newnode->data) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}

// function to sort a singly linked list

void sort()
{

    struct data* current = unsorted;

    //Traverse the given linked list and insert every
    //data to sorted
    while (current != NULL) {

        //Store next for next iteration
        struct data* next = current->next;

        //insert current in sorted linked list
        fillinSorted(current);

        //Update current
        current = next;
    }
    //Update unsorted to point to sorted linked list
    unsorted = sorted;
}


void printstruct(struct data* temp)
{

    unsigned int i = 0;
    //only print 15 numbers
    while (temp != NULL && i < 15) {

        printf("%d ", temp->data);
        temp = temp->next;
        i++;
    }
    printf("\n");
}
void inserS_LL (int *randArr, int sizeRandArr, double *timetakenArr, double *timetakenArr2){

    //====================Calculation of struct init time
    clock_t begin, end;

    begin = clock();

    for(int i = ( sizeRandArr - 1 ); i >= 0; ){
        insert(randArr[i]);
        i--;
    }

    end = clock();

    *timetakenArr = (((double)end - (double)begin) / CLOCKS_PER_SEC * 1000);
    //====================END

    //====================Print only 15 values of sorted list <- defined in printstruct();
    printf("\nUnsorted Array / List \n");
    printstruct(unsorted);
    //====================END
    //====================Calculate time of sorting a linked list and write value to variable behind pointer
    begin = clock();

    sort();

    end = clock();
    *timetakenArr2 = (((double)end - (double)begin) / CLOCKS_PER_SEC * 1000);
    //====================END
    //====================Print only 15 values of sorted list <- defined in printstruct();
    printf("\nSorted List \n");
    printstruct(unsorted);
    //====================END

}
