#include "lab2.h"

// prototypes
int makeArray(int **array, int size);
void initArray(int *array, int size);
int multiplyOdd(int *array, int size, int multiplicand);
void freeArray(int **array);

int main(){
    //create array and length of array 
    int len = 4;
    int **row; 
    int multiple = 3; 

    //check to see if memory was allocated directly 
    if( (row = malloc(len * sizeof(int *)) )){
        printf("memory was allocated correctly\n");

        //create the second dimension in the array
        if( (makeArray(row, len)) == 0){

            //print out array 
            int j, n; 
            for(j = 0; j < len; j++){
                for(n = 0; n<len; n++){
                    printf("Numbers in row[%d][%d]: %d\n", j, n, row[n][j]); 
                }
            }

            //able to unallocate memory for array 
            freeArray(row);

            // variables to be used in the for loop 
            int row1; 
            // variable to determine amount of odd variables in array
            int didMultipy; 

            // will complete through forloop, looping through each row at a time 
            for(row1 = 1; row1 < len; row1++){
                // checks if any of the elements in the row are odd(by passing through the function), and adding to did multiply if they did!
                didMultipy += multiplyOdd(row[1], len, multiple); 
            }

            //determines how many elements in the array were multiplied (or how many were odd)
            if( didMultipy > 0){
                printf("there were %d elements in the array that were odd", didMultipy); 
            }
            else {printf("there were Zero elements in the array that were odd :(");}

        }else {printf("Second dimension not created :(\n");}
        
    }else {printf("memory was allocated incorrectly\n");}
    
}

//make array
int makeArray(int **array, int size){
    //create a 2D array using size for the size
    int i; 
    for (i = 0; i < size; ++i){
        // allocate storage in array[i] to fit the 2D array 
        //checks if the memory was allocated correctly
        if( !(array[i] = malloc(size * sizeof(int))) ) return 1; 

        // init each element in the array to zero 
        initArray(array[i], size); 
    }
    
    return 0; 
}


void initArray(int *array, int size){
    // sets passed array elements to zero 
    int i; 
    for(i = 0; i < size; ++i){
        array[i] = 0;
    }
}

int multiplyOdd(int *array, int size, int multiplicand){

    int j, oddCounter; 
    oddCounter = 0; 
    for(j = 0; j < size; ++j){
        //checks if current element in the row passed is odd
        if( (array[j]%2) != 0 ){
            // multiplys array by multiplicand and counts that there was an odd character instance
            int temp = array[j];
            array[j] = temp * multiplicand; 
            oddCounter++; 
        }
    }
    return (oddCounter); 
}


void freeArray(int **array){
    // free array 
    free(*array); 
    printf("memory allocated successfully :)\n"); 
}
