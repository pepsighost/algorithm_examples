#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createRandArray(int arr[], int size, int maxVal);
void printArray(int arr[], int size);
void selectionSort(int arr[], int size);

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
    selectionSort(array, size);

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

void selectionSort(int arr[], int size){

    int smallest_value, smallest_value_index;

    for (int i = 0; i < size - 1; i++){
        smallest_value = arr[i];
        smallest_value_index = i;

        for (int j = i + 1; j < size; j++){
            if (arr[j] < smallest_value){
                smallest_value = arr[j];
                smallest_value_index = j;            }
        }

        arr[smallest_value_index] = arr[i];
        arr[i] = smallest_value;
    }
}