#include "lab8.h"
//----------------------------------------------------------------
typedef struct Node
{
    void *data;
    int priority;
    struct Node *next;
} Node;
//----------------------------------------------------------------
typedef struct Info
{
    Node *front;
    Node *rear;
    int size;
    int ec;
} Info;
// ----------------------------------------------------------------
// functions prototypes
int pqGetErrorCode(PQueue q);
//-2
// O(1)
PQueue pqInit();
//-3
// O(n)
int pqInsert(void *data, int priority, PQueue q);
//-4
// O(1)
void *pqRemoveMax(PQueue q);
//-5
// O(1)
void *pqPeek(PQueue q);
//-6
// O(1)
int pqGetSize(PQueue q);
//-7
// O(n)
void pqFree(PQueue q);

int main()
{
}

// O(1)
/*
This function returns the error code from the most recently executed PQueue operation. 0
implies success, 1 implies out-of-memory error. Some functions may document additional error
conditions
*/
int pqGetErrorCode(PQueue q)
{
    return q.info->ec; // error code
}
/*
This function returns an initialized PQueue variable. Every queue variable must be initialized
before applying subsequent queue functions.
*/
// O(1)
PQueue pqInit()
{
    PQueue q;
    q.info = malloc(sizeof(Info)); // initialize queue and allocate memory for info structure
    if (q.info == NULL)
    { // malloc check
        q.info = NULL;
        printf("Error initializing stack\n"); // error message
        return q;                             // return NULL queue
    }
    q.info->front = q.info->rear = NULL; // initialize front and rear pointers to NULL
    q.info->size = 0;                    // size is 0
    q.info->ec = 0;                      // error code is 0
    return q;                            // return queue
}
/*
This function enqueues an object and its associated priority (int) into the PQueue. For conve-
nience, error code is returned directly (and also can be obtained via pqGetErrorCode)
*/
// O(n)
int pqInsert(void *data, int priority, PQueue q)
{
    Node *new_node = malloc(sizeof(Node)); // allocate memory for new node
    if (new_node == NULL)
    {                      // malloc check
        q.info->ec = 1;    // out-of-memory error
        return q.info->ec; // return error code
    }
    new_node->data = data;         // assign data to new node
    new_node->priority = priority; // assign priority to new node
    new_node->next = NULL;         // initialize next pointer to NULL
    if (q.info->front == NULL)
    {                             // if queue is empty
        q.info->front = new_node; // assign new node to front pointer
        q.info->rear = new_node;  // assign new node to rear pointer
    }
    else
    {                               // if queue is not empty
        Node *curr = q.info->front; // assign new node to
        Node *prev = NULL;          // assign new node to previous node
        while (curr != NULL && curr->priority >= new_node->priority)
        {                      // while curr is not NULL and curr->priority is greater than new_node->priority
            prev = curr;       // assign new node to previous node
            curr = curr->next; // assign new node to next node
        }
        if (prev == NULL)
        {                                   // if curr is NULL
            new_node->next = q.info->front; // assign new node to front pointer
            q.info->front = new_node;       // assign new node to front pointer
        }
        else
        {
            new_node->next = prev->next; // assign new node to previous node's next pointer
            prev->next = new_node;       // assign new node to previous node's next pointer
        }
        if (new_node->next == NULL)
        {                            // if new_node's next pointer is NULL
            q.info->rear = new_node; // assign new node to rear pointer
        }
    }
    q.info->size++;    // increment size
    q.info->ec = 0;    // reset error code
    return q.info->ec; // return error code
}
/*
This function returns the user object with highest priority, after removing it from the queue. If
two objects have the same priority, then they are returned in FIFO order. NULL is returned if PQueue is
empty and error code is set to 2
*/
// O(1)
void *pqRemoveMax(PQueue q)
{
    if (q.info->front == NULL)
    {                   // if queue is empty
        q.info->ec = 2; // empty queue error
        return NULL;    // return NULL
    }
    Node *temp = q.info->front; // assign temp to front node
    void *data = temp->data;    // assign data to temp
    q.info->front = temp->next; // assign temp's next pointer to front node's next pointer
    if (q.info->front == NULL)
    {
        q.info->rear = NULL;
    }               // if queue is empty
    free(temp);     // free memory
    q.info->size--; // decrement size
    q.info->ec = 0; // reset error code
    return data;    // return
}
/*
This function returns the user object with the highest priority, without removing it from the
Queue
*/
// O(1)
void *pqPeek(PQueue q)
{
    if (q.info->front == NULL)
    {                   // if queue is empty
        q.info->ec = 2; // empty queue error
        return NULL;    // empty
    }
    return q.info->front->data;
}
/*
This function returns the number of objects in the PQueue.*/
// O(1)
int pqGetSize(PQueue q)
{
    return q.info->size; // return size
}
/*
This function uninitializes a queue and frees all memory associated with it
*/
// O(n)
void pqFree(PQueue q)
{
    Node *curr = q.info->front; // assign new node to curr
    while (curr != NULL)
    {                            // while curr is not NULL
        Node *next = curr->next; // assign new node to next
        free(curr);              // free memory
        curr = next;             // assign new node to curr
    }
    free(q.info);  // free memory
    q.info = NULL; // uninitialized the queue
}