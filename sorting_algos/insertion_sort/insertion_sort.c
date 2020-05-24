/*
    Insertion sort

    for each element in the array:
        treat every element before the element as sorted 
        Go backwards through the sorted portion of the array to see where to "insert"
            the element in question
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createRandArray(int arr[], int size, int maxVal);
void printArray(int arr[], int size);
void insertionSort(int arr[], int size);

int main(void){

    // seed the random generator
    srand((unsigned)time(NULL));

    int size, maxValue;

    printf("Size of array: ");
    scanf("%d", &size);
    printf("Maximum value: ");
    scanf("%d", &maxValue);

    // create array
    int array[size];
    createRandArray(array, size, maxValue);

    printf("Original array: ");
    printArray(array, size);

    // sort array
    insertionSort(array, size);

    printf("Sorted array: ");
    printArray(array, size);

}

void createRandArray(int arr[], int size, int maxVal){
    
    for (int i = 0; i < size; i++){
        arr[i] = rand() % (maxVal + 1);
    }

}

void printArray(int arr[], int size){

    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

}

void insertionSort(int arr[], int size){

    int tempVal;
    for (int i = 1; i < size; i++){
        //printf("\n");
        //printArray(arr, size);
        for (int j = i - 1; j >= 0; j--){
            if (arr[j] <= arr[j+1]){
                break;
            }
            tempVal = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = tempVal;
            //printArray(arr, size);
        }
    }
}