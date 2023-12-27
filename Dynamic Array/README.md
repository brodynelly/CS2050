# Dynamic Array Operations README

This README provides an overview of a set of functions designed to manage a dynamic array in C. The code includes functions for creating an array, getting its size, counting items with greater IDs, and freeing the array memory.

## Table of Contents

1. [Introduction](#introduction)
2. [Usage](#usage)
3. [Function Descriptions](#function-descriptions)
4. [Example](#example)
5. [Memory Management](#memory-management)

## Introduction

The provided code includes a collection of functions to work with dynamic arrays. These functions allow you to create, manipulate, and manage an array of data elements. The dynamic array automatically stores its size, and you can count items with IDs greater than or equal to a specified minimum.

## Usage

To use the provided code for dynamic array operations, include the "lab4.h" header file in your C program. The following steps outline how to use the dynamic array functions:

1. **Create an Array**: Initialize a new dynamic array using `makeArray(arraySize, elementSize)`. This function allocates memory for the array and returns a pointer to it. If allocation fails, it returns NULL.

2. **Get Array Size**: Obtain the size of the array using `getSize(array)`.

3. **Count Items with Greater IDs**: Count the number of items with IDs greater than or equal to a specified minimum using `countGreaterID(array, minID)`.

4. **Free Array Memory**: Free the memory allocated for the array using `freeArray(array)`.

## Function Descriptions

Here is a brief description of each function provided in the code:

- `void *makeArray(int arraySize, int elementSize)`: Allocates memory for an array with the given size and stores the size before the start of the array. Returns a pointer to the array or NULL if allocation fails.

- `int getSize(void *array)`: Returns the size of the array, which was stored before the array.

- `int countGreaterID(InventoryItem *items, int minID)`: Counts the number of items in the array with IDs greater than or equal to the specified `minID`.

- `void freeArray(void *array)`: Frees the memory allocated for the array, including the size stored before the array.

## Example

Here's an example of how to use the provided code to create a dynamic array, add elements, count items with greater IDs, and free the memory:

```c
#include "lab4.h"

int main() {
    // Create an array with a size of 3 elements and the size of each element
    int arraySize = 3;
    InventoryItem *inv = makeArray(arraySize, sizeof(InventoryItem));

    // Check if the array was allocated correctly
    if (inv == NULL) {
        printf("Memory was not allocated correctly!\n");
        return -1;
    }

    // Add elements to the array
    for (int i = 0; i < getSize(inv); i++) {
        inv[i].ID = i * 78;
        printf("Employee %d has ID: %d\n", i, inv[i].ID);
    }

    // Count employees with IDs greater than or equal to minID
    int minID = 75;
    printf("The number of employees with an ID greater than %d is: %d\n", minID, countGreaterID(inv, minID));

    // Free the allocated memory
    freeArray(inv);

    return 0;
}
```

## Memory Management

The code includes functions for proper memory management to prevent memory leaks. It is essential to call freeArray(array) when you are done using the dynamic array to release all allocated memory.