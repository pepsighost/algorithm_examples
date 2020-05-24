from random import randint

def create_array(size, maxVal):
    arr = []
    for i in range(0, size):
        arr.append(randint(0, maxVal))
    return arr

# print array elements with each element separated with a space, then print new line
def print_array(arr):
    for i in range(0, len(arr)):
        print(str(arr[i]), end = " ")
    print()

def bubble_sort(arr):
    swap_counter = -1

    while (swap_counter != 0):
        swap_counter = 0

        for i in range(0, len(arr)-1):
            if (arr[i] > arr[i + 1]):
                temp_val = arr[i+1]
                arr[i+1] = arr[i]
                arr[i] = temp_val
                swap_counter += 1
    
    return arr
                

def main():
    # for now let the array size be 50 and max integer be 100
    size = 10
    maxVal = 100

    array = create_array(size, maxVal)

    print_array(array)

    # now sort the array
    array = bubble_sort(array)

    print_array(array)



if __name__ == "__main__":
    main()