# Singly Linked List Functions README

This README provides an overview of a set of functions designed to manipulate a singly linked list in C. The code includes functions for creating a list, obtaining its size, inserting at the tail, removing from the head, and freeing the list memory.

## Table of Contents

1. [Introduction](#introduction)
2. [Usage](#usage)
3. [Function Descriptions](#function-descriptions)
4. [Example](#example)
5. [Memory Management](#memory-management)

## Introduction

The provided code includes a collection of functions to work with singly linked lists. These functions allow you to create, manipulate, and manage a linked list of data elements. A singly linked list is a data structure that consists of a sequence of elements, each containing a reference to the next element.

## Usage

To use the provided code for linked list operations, include the "lab5.h" header file in your C program. The following steps outline how to use the linked list functions:

1. **Create a List**: Initialize a new linked list using `makeList(&list)`. This function will always return 0.

2. **Get List Size**: Determine the number of elements in the list using `getSize(list)`.

3. **Insert at Tail**: Insert a data element at the tail of the list using `insertAtTail(&list, data)`. It returns 0 if insertion was successful, or 1 if it failed.

4. **Remove from Head**: Remove the element at the head of the list using `removeFromHead(&list)`. It returns the data removed from the list or NULL if the list was empty.

5. **Free List Memory**: Free the memory allocated for the list and its nodes using `freeList(&list)`.

## Function Descriptions

Here is a brief description of each function provided in the code:

- `int makeList(Node **list)`: Initializes the provided pointer to Node * to an empty list and always returns 0.

- `int getSize(Node *list)`: Returns the number of elements in the list. If the list is empty, it returns 0.

- `int insertAtTail(Node **list, void *data)`: Inserts a data element at the tail of the list. Returns 0 if insertion was successful, or 1 if it failed.

- `void *removeFromHead(Node **list)`: Removes the element at the head of the list (if any) and returns the data removed or NULL if the list was empty.

- `void freeList(Node **list)`: Frees all memory allocated for the list and its nodes. Sets the `list` pointer to NULL after freeing. Note that data on the list is not considered part of the memory allocated to the list.

## Example

Here's an example of how to use the provided code to create, manipulate, and free a linked list:

```c
#include "lab5.h"

int main() {
    // Create an initialized linked list
    Node *list;
    makeList(&list);

    // Insert elements at the tail (error checking omitted for brevity)
    int data1 = 42;
    insertAtTail(&list, &data1);
    
    int data2 = 12;
    insertAtTail(&list, &data2);

    // Get the size of the list
    int size = getSize(list);

    // Remove an element from the head
    void *removedData = removeFromHead(&list);

    // Free the memory allocated for the list and its nodes
    freeList(&list);

    return 0;
}
```

## Memory Management

The code includes functions for proper memory management to prevent memory leaks. It is essential to call freeList(&list) when you are done using the linked list to release all allocated memory.