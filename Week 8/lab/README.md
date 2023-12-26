# Priority Queue (PQueue) Functions README

This README provides an overview of a set of functions designed for implementing a Priority Queue (PQueue) in C. The code includes functions for initializing a PQueue, inserting elements with priorities, removing the element with the highest priority, and more.

## Table of Contents

1. [Introduction](#introduction)
2. [Usage](#usage)
3. [Function Descriptions](#function-descriptions)
4. [Example](#example)
5. [Memory Management](#memory-management)
6. [Contributing](#contributing)
7. [License](#license)

## Introduction

This code includes several functions for implementing a Priority Queue (PQueue) in C. A Priority Queue is a data structure that allows you to insert elements with associated priorities and retrieve the element with the highest priority.

## Usage

To use the provided code for a Priority Queue, you should include the "lab8.h" header file in your C program. The following steps outline how to use the PQueue functions:

1. **Initialization**: Create an initialized PQueue variable using `pqInit()`. Every PQueue variable must be initialized before applying subsequent PQueue functions.

2. **Insertion**: Insert an object with its associated priority into the PQueue using `pqInsert(data, priority, q)`. This function returns an error code (0 for success, 1 for out-of-memory).

3. **Removing Max Priority**: Remove and return the object with the highest priority using `pqRemoveMax(q)`. This function returns NULL if the PQueue is empty and sets an error code (2 for empty queue).

4. **Peeking Max Priority**: Peek at the object with the highest priority without removing it using `pqPeek(q)`. This function returns NULL if the PQueue is empty and sets an error code (2 for empty queue).

5. **Getting Size**: Get the number of objects in the PQueue using `pqGetSize(q)`.

6. **Getting Error Code**: Retrieve the error code from the most recently executed PQueue operation using `pqGetErrorCode(q)`.

7. **Freeing Memory**: Free the memory allocated for the PQueue and its elements using `pqFree(q)`.

## Function Descriptions

Here's a brief description of each function provided in the code:

- `int pqGetErrorCode(PQueue q)`: Returns the error code from the most recently executed PQueue operation. 0 implies success, 1 implies out-of-memory error, and 2 implies an empty queue.

- `PQueue pqInit()`: Returns an initialized PQueue variable. Every PQueue variable must be initialized before applying subsequent PQueue functions.

- `int pqInsert(void *data, int priority, PQueue q)`: Enqueues an object and its associated priority (int) into the PQueue. Returns an error code (0 for success, 1 for out-of-memory).

- `void *pqRemoveMax(PQueue q)`: Removes and returns the user object with the highest priority from the PQueue. Returns NULL if the PQueue is empty and sets an error code (2 for empty queue).

- `void *pqPeek(PQueue q)`: Returns the user object with the highest priority without removing it from the PQueue. Returns NULL if the PQueue is empty and sets an error code (2 for empty queue).

- `int pqGetSize(PQueue q)`: Returns the number of objects in the PQueue.

- `void pqFree(PQueue q)`: Uninitializes a queue and frees all memory associated with it.

## Example

Here's an example of how to use the provided code to create, insert, remove, and free a Priority Queue:

```c
#include "lab8.h"

int main() {
    // Create an initialized Priority Queue
    PQueue pq = pqInit();

    // Insert objects with priorities into the PQueue (error checking omitted for brevity)
    int data1 = 42;
    pqInsert(&data1, 3, pq);
    
    int data2 = 12;
    pqInsert(&data2, 1, pq);

    int data3 = 99;
    pqInsert(&data3, 2, pq);

    // Remove and retrieve the object with the highest priority
    int *maxPriorityData = pqRemoveMax(pq);

    // Peek at the object with the highest priority
    int *peekedData = pqPeek(pq);

    // Get the number of objects in the PQueue
    int size = pqGetSize(pq);

    // Free the memory allocated for the PQueue and its elements
    pqFree(pq);

    return 0;
}

```

## Memory Management

The code includes functions for proper memory management to prevent memory leaks. It is essential to call pqFree(q) when you are done using the PQueue to release all allocated memory.