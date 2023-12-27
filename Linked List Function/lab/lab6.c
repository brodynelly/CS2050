#include "lab6.h"
#include <stdio.h>
#include <stdlib.h>

int makeList(Node **list);
int getSize(Node *list);
void *getAtIndex(Node *list, int index);
int insertAtHead(Node *list, void *data);
void *removeFromTail(Node *list);
void freeList(Node **list);

int main()
{
}
/*
This function will initialize and return a Stack. If initialization fails, the info pointer in the
returned struct must be set to NULL. Your grade for this function will also include your stack imple-
mentation
*/
int makeList(Node **list)
{
    Node *dummy;
    dummy = (Node *)malloc(sizeof(Node));
    if (!dummy)
    {
        return 1;
    }              // malloc check
    *list = dummy; // sets list to equal dummy function...
    dummy->next = NULL;
    return 0;
}
/*
This function takes a stack, and returns the number of elements on the stack
*/
int getSize(Node *list)
{
    Node *loop = list->next; // skips dummy function
    if (list->next == NULL)
    {
        printf("The list is empty\n");
        return 0;
    } // checks if list is empty
    int count = 1;
    for (; loop->next != NULL; loop = loop->next)
    {
        count++;
    } // traverses through loop until reaching the end, counting every element
    return count;
}
/*
This function takes a list, and returns the element at the given index, or NULL if the index is
invalid.
*/
void *getAtIndex(Node *list, int index)
{
    Node *loop = list->next; // skip dummy node
    int count = 0;
    if ((index < 0) || (index >= (sizeof(Node))))
    { // checks if the given index is valid
        for (; loop->next != NULL; loop = loop->next)
        { // traverses through linked list until given index is reached
            if (count == index)
            {
                return loop;
            }
        }
        count++;
    }
    return NULL;
}
/*
This function takes a pointer to Node, and inserts the given data at the head of the list. It returns
0 if insertion was successful, or 1 if insertion failed.
*/
int insertAtHead(Node *list, void *data)
{
    Node *new = malloc(sizeof(Node));
    if (!new)
    {
        return 1;
    }
    new->data = data;
    new->next = list->next; // sets new node to point to the node previouly pointed to by the dummy node
    list->next = new;       // sets dummy node to now point to new node
    return 0;
}
/*
This function takes a pointer to Node, and removes the element at the tail of the list (if any). It
will return the data which was removed from the list, or NULL if the list was empty. You may assume
that no data on the list will be NULL.
*/
void *removeFromTail(Node *list)
{
    Node *loop = list->next; // skip dummy node
    Node *temp = NULL;
    for (; loop->next != NULL; loop = loop->next)
    {
        temp = loop;
    } // traverses through loop until the end is reached
    void *data = loop->data;
    if (!temp) // checks if current element in linked list is valid
    {
        list = NULL;
    } 
    else// if conditional statement fails, removes the element in list
    {
        temp->next = NULL;
    }           
    free(loop); // free memeory
    return (void *)data;
}
/*This function takes a pointer to Node *, and frees the memory allocated to the list. After freeing,
it sets the pointer to NULL.
*/
void freeList(Node **list)
{
    Node *ptr = *list; // creates a temp pointer that is the same as passed param
    while (ptr)
    {
        Node *ptrTemp = ptr; // creates second pointer to prevent seg falt for going pass tail node
        ptr = ptr->next;     // moves the first pointer by one to set second pointer to be free for next interation
        free(ptrTemp);       // frees second pointer that inst needed anymore (will move onto next one)
    }
    *list = NULL; // sets pointer to NULL
}
