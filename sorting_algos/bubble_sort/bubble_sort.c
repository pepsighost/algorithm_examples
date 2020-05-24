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