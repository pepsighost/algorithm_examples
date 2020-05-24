/*
    Merge sort

    Sort the left half of the array
    Sort the right half of the array
    Merge the two halves together
        queue the frontmost elements of each half and have a new, temporary array
        for each item in the array, fill it with the smallest of the two frontmost elements
        each time an item is assigned an element, shift the element's respective half to queue up a new front element 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createRandArray(int arr[], int size, int maxVal);
void printArray(int arr[], int size);
void mergeSort(int arr[], int startIndex, int endIndex);

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
    mergeSort(array, 0, size);

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

void mergeSort(int arr[], int startIndex, int endIndex){

    // array size is 1
    if (endIndex - startIndex == 1){
        return;
    }

    int sizeOfMerged = endIndex - startIndex;
    int middleIndex = ((sizeOfMerged) / 2) + startIndex;

    //printf("\nMerging array...\n");
    //printArray(arr, sizeOfMerged);

    // sort left and right halves
    mergeSort(arr, startIndex, middleIndex);
    mergeSort(arr, middleIndex, endIndex);

    // create new array to merge the two halves together
    int mergedArr[sizeOfMerged];

    int nextLeft = startIndex, nextRight = middleIndex;
    
    for (int i = 0; i < sizeOfMerged; i++){
        // check if one half of the array has already been merged completely
        if (nextLeft >= middleIndex){
            mergedArr[i] = arr[nextRight];
            nextRight++;
        }
        else if (nextRight >= endIndex){
            mergedArr[i] = arr[nextLeft];
            nextLeft++;
        }
        // if both halves haven't merged completely, check the first element of the unmerged halves
        else if (arr[nextLeft] < arr[nextRight]){
            mergedArr[i] = arr[nextLeft];
            nextLeft++;
        }
        else {
            mergedArr[i] = arr[nextRight];
            nextRight++;
        }
    }

    //printf("Merged array:\n");
    //printArray(mergedArr, sizeOfMerged);

    // put merged array into original array
    for (int i = 0; i < sizeOfMerged; i++){
        arr[startIndex + i] = mergedArr[i];
    }

    return;

}