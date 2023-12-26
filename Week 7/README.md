# Stack ADT README

This README provides an overview of a set of functions designed to implement a Stack Abstract Data Type (ADT) in C. The code includes functions for initializing a stack, checking its size, pushing and popping elements, peeking at the top element, checking for element existence, and freeing the stack memory.

## Table of Contents

1. [Introduction](#introduction)
2. [Usage](#usage)
3. [Function Descriptions](#function-descriptions)
4. [Example](#example)
5. [Memory Management](#memory-management)

## Introduction

This code includes a collection of functions that extend the capabilities of a basic stack data structure using a linked list. A stack is a linear data structure that follows the Last-In-First-Out (LIFO) principle, where the last element added is the first to be removed. These functions allow for the initialization, manipulation, and management of a stack.

## Usage

To use the provided code for a stack, include the "lab7.h" header file in your C program. The following steps outline how to use the stack functions:

1. **Initialization**: Create an initialized stack using `initStack()`. If initialization fails, the `info` pointer in the returned struct will be set to NULL.

2. **Size**: Get the size of the stack using `getSize(stack)`.

3. **Peek**: Retrieve the data at the top of the stack without removing it using `peekStack(stack)`.

4. **Push**: Push an item onto the top of the stack using `pushStack(stack, data)`. It returns 0 if the insertion was successful, or 1 if it was not.

5. **Pop**: Pop the data item from the top of the stack using `popStack(stack)`. It returns the item popped from the stack or NULL if the stack is empty.

6. **Contains**: Check if a given data item exists on the stack using `stackContains(stack, data)`. It returns 1 if the data exists on the stack, or 0 if it does not.

7. **Freeing Memory**: Free the memory allocated for the stack and its nodes using `freeStack(stack)`.

## Function Descriptions

Here's a brief description of each function provided in the code:

- `Stack initStack()`: Initializes and returns a stack. If initialization fails, the `info` pointer is set to NULL.

- `int getSize(Stack stack)`: Returns the size (number of elements) of the stack.

- `void *peekStack(Stack stack)`: Retrieves the data at the top of the stack without removing it. Returns NULL if the stack is empty.

- `int pushStack(Stack stack, void *data)`: Pushes an item onto the top of the stack. Returns 0 if insertion was successful, or 1 if it failed.

- `void *popStack(Stack stack)`: Pops the data item from the top of the stack. Returns the item popped from the stack or NULL if the stack is empty.

- `int stackContains(Stack stack, void *data)`: Checks if a given data item exists on the stack. Returns 1 if the data exists on the stack, or 0 if it does not.

- `void freeStack(Stack stack)`: Frees all memory allocated to the stack, including its nodes.

## Example

Here's an example of how to use the provided code to create, push, pop, and free a stack:

```c
#include "lab7.h"

int main() {
    // Create an initialized stack
    Stack stack = initStack();

    // Push elements onto the stack (error checking omitted for brevity)
    int data1 = 42;
    pushStack(stack, &data1);
    
    int data2 = 12;
    pushStack(stack, &data2);

    // Get the size of the stack
    int size = getSize(stack);

    // Peek at the top element without removing it
    int *peekedData = peekStack(stack);

    // Pop the top element from the stack
    int *poppedData = popStack(stack);

    // Check if an element exists on the stack
    int searchData = 12;
    int contains = stackContains(stack, &searchData);

    // Free the memory allocated for the stack and its nodes
    freeStack(stack);

    return 0;
}
```

## Memory Management

The code includes functions for proper memory management to prevent memory leaks. It is essential to call freeStack(stack) when you are done using the stack to release all allocated memory.