#include "lab7.h"

/* These ADT's add to the stack struct to gain the ability to navigate a linked list*/
typedef struct Node Node;
typedef struct Node {
    void *data;
    Node *next;
}Node;
struct Info {
    Node *top;
    int size;
};
/* prototypes for function */
Stack initStack();
int getSize(Stack s);
void * peekStack(Stack s);
int pushStack(Stack s, void *data);
void * popStack(Stack s);
int stackContains(Stack s, void *data);
void freeStack(Stack s);

int main(){

}

// This function will initialize and return a Stack. If initialization fails, the info pointer in the
// returned struct must be set to NULL. Your grade for this function will also include your stack imple-
// mentation.
Stack initStack() {
    Stack s; s.info=malloc(sizeof(Info)); //initializes new struct by dynamically allocating it space
    if(s.info==NULL) { // malloc check 
        s.info=NULL;
        printf("Error initializing stack\n"); //printf
        return s;
    }
    s.info->top=NULL; // set top pointer to point towards NULL
    s.info->size=0;
    return s;
}
// Function to return the size of the stack
int getSize(Stack s) {
    return s.info->size;
}
// Function to return the data at the top of the stack without removing it
void *peekStack(Stack s) {
    if(s.info->top==NULL) { return NULL; } //checks if list is emtpy, if so, returns null
    return s.info->top->data;
}
// This function takes a stack, as well as a data item. It will push the item onto the top of the stack,
// and return 0 if insertion was successful, or 1 if it was not
int pushStack(Stack s, void *data) {
    Node*new=malloc(sizeof(Node)); // dynamically allocates a new node
    if(new==NULL) { return 1; } // malloc check, if fail, return indication that push failed 
    new->data=data; // sets the data of the new node
    new->next=s.info->top; // sets the next pointer of the new node to the current top node 
    s.info->top=new; // setting top pointer to new node
    s.info->size++; // increment size by one 
    return 0;  // return success
}
// This function takes a stack, and pops the data item from the top of the stack. It returns the item
// popped from the stack, or NULL if the stack is empty
void *popStack(Stack s) {
    if(s.info->top==NULL) { return NULL; } // check if stack is emtpy 
    Node*temp=s.info->top; // store the current top node in a temp node
    void*data=temp->data;  // store the data of the current top node 
    s.info->top=temp->next; // point towards the next node after temp
    s.info->size--; // decrement size of the list by one
    free(temp); // free node to prevent memory leak
    return data;
}
// his function takes a stack, as well as a data item. It returns 1 if the given data exists on the
// stack, or 0 if it does not.
int stackContains(Stack s, void *data) {
    Node *temp=s.info->top; // set new node to a temp node to traverse through stack
    while(temp) {  // needs to cast as you are unable to compaire void *data with one->another
        if(*(int *)temp->data == *(int *)data) {  return 1; }
        temp=temp->next;
    }
    return 0;
}
// This function takes a stack, and frees all memory allocated to the stack. Remember that data
// which have been inserted onto the stack are not considered part of the memory allocated to
// the stack.
void freeStack(Stack s) {
    Node*temp=s.info->top;  // sets current node to top of stack 
    while(temp!=NULL) { // traverses through list 
        Node*nextNode=temp->next; // place holder for the next node, so we can free current node iwhtout confliction 
        free(temp); // free current node
        temp=nextNode; // set current node to the next node
    }
    free(s.info); // free info node 
    s.info=NULL; // set stack to NULL
}