# Array Manipulation Functions README

This README provides an overview of a set of functions designed for array manipulation in C. The code includes functions for creating dynamic arrays, searching elements, comparing elements, and freeing memory.

## Table of Contents

1. [Introduction](#introduction)
2. [Usage](#usage)
3. [Function Descriptions](#function-descriptions)
4. [Example](#example)
5. [Memory Management](#memory-management)

## Introduction

This code includes several functions that can be used to manage arrays in C. These functions allow you to create dynamic arrays, search for elements using binary search, compare elements based on a specified criterion, and free the memory allocated for arrays.

## Usage

To use the provided code for array manipulation, you should include the "lab9.h" header file in your C program. The following steps outline how to use the array manipulation functions:

1. **Creating an Array**: Use `makeArray(arraySize, elementSize)` to allocate memory for an array with the specified size and element size. This function returns a pointer to the array.

2. **Getting Array Size**: Retrieve the size of the array using `getSize(array)`.

3. **Binary Search**: Search for elements in the array using `searchClients(array, query)`. This function performs a binary search and returns the index of the query element or -1 if not found.

4. **Comparing Elements**: Use `compareClients(a, b)` to compare two elements based on a specific criterion. This function returns a negative number if `a` is less than `b`, a positive number if `a` is greater than `b`, or 0 if they are equal.

5. **Freeing Memory**: Free the memory allocated for the array using `freeArray(array)`.

## Function Descriptions

Here's a brief description of each function provided in the code:

- `void *makeArray(int arraySize, int elementSize)`: Allocates memory for an array with the given size and element size and returns a pointer to the array.

- `int getSize(void *array)`: Retrieves the size of the array.

- `int searchClients(Client *array, Client *query)`: Performs a binary search on the array and returns the index of the query element or -1 if not found.

- `int binarySearch(Client *array, int left, int right, Client *query)`: Performs binary search recursively on a sorted array.

- `int compareClients(Client *a, Client *b)`: Compares two elements based on their `accountWorth` members and returns a negative, positive, or zero value accordingly.

- `void freeArray(void *array)`: Frees the memory allocated for the array.

## Example

Here's an example of how to use the provided code to create, search, and free an array:

```c
#include "lab9.h"

int main() {
    // Create an array of Clients
    Client *array = makeArray(10, sizeof(Client));

    // Fill the array with Client data (omitted for brevity)

    // Search for a specific Client in the array
    Client queryClient;
    // Initialize queryClient (omitted for brevity)
    int index = searchClients(array, &queryClient);
    if (index != -1) {
        // Client found at index
    } else {
        // Client not found
    }

    // Free the memory allocated for the array
    freeArray(array);

    return 0;
}
```

## Memory Management   


Certainly! Here's the README content in Markdown format for easy export as a .md file:

markdown
Copy code
# Array Manipulation Functions README

This README provides an overview of a set of functions designed for array manipulation in C. The code includes functions for creating dynamic arrays, searching elements, comparing elements, and freeing memory.

## Table of Contents

1. [Introduction](#introduction)
2. [Usage](#usage)
3. [Function Descriptions](#function-descriptions)
4. [Example](#example)
5. [Memory Management](#memory-management)
6. [Contributing](#contributing)
7. [License](#license)

## Introduction

This code includes several functions that can be used to manage arrays in C. These functions allow you to create dynamic arrays, search for elements using binary search, compare elements based on a specified criterion, and free the memory allocated for arrays.

## Usage

To use the provided code for array manipulation, you should include the "lab9.h" header file in your C program. The following steps outline how to use the array manipulation functions:

1. **Creating an Array**: Use `makeArray(arraySize, elementSize)` to allocate memory for an array with the specified size and element size. This function returns a pointer to the array.

2. **Getting Array Size**: Retrieve the size of the array using `getSize(array)`.

3. **Binary Search**: Search for elements in the array using `searchClients(array, query)`. This function performs a binary search and returns the index of the query element or -1 if not found.

4. **Comparing Elements**: Use `compareClients(a, b)` to compare two elements based on a specific criterion. This function returns a negative number if `a` is less than `b`, a positive number if `a` is greater than `b`, or 0 if they are equal.

5. **Freeing Memory**: Free the memory allocated for the array using `freeArray(array)`.

## Function Descriptions

Here's a brief description of each function provided in the code:

- `void *makeArray(int arraySize, int elementSize)`: Allocates memory for an array with the given size and element size and returns a pointer to the array.

- `int getSize(void *array)`: Retrieves the size of the array.

- `int searchClients(Client *array, Client *query)`: Performs a binary search on the array and returns the index of the query element or -1 if not found.

- `int binarySearch(Client *array, int left, int right, Client *query)`: Performs binary search recursively on a sorted array.

- `int compareClients(Client *a, Client *b)`: Compares two elements based on their `accountWorth` members and returns a negative, positive, or zero value accordingly.

- `void freeArray(void *array)`: Frees the memory allocated for the array.

## Example

Here's an example of how to use the provided code to create, search, and free an array:

```c
#include "lab9.h"

int main() {
    // Create an array of Clients
    Client *array = makeArray(10, sizeof(Client));

    // Fill the array with Client data (omitted for brevity)

    // Search for a specific Client in the array
    Client queryClient;
    // Initialize queryClient (omitted for brevity)
    int index = searchClients(array, &queryClient);
    if (index != -1) {
        // Client found at index
    } else {
        // Client not found
    }

    // Free the memory allocated for the array
    freeArray(array);

    return 0;
}
Memory Management
The code includes functions for proper memory management to prevent memory leaks. It is essential to call freeArray(array) when you are done using the dynamically allocated array to release all allocated memory.