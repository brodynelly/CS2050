# Array Operations README

This README provides an overview of a set of functions in C for working with arrays. The code includes functions for calculating the average value of an array and summing positive integers.

## Table of Contents

1. [Introduction](#introduction)
2. [Usage](#usage)
3. [Function Descriptions](#function-descriptions)
4. [Example](#example)

## Introduction

The provided code includes a collection of functions for performing basic operations on integer arrays in C. These functions allow you to calculate the average value of an array and find the sum of positive integers in the array. 

## Usage

To use the provided code for array operations, include the "lab1.h" header file in your C program. The following steps outline how to use these functions:

1. **Generate an Array**: Create an array of integers and populate it with random values (or any values of your choice). Ensure that you pass the array and its size to the functions.

2. **Calculate Average Value**: Use the `getAverage(array, size, &result)` function to calculate the average value of the array. The result will be stored in the `result` variable, which you pass by reference. The function returns 1 if the calculation was successful or 0 if there was an error (e.g., division by zero).

3. **Sum Positive Integers**: Use the `sumPositive(array, size, &result)` function to calculate the sum of positive integers in the array. The result will be stored in the `result` variable, which you pass by reference. The function returns 1 if the calculation was successful or 0 if there were no positive integers in the array.

## Function Descriptions

Here is a brief description of each function provided in the code:

- `int getAverage(int array[], int size, float *result)`: Calculates the average value of the array and stores it in the `result` variable. Returns 1 if the calculation was successful or 0 if there was an error.

- `int sumPositive(int array[], int size, int *result)`: Calculates the sum of positive integers in the array and stores it in the `result` variable. Returns 1 if the calculation was successful or 0 if there were no positive integers in the array.

## Example

Here's an example of how to use the provided code to create an array, calculate its average value, and sum positive integers:

```c
#include "lab1.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int arrSize = 10; 
    int data[arrSize];

    // Populate the array with random values
    printf("The array data:\n[");
    for (int i = 0; i < arrSize; ++i) {
        data[i] = (rand() % 10) + 1;
        printf("%d%s", data[i], (((i + 1) == arrSize) ? "]\n\n" : ", "));
    }

    float arAvg = 0.0; 
    int arSum = 0; 

    int avg = getAverage(data, arrSize, &arAvg); 
    int sum = sumPositive(data, arrSize, &arSum); 

    if (avg == 1) {
        printf("The average value in the array is: %f\n", arAvg); 
    } else {
        printf("The getAverage calculation was not successful\n"); 
    }

    if (sum == 1) {
        printf("The sum of all positive integers is: %d\n", arSum); 
    } else {
        printf("The sumPositive calculation was not successful\n");
    }

    return 0; 
}
```