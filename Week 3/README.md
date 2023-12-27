# String Utility Functions README

This README provides an overview of a set of string utility functions in C. The code includes functions for allocating and managing character arrays, finding string length, copying strings, comparing strings, and freeing memory.

## Table of Contents

1. [Introduction](#introduction)
2. [Usage](#usage)
3. [Function Descriptions](#function-descriptions)
4. [Example](#example)
5. [Memory Management](#memory-management)

## Introduction

The provided code includes a collection of functions for handling character arrays (strings) in C. These functions allow you to allocate memory for strings, find their length, copy them, compare them, and free the allocated memory.

## Usage

To use the provided code for string utility functions, include the "lab3.h" header file in your C program. The following steps outline how to use these functions:

1. **Allocate a String**: Use `strAlloc(size)` to create a new character array (string) with the specified size. This function allocates memory and returns a pointer to the allocated string. If memory allocation fails, it returns NULL.

2. **Get String Length**: Determine the length of a string using `strLen(str)`. This function returns the size of the string.

3. **Copy Strings**: Copy one string to another using `strCpy(source, dest)`. It performs a character-by-character copy from the source string to the destination string.

4. **Compare Strings**: Compare two strings using `strCmp(source, dest)`. It uses the standard library function `strcmp` to compare the strings and returns 1 if they are equal, or 0 if they are not.

5. **Free String Memory**: Deallocate memory used by a string with `strFree(str)`.

## Function Descriptions

Here is a brief description of each function provided in the code:

- `char *strAlloc(int size)`: Allocates memory for a character array (string) with the specified size. It stores the size before the start of the array and returns a pointer to the allocated string or NULL on failure.

- `int strLen(char *str)`: Returns the length of the string by accessing the size stored before the array.

- `int strCmp(char *source, char *dest)`: Compares two strings using the standard library function `strcmp`. It returns 1 if the strings are equal, or 0 if they are not.

- `void strCpy(char *source, char *dest)`: Copies the characters from the source string to the destination string character by character.

- `void strFree(char *str)`: Frees the memory allocated for the string, including the size stored before the array.

## Example

Here's an example of how to use the provided code to allocate, manipulate, and deallocate strings:

```c
#include "lab3.h"

int main() {
    int sourceSize = 5; // Size of the source string
    int destSize = 7;   // Size of the destination string

    char *source;
    char *dest;

    // Create string source
    source = strAlloc(sourceSize);
    dest = strAlloc(destSize);

    strCpy(source, dest);
    strCmp(source, dest);

    // Free allocated memory
    strFree(source);
    strFree(dest);

    return 0;
}
```

## Memory Management

The code includes functions for proper memory management to prevent memory leaks. Make sure to call strFree(str) when you are done using a string to release the allocated memory.