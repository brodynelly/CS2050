#include "lab9.h"
#include <stdio.h>
#include <stdlib.h>

// prototypes
void *makeArray(int arraySize, int elementSize);
int getSize(void *array);
int searchClients(Client *array, Client *query);
int binarySearch(Client *array, int left, int right, Client *query); 
int compareClients(Client *a, Client *b);
void freeArray(void *array);

int main()
{ // main function
}

/*
This function will take an array size, as well as the size of each element in the array. It will
allocate an array with the given size, and store the size before the start of the array as an int. If
allocating the array was successful, it will return a pointer to the array, otherwise it will return NULL.
*/
void *makeArray(int arraySize, int elementSize)
{
    // allocate memory for the array and the size
    void *array = malloc(arraySize * elementSize + sizeof(int));

    if (array == NULL)
    {
        // allocation failed
        return NULL;
    }

    // store the size before the array
    *(int *)array = arraySize;

    // return a pointer to the beginning of the array
    return (char *)array + sizeof(int);
}

/*
This function takes an array which was allocated with makeArray, and returns the size stored
before the array.
*/
int getSize(void *array)
{
    // Get the size variable before the start of the array
    int *size = (int *)array - 1;
    return *size;
}

/*
this function performs a binary search on the given struct array using recursion. This function
will return the index of the query struct when it is located, or -1 on error.
*/
int searchClients(Client *array, Client *query)
{
    // perform binary search recursively
    return binarySearch(array, 0, getSize(array), query);
}

// binary search recursively
int binarySearch(Client *array, int left, int right, Client *query)
{
    if(left > right)
    {
        // not found, return error code -1
        return -1; 
    }
    
    // Calculate the middle index of the array
    int middle = left + (right - left) / 2;
    int cmp = compareClients(&array[middle], query);

    if (cmp == 0)
    {
        // If the middle client is equal to the query client, return the index of the middle client
        return middle;
    }
    else if (cmp < 0)
    {
        // If the middle client is less than the query client, search the right half of the array
        return binarySearch(array, middle + 1, right, query);
    }
    else
    {
        // If the middle client is greater than the query client, search the left half of the array
        return binarySearch(array, left, middle - 1, query);
    }
}

/*
This function compares the two structs given by their accountWorth members. It should return
a strictly negative number if a < b, a strictly positive number if a > b, or 0 if they are equal.
*/
int compareClients(Client *a, Client *b)
{
    if (a->accountWorth < b->accountWorth)
    {
        // It returns -1 if the account worth of the first client is less than the second client's
        return -1;
    }
    else if (a->accountWorth > b->accountWorth)
    {
        // It returns 1 if the account worth of the first client is greater than the second client's
        return 1;
    }
    else
    {
        // It returns 0 if both clients have equal account worth.
        return 0;
    }
}

/*
This function takes an array which was allocated with makeArray, and frees the memory allo-
cated to the array.
*/
void freeArray(void *array)
{
    // free memory from the first element of the array
    free((int *)array - 1);
}