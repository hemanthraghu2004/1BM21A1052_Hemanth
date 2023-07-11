#include <iostream>
#include <vector>


void merge(std::vector<int>& arr, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = 0;
    std::vector<int> temp(right - left + 1);


    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }


    while (i <= mid) {
        temp[k++] = arr[i++];
    }


    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}


void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) {

        return;
    }

    int mid = left + (right - left) / 2;  // Calculate the middle index


    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}


void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr = {9, 3, 17, 1, 25, 6, 11};
    int size = arr.size();

    std::cout << "Original array: ";
    printArray(arr);

    mergeSort(arr, 0, size - 1);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
