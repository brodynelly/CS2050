# 2D Array Manipulation README

This README provides an overview of a set of functions in C for working with 2D arrays. The code includes functions for dynamically creating a 2D array, initializing it, multiplying odd elements, and freeing memory.

## Table of Contents

1. [Introduction](#introduction)
2. [Usage](#usage)
3. [Function Descriptions](#function-descriptions)
4. [Example](#example)
5. [Memory Management](#memory-management)
6. [Contributing](#contributing)
7. [License](#license)

## Introduction

The provided code includes a collection of functions for managing 2D arrays in C. These functions allow you to allocate memory for a 2D array, initialize it, multiply odd elements by a given factor, and free the allocated memory.

## Usage

To use the provided code for 2D array manipulation, include the "lab2.h" header file in your C program. The following steps outline how to use these functions:

1. **Allocate a 2D Array**: Use `makeArray(&array, size)` to create a dynamically allocated 2D array of the specified size. This function returns 0 if the array was created successfully or 1 if there was an allocation error.

2. **Initialize the Array**: Use `initArray(array, size)` to set all elements of the array to zero.

3. **Multiply Odd Elements**: Use `multiplyOdd(array, size, multiplicand)` to multiply odd elements of the array by a given `multiplicand`. It returns the count of odd elements that were multiplied.

4. **Free Array Memory**: Deallocate memory used by the 2D array with `freeArray(&array)`.

## Function Descriptions

Here is a brief description of each function provided in the code:

- `int makeArray(int **array, int size)`: Creates a dynamically allocated 2D array of the specified size. It returns 0 on success or 1 on allocation failure.

- `void initArray(int *array, int size)`: Initializes all elements of the array to zero.

- `int multiplyOdd(int *array, int size, int multiplicand)`: Multiplies odd elements in the array by the given `multiplicand` and returns the count of elements that were multiplied.

- `void freeArray(int **array)`: Deallocates the memory used by the 2D array.

## Example

Here's an example of how to use the provided code to create, manipulate, and free a 2D array:

```c
#include "lab2.h"

int main() {
    int len = 4;        // Size of the 2D array
    int **matrix;       // Pointer to the 2D array
    int multiplicand = 3; // Value to multiply odd elements

    // Check if memory was allocated successfully
    if (makeArray(&matrix, len) == 0) {
        initArray(matrix, len);

        // Print the initialized array
        for (int row = 0; row < len; row++) {
            for (int col = 0; col < len; col++) {
                printf("Element at row %d, col %d: %d\n", row, col, matrix[row][col]);
            }
        }

        // Multiply odd elements and count them
        int oddCount = 0;
        for (int row = 0; row < len; row++) {
            oddCount += multiplyOdd(matrix[row], len, multiplicand);
        }

        if (oddCount > 0) {
            printf("There were %d odd elements in the array that were multiplied.\n", oddCount);
        } else {
            printf("There were no odd elements in the array.\n");
        }

        // Free allocated memory
        freeArray(&matrix);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
```

## Memory Management

The code includes functions for proper memory management to prevent memory leaks. Make sure to call freeArray(&array) when you are done using the 2D array to release the allocated memory.