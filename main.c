#include "array.h"
#include "arrayoperators.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    /*From what I understand, we need to use the custom structure defined in array.h to dynamically allocate an array with (malloc). We will get the size by taking in a command line arguement, and then fill in the data
     * with whatever I want. I'll fill it with alternating values to make the following operations more coherent. */
    //https://stackoverflow.com/questions/523237/how-to-read-in-numbers-as-command-arguments
    int arraySize = atoi(argv[1]);
    printf("Size is %d\n", arraySize);
    Array array = {arraySize, (float *)malloc(arraySize * sizeof(float))};
    array.size = arraySize;
    //Dynamically allocate that array!
    for(int i =0; i<arraySize; i++){
        array.data[i] = 2 * i; //Allocate with even numbers so we have the same results everytime
    }
    arrayoutput(array.size, array.data); //
    arrayleftshift(array.size, array.data); //
    arrayoutput(array.size, array.data); //Verify the shift happened
    float *newArray= averagedarray(arraySize, array.data); //This returns a new array
    arrayoutput(arraySize, newArray);
    //Deallocate the memory space used by both arrays.
    free(newArray);
    free(array.data);
}
