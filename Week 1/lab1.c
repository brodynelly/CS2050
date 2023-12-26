#include "lab1.h"
#include <stdio.h>
#include <stdlib.h>

// prototypes
int getAverage(int array[], int size, float *result); //error occurs when using float when int should've been used
int sumPositive(int array[], int size, int *result);

int main(){
    // creates a list of an array to be passed (pulled from lab0 from week)
    int arrSize = 10; 
    int data[arrSize];

    printf("The array passed:\n[");
    for(int i = 0; i < arrSize; ++i) {
        data[i] = (rand() % 10) + 1;
        printf("%d%s", data[i], (((i + 1) == arrSize) ? "]\n\n" : ", "));
    }

    
    float arAvg = 0; 
    int arSum = 0; 

    int avg = getAverage(data, arrSize, &arAvg); 
    int sum = sumPositive(data, arrSize, &arSum); 

    //determins if getAverage calculations were done correctly 
    if(avg == 1){
        printf("the average value in the array is: %f", arAvg); 
    }
    else{
        printf("the getAverage calulations were not successfull"); 
    }

    // determines if sumPositive calculations were dont correctectly 
    if(sum == 1){
        printf("the sum of all positive integers is: %d", arSum); 
    }
    else{
        printf("the sumPositive calulations were not successfull");
    }

    return 0; 
}
// caclulates the average value in array by pass-by-reference, 
// returns if the average value calculation can occur 
int getAverage(int array[], int size, float *result){

    int temp = 0; 
    for(int i = size; i <= size; i++){
        temp += array[i]; 
    }

    if(temp != 0){
        *result = (temp/size); 
        return 1; 
    }
    else{
        return 0; 
    }
}
// calculates the sum of all positive numbers in the array 
// returns 1 if calculations were successfull and returns 0 otherwise
int sumPositive(int array[], int size, int *result){
        for(int j = size; j < size; j++){
            if(array[j] >= 0){
                *result += array[j]; 
            }
        }

    if((*result > 0)){
        return 1; 
    }
    else{
        return 0; 
    }
}