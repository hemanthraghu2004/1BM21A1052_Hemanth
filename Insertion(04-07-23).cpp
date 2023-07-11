#include <iostream>
#include <vector>

// Insertion Sort function
void insertionSort(std::vector<int>& arr) {
    int size = arr.size();

    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Utility function to print an array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Test the insertionSort function
int main() {
    std::vector<int> arr = {9, 3, 17, 1, 25, 6, 11};

    std::cout << "Original array: ";
    printArray(arr);

    insertionSort(arr);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
