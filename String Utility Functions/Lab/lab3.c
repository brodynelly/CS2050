#include "lab3.h"
#include <string.h>


// prototypes
char * strAlloc(int size);
int strLen(char *str);
void strCpy(char *source, char *dest);
int strCmp(char *source, char *dest);
void strFree(char *str);


int main(){
    int sorSize = 5; // size of source array 
    int desSize = 7; // size of dest array 
    
    char *source;
    char *dest;  
    // create string str
    source = strAlloc(sorSize);
    dest = strAlloc(desSize); 

    printf("%d \n", ((int*)source)[-1]);

    strCpy(source, dest); 
    strCmp(source, dest);
    strFree(source);
    strFree(dest); 
}

// creates an char array with the size stored in the first element
char * strAlloc(int size){

    void * arr = malloc((size) + sizeof(int));
    //checks to see if memory was allocated correctly
	if (arr == NULL) {
        return NULL; 
    }
    arr=((int*)arr)+1;
    ((int*)arr)[-1]=size;
    printf("%d \n", ((int*)arr)[-1]);
	return ((char*)arr);
}

// returns the size of array by calling -1 element 
int strLen(char *str){
    return (((int*)str)[-1]);
}

int strCmp(char *source, char *dest){
    // compaires the two different strings
    // using the helper file of <string> you are able to compaire the two strings seemlessly 
   if(strcmp(source, dest) != 0){
        return 0; 
   }
   else{
        return 1; 
   }
}

void strCpy(char *source, char *dest){

    int i; 
    char temp; 
    for(i = 0; i < strLen(source); i++){
        temp = source[i];
        dest[i] = temp; 
    }

}

void strFree(char *str){
    
    free(((int*)str)-1); 
}