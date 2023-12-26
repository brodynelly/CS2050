# Binary Search Tree (BST) README

This README provides an overview of the code and functions implemented for a Binary Search Tree (BST). The code is written in C and includes various functions for creating, manipulating, and freeing a BST.

## Table of Contents

1. [Introduction](#introduction)
2. [Usage](#usage)
3. [Function Descriptions](#function-descriptions)
4. [Example](#example)
5. [Memory Management](#memory-management)

## Introduction

A Binary Search Tree (BST) is a data structure that maintains a set of values, providing efficient insertion, deletion, and searching operations. In this code, we have implemented a basic BST data structure along with several functions to interact with it.

## Usage

To use the provided code for a BST, you should include the "lab11.h" header file in your C program. The following steps outline how to use the BST functions:

1. **Initialization**: Create a new BST using `initBST()`. This function returns a pointer to an empty BST.

2. **Insertion**: Insert values into the BST using `insertBST(tree, data)`. This function adds a new element to the tree, maintaining the binary search tree property.

3. **Size**: Retrieve the size (number of elements) of the BST using `getSizeBST(tree)`.

4. **Minimum Value**: Find the minimum value in the BST using `getMinBST(tree)`.

5. **Pre-order Traversal**: Print the elements of the BST in pre-order using `preOrderPrintBST(tree)`.

6. **Memory Cleanup**: Free the memory allocated for the BST and its nodes using `freeBST(tree)`.

## Function Descriptions

Here's a brief description of each function provided in the code:

- `BST* initBST()`: Initializes a new BST and returns a pointer to it.

- `Node* newNode(int data)`: Creates a new node with the given data.

- `Node* insertBSTHelper(Node* node, int data)`: Helper function for recursively inserting a new node into the BST.

- `int insertBST(BST* tree, int data)`: Inserts a new element into the BST and updates its size.

- `int getSizeBST(BST* tree)`: Returns the number of elements in the BST.

- `int getMinBST(BST* tree)`: Returns the minimum value in the BST.

- `void preOrderPrintBST(BST* tree)`: Prints the elements of the BST in pre-order.

- `void freeHelper(Node* node)`: Helper function for recursively freeing the memory of BST nodes.

- `void freeBST(BST* tree)`: Frees all memory allocated to the BST.

## Example

Here's a simple example of how to use the provided code to create, manipulate, and free a BST:

```c
#include "lab11.h"

int main() {
    // Create a new binary search tree
    BST* tree = initBST();

    // Insert values
    insertBST(tree, 50);
    insertBST(tree, 30);
    insertBST(tree, 70);
    insertBST(tree, 20);
    insertBST(tree, 40);
    insertBST(tree, 60);
    insertBST(tree, 80);

    // Print the tree in pre-order traversal
    printf("Pre-order traversal: ");
    preOrderPrintBST(tree);

    // Get and print the size of the tree
    int size = getSizeBST(tree);
    printf("Size of the tree: %d\n", size);

    // Get and print the minimum value in the tree
    int min = getMinBST(tree);
    printf("Minimum value in the tree: %d\n", min);

    // Free the memory allocated for the tree
    freeBST(tree);

    return 0;
}
```

## Memory Management

The code includes functions for proper memory management to prevent memory leaks. It is essential to call freeBST(tree) when you are done using the BST to release all allocated memory.
