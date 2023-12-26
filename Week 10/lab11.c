#include "lab11.h"

// Node structure for the binary search tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Binary search tree structure
typedef struct BST {
    Node* root;
    int size;
} BST;

//prototypes
BST * initBST();
Node* newNode(int data); 
Node* insertBSTHelper(Node* node, int data); 
int insertBST(BST *tree, int data);
int getSizeBST(BST *tree);
int getMinBST(BST *tree);
void printBSTHelper(Node* node); 
void preOrderPrintBST(BST *tree);
void freeHelper(Node* node); 
void freeBST(BST *tree);

int main(){
    // Create a new binary search tree
    BST* tree = initBST();
    
    // Insert some values
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


/* 
This function initializes and returns a pointer to a BST struct on success, or NULL if initialization
was not successful. Your grade for this function includes your BST implementation
*/
// O(1)
BST* initBST() {
    // Initializes a new binary search tree by allocating memory for a new tree 
    BST* tree = (BST*)malloc(sizeof(BST));
    if (tree == NULL) {
        printf("Malloc failure for BST\n"); 
        return NULL;
    }

    // setting its root to NULL and size to 0.
    tree->root = NULL;
    tree->size = 0;

    // returns the initialized binary search tree
    return tree;
}

/*
This function takes a BST and a data integer. It will insert the given data onto the tree and
return 0 on success, or 1 if insertion was not successful. You may assume no duplicate items will
be inserted.
*/
Node* newNode(int data) {
    //  Creates a new node with the given data, 
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Malloc failure for creating a new Node\n"); 
        return NULL;
    }
    node->data = data;

    //  left and right children set to NULL
    node->left = NULL;
    node->right = NULL;

    // returns the new node
    return node;
}

//  A helper function to recursively insert a new node 
//  (smaller values on the left, larger values on the right).
Node* insertBSTHelper(Node* node, int data) {
    // Checks if the tree is empty
    if (node == NULL) {
        return newNode(data);
    }

    // recursively insert a new node with the given data in the correct position in the tree,
    if (data < node->data) {
        node->left = insertBSTHelper(node->left, data);
    } else {
        node->right = insertBSTHelper(node->right, data);
    }

    // return the new node
    return node;
}


// O(log(n))
int insertBST(BST* tree, int data) {
    // Checks if the tree is empty
    if (tree == NULL) {
        printf("Insertion was unsuccessful\n"); 
        return 1;
    }

    // Inserts a new node with the given data into the tree
    tree->root = insertBSTHelper(tree->root, data);
    // and updates the tree's size.
    tree->size += 1;
    printf("Insertion was successful\n"); 
    return 0;
}

/*
This function takes a BST and returns the number of elements in the BST.
*/
// O(1)
int getSizeBST(BST* tree) {
    // Checks if the tree is empty
    if (tree == NULL) {
        printf("BST is not valid\n");
        return -1;
    }
    // Returns the size of the tree (number of nodes).
    return tree->size;
}

/*
This function takes a BST and returns the minimum value in the tree. You may assume the tree
is not empty.
*/
// O(log(n))
int getMinBST(BST* tree) {
    // Checks if the tree is empty
    if (tree == NULL || tree->root == NULL) {
        printf("BST is not valid\n"); 
        return -1;
    }

    // Returns the minimum value in the tree.
    Node* current = tree->root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

// A helper function for preOrderPrintBST.
void printBSTHelper(Node* node) {
    // Checks if the node is empty
    if (node == NULL) { 
        return;
    }

    // recursively print the values of the nodes in pre-order traversal (root, left, right)
    printf("%d ", node->data);
    printBSTHelper(node->left);
    printBSTHelper(node->right);
}

/*
This function takes a BST and prints the elements in the BST in pre-order. The lecture slides
discussing this are on Canvas under Modules
*/
// O(n)
void preOrderPrintBST(BST* tree) {
    // Checks if the tree is empty
    if (tree == NULL) {
        printf("BST is not valid\n"); 
        return;
    }

    // //Prints the values of the nodes in the tree in pre-order traversal.
    printBSTHelper(tree->root);
    printf("\n");
}

// recursivley frees the memory allocated for the tree and its nodes.
void freeHelper(Node* node) {
    // checks if the node is valid
    if (node == NULL) {
        return;
    }

    // recursively frees the values of the nodes in pre-order traversal (root, left, right)
    freeHelper(node->left);
    freeHelper(node->right);
    free(node);
}

/*
This function takes a BST and frees all memory allocated to it.
*/
// O(n)
void freeBST(BST* tree) {
    // checks if the tree is valid 
    if (tree == NULL) {
        return;
    }

    // frees the BST
    freeHelper(tree->root);
    free(tree);
    printf("Memory successfully freed\n");
}