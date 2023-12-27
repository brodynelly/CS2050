# Linked List Functions README

This README provides an overview of a set of functions designed to manipulate a singly linked list in C. The code includes functions for creating a list, obtaining its size, accessing elements by index, inserting at the head, removing from the tail, and freeing the list memory.

## Table of Contents

1. [Introduction](#introduction)
2. [Usage](#usage)
3. [Function Descriptions](#function-descriptions)
4. [Example](#example)
5. [Memory Management](#memory-management)

## Introduction

The provided code includes a collection of functions to work with singly linked lists. These functions allow you to create, manipulate, and manage a linked list of data elements. A linked list is a data structure that consists of a sequence of elements, each containing a reference (link) to the next element.

## Usage

To use the provided code for linked list operations, include the "lab6.h" header file in your C program. The following steps outline how to use the linked list functions:

1. **Create a List**: Initialize a new linked list using `makeList(&list)`. If initialization fails, the `list` pointer will be set to NULL.

2. **Get List Size**: Determine the number of elements in the list using `getSize(list)`.

3. **Access Element by Index**: Retrieve an element at a specified index in the list using `getAtIndex(list, index)`. It returns the element or NULL if the index is invalid.

4. **Insert at Head**: Insert a data element at the head of the list using `insertAtHead(list, data)`. It returns 0 if insertion was successful, or 1 if it failed.

5. **Remove from Tail**: Remove the element at the tail of the list using `removeFromTail(list)`. It returns the data removed from the list or NULL if the list was empty.

6. **Free List Memory**: Free the memory allocated for the list and its nodes using `freeList(&list)`.

## Function Descriptions

Here is a brief description of each function provided in the code:

- `int makeList(Node **list)`: Initializes and returns a linked list. If initialization fails, the `list` pointer is set to NULL.

- `int getSize(Node *list)`: Returns the number of elements in the list.

- `void *getAtIndex(Node *list, int index)`: Retrieves an element at the specified index in the list or returns NULL if the index is invalid.

- `int insertAtHead(Node *list, void *data)`: Inserts a data element at the head of the list. Returns 0 if insertion was successful, or 1 if it failed.

- `void *removeFromTail(Node *list)`: Removes the element at the tail of the list (if any) and returns the data removed or NULL if the list was empty.

- `void freeList(Node **list)`: Frees all memory allocated for the list and its nodes. Sets the `list` pointer to NULL after freeing.

## Example

Here's an example of how to use the provided code to create, manipulate, and free a linked list:

```c
#include "lab6.h"

int main() {
    // Create an initialized linked list
    Node *list;
    int createResult = makeList(&list);

    // Insert elements at the head (error checking omitted for brevity)
    int data1 = 42;
    insertAtHead(list, &data1);
    
    int data2 = 12;
    insertAtHead(list, &data2);

    // Get the size of the list
    int size = getSize(list);

    // Access elements by index
    void *element = getAtIndex(list, 1);

    // Remove an element from the tail
    void *removedData = removeFromTail(list);

    // Free the memory allocated for the list and its nodes
    freeList(&list);

    return 0;
}
```

## Memory Management

The code includes functions for proper memory management to prevent memory leaks. It is essential to call freeList(&list) when you are done using the linked list to release all allocated memory.