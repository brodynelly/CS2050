#include "lab4.h"

/* Prototypes begin*/
void * makeArray(int arraySize , int elementSize); 
int getSize(void *array); 
int countGreaterID(InventoryItem *items , int minID); 
void freeArray(void *array); 

int main(){

    //create the size for the array 5 elements
    int arraySize=3; 

    // initiate the array
    InventoryItem *inv=makeArray(arraySize, sizeof(InventoryItem));

    //check if array was allocated correctly
    if(inv == NULL){
        printf("Memeory was not allocated correctly!");
        return -1; 
    }

    //for Loop to add some elements into the array. 
    int i; 
    for(i=0;i<getSize(inv);i++){
        inv[i].ID=(i*78); 
        printf("\nThe number %d employee in the array has ID num: %d",i,inv[i].ID); 
    }

    //display the number of employees with an ID greater than minID
    int minID=75; 
    printf("\nThe number of employees with an ID greater that %d is: %d\n",minID,countGreaterID(inv, minID)); 

    //free unallocated memeory
    freeArray(inv); 
    return 0; 
}

/*
makeArray: 
    This function will take an array size, as well as the size of each element in the array. It will
    allocate an array with the given size, and store the getSize before the start of the array as an int. If
    allocating the array was successful, it will return a pointer to the array, otherwise it will return NULL.
*/
 void * makeArray(int arraySize , int elementSize){
    int* arr=malloc((arraySize*elementSize)+sizeof(int));
	if (arr!=NULL) { 
        *arr=arraySize; 
    }
	arr += 1;
	return (arr); //returns NULL even if done correctly because the array will read NULL
 }

 /*
 getSize: 
    This function takes an array which was allocated with makeArray, and returns the size stored
    before the array.
 */
int getSize(void *array){
    int *pntr=array;
    return *(pntr-1); 
}

/*
countGreaterID:
    This function takes an array of InventoryItems, and returns the number of items in the array
    which have an ID greater than or equal to the given minID. 
*/
int countGreaterID(InventoryItem *items , int minID){
    int i, counter=0;
    for(i=0;i<getSize(items);i++){ //get size stored from calling function 
        if(items[i].ID>=minID){ // runs a check of each ID in array while iterating through array
            counter++; //? counts how many instances of minID is above counter
        }
    }
    return counter;
}

/*
freeArray: 
    This function takes an array which was allocated with makeArray, and frees the memory allo-
    cated to the array.
*/
void freeArray(void *array){
    int *pntr=(int*)array; // create pointer to array of caste type int
    free(pntr-1);  // free the unallocated memory including the size stored before the array
}
