//This is code written by James Lambros
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayoperators.h"
//You can just pass arrayTemp directly for most of these functions
//Calculate the sum of all the elements in the array
float arraysum(int size, float *array){
    float tempSum = 0;
    for(int i = 0; i < size; i++){  //Step through the array and sum the components
        tempSum = tempSum + array[i];
    }
    return tempSum;
}
//Calculate the average of all the elements in the array
float arrayaverage(int size, float sum){
    float tempAverage = sum / size;
    return tempAverage;
}
//Calculate the standard deviation of all the elements of the array.
float arraystd(int size ,float average, float *array){ //This loop needs the average, size of the array, and the array itself. Lik
    float tempDeviationHolder = 0;
    float tempDeviation = 0;
    //https://www.mathsisfun.com/data/standard-deviation-formulas.html
    for(int i = 0; i < size; i++){
        tempDeviationHolder = (array[i] - average);
        tempDeviationHolder = tempDeviationHolder * tempDeviationHolder;
        tempDeviationHolder = (tempDeviationHolder / size);
        tempDeviation = tempDeviation + tempDeviationHolder;
    }
    tempDeviation = sqrt(tempDeviation); //Squaring outside the loop since it was the easiest method.
    return tempDeviation;
}
//Find the smallest element in the array
//I need the array and the size of the array. Should be pretty simple for min and max, just assume that the first number is the min/max. Compare it to the next number, and replace the min/max if needed.
float arraymin(int size, float *array){
    float tempMin = array[0];
    //For this loop, I was considering to make i start at 1 to skip the first number, but I decided against this because what if there is an array of 1 element?
    for(int i = 0; i < size; i++){
        if(array[i] < tempMin){
            tempMin = array[i];
        }
    }
    return tempMin;
}
//Find the largest element in the array
float arraymax(int size, float *array){
    float tempMax = array[0];
    for(int i = 0; i < size; i++){
        if(tempMax < array[i]){
            tempMax = array[i];
        }
    }
    return tempMax;
}
//This function provides the difference between the min and max. Needs to be the ABS, so order really doesn't matter. Change this to just take in the array.
float arraydiff(float min, float max){
    float tempDiff = max - min;
    return abs(tempDiff);
}
//Output the array and the elements. Thinking to display both the size and the elements.
void arrayoutput(int size, float *array){
    printf("The total size of the array is %d elements\n", size);
    for(int i = 0; i < size; i++){
        printf("The %d element is %f\n", i+1, array[i]);
    }
}
//Perform an arithmatic shift LEFT on the array. Aka no numbers should be lost, wrap around.
void arrayleftshift(int size, float *array){
    //Here I am filling the new array, storing the first element seperatly so it isn't lost
    float firstElement = array[0];
    for(int i = 0; i < size-1; i++){
        array[i] = array[i+1];
    }
    array[size - 1] = firstElement; /*Make the last element of the new array the first element. array[size] isn't valid, I was struggling with that for an embarrasing amount of time */
}
//Average each element with one of its neighbors. No element should be touched twice, and if there are an odd number of elements drop the last element. Should be half the size of the original array.
//https://stackoverflow.com/questions/3602827/what-is-the-behavior-of-integer-division
//https://stackoverflow.com/questions/12380758/error-function-returns-address-of-local-variable
float* averagedarray(int size, float *array){
    int newSize = size/2; //Rounds down, what we need, source 1
    float *newArray = (float *)malloc(newSize * sizeof(float));
    float tempOne = 0;
    float tempTwo = 0;
    int loopVar = 0;
    for(int i = 0; i < newSize; i++){
        tempOne = array[(loopVar)];
        tempTwo = array[(loopVar+1)];
        newArray[i] = (tempOne + tempTwo)/2; //Average the two elements
        loopVar = (i+1) * 2; //We need to not repeat an element, so we move in units of 2
    }
    return newArray;
}
