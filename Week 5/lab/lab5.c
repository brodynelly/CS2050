#include "lab5.h"

//prodotypes
int makeList(Node **list);
int getSize(Node *list);
int insertAtTail(Node **list, void *data);
void * removeFromHead(Node **list);
void freeList(Node **list);

int main(){

    // initialize an empty node
    Node*list;


    /*int ec = makeList(&list);
    if(ec==0){
        printf("Node has been inizialized correctly\n\n"); 
    }
    int i; 
    void*pef; 
    for (i=0; i<4; i++) {  
        if(insertAtTail( &list, pef )==0){ 
            printf("the insertion was successful\n"); 
        } 
        else{
            printf("the insertion failed"); 
        }
    }  
    //check to see if get size works // should be 4
    printf("The Size of the List: %d\n",getSize( list ));
    // delete an item from the head // remove one 
    removeFromHead( &list );
    // check if item was deleted properly // should be three
    printf("The Size of the List: %d\n",getSize( list ));
    // free the list 
    */ 
    freeList( &list) ; 
}

/*
This function will initialize the provided pointer to Node * to an empty list. It will always return 0.
*/
int makeList(Node **list){                   // runs a check if memory was allocated correctly 
    *list=NULL;     // points created list towards null value 
    return 0; 
}
/*
This function takes a list, and returns the number of elements on the list. Note that if the list is
empty, the number of elements on the list is 0.
*/
int getSize(Node *list){
    int count=1; // count starts at one for first node
    if(list->next==NULL) {printf("The list is empty\n"); return 0;} // check if the list is empty, if does, returns zero nodes
    while(list->next!=NULL){ // loop all the way till the end of list
        count++; // increment count by one
        list=list->next;  //continue to next node in list
    }
    return count;  // return the number of times list was traversed
}
/*
This function takes a pointer to Node *, and inserts the given data at the tail of the list. It
returns 0 if insertion was successful, or 1 if insertion failed.
*/
int insertAtTail(Node **list, void *data){
    Node*ptr=malloc(sizeof(Node)); //allocated memory for new item in list
    if(!ptr){return 1;} //checks if memory wasn't allocated correctly
    ptr->data=data;     //adds passed value to newly created node
    while(*list!=NULL){ //traverses through list till reaches end
        list=&(*list)->next; //allows the traversal of list, moving from one node to the next
    }
    *list=ptr; //points passed node to newly created node
    return 0; // signalfies that the node was inserted correctly
}
/*
This function takes a pointer to Node *, and removes the element at the head of the list (if
any). It will return the data which was removed from the list, or NULL if the list was empty. You may
assume that no data on the list will be NULL.
*/
void * removeFromHead(Node **list){
    Node*head=*list; //sets a temp node equal to passed node
    if(head==NULL){return NULL;}; //checks if list is empty
    *list=head->next; //points node that was passed to start at next node (deleting the first)
    free(head); //frees old header             
    return (Node*)head; //returns the old header
}

/*
This function takes a pointer to Node *, and frees the memory allocated to the list. After freeing,
it sets the pointer to NULL. Note that the data on the list is not considered part of the memory
allocated to the list.
*/
void freeList(Node **list) {
    Node*ptr=*list; //creates a temp pointer that is the same as passed param
    while(ptr){
        Node*ptrTemp=ptr; //creates second pointer to prevent seg falt for going pass tail node
        ptr=ptr->next; //moves the first pointer by one to set second pointer to be free for next interation
        free(ptrTemp); //frees second pointer that inst needed anymore (will move onto next one)
    }
}
