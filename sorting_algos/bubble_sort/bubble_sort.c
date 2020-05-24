/*
    Bubble sort

    set a swap counter to a non-zero value
    until the swap counter is 0 (meaning no swaps were performed):
        set the swap counter to 0
        Iterate over array, comparing each pair (where each pair is an element and the element after it) 
            and switching them if they are out of order
        If any switches are performed, increment the swap counter
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createRandArray(int arr[], int size, int maxVal);
void printArray(int arr[], int size);
void bubbleSort(int arr[], int size);

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
    bubbleSort(array, size);

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

void bubbleSort(int arr[], int size){

    int swap_counter = -1, tempVal;

    while (swap_counter != 0){
        swap_counter = 0;

        for (int i = 0; i < size - 1; i++){
            tempVal = arr[i+1];
            if (arr[i] > arr[i+1]){
                arr[i+1] = arr[i];
                arr[i] = tempVal;
                swap_counter++;
            }
        }
    }
}