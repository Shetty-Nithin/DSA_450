#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
1. Bubble Sort: Stable
    Time Complexity = O(n^2)
    Space Complexity = O(1)

    Values will be sort one by one from the begining in the ascending order in this program
    (can make it descending order also).
*/
void bubbleSort(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(arr[i] > arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
}

/*
2. Selection Sort: Not Stable
    Same as bubble sort, but with only n number of swaps
    Time Complexity = O(n^2)
    Space Complexity = O(1)

    Instead of swaping in every successfull comparison as in the Bubble Sort, save the index at which the minimum
    value is present and at replace it in its correct position.
*/
void selectionSort(int arr[],int n){
    for(int i=0; i<n-1; i++){
        int minNumIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minNumIndex]){
                minNumIndex = j;
            }
        }
        swap(arr[i], arr[minNumIndex]);
    }
}


/*
3. Insertion Sort
    Time Complexity = O(n^2)
    Space Complexity = O(1)
*/
#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6};
    int n = arr.size();

    insertionSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}


/*
4. Merge Sort
    Time Complexity = O(nlogn)
    Space Complexity = O(n)
*/
void merge(int arr[], int left, int right, int mid){
    int n1 = mid-left+1;
    int n2 = right-mid;
    int leftArr[n1], rightArr[n2];

    for(int i=0; i<n1; i++){
        leftArr[i] = arr[left+i];
    }
    for(int j=0; j<n2; j++){
        rightArr[j] = arr[mid+1+j];
    }

    int i=0, j=0, k=left;
    while(i<n1 && j<n2){
        if(leftArr[i] < rightArr[j]){
            arr[k] = leftArr[i++];
        }
        else {
            arr[k] = rightArr[j++];
        }
        k++;
    }
    while(i<n1){
        arr[k++] = leftArr[i++];
    }
    while(j<n2){
        arr[k++] = rightArr[j];
    }
}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = left + (right - left)/2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        merge(arr, left, right, mid);
    }
}


/*
5. Quick Sort
    Time Complexity = O(n^2) - worst case
                      O(nlogn) - average case
    Space Complexity = O(logn)
*/
#include <iostream>
#include <vector>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) { // moving all the smaller value than the pivotValue before the pivotIndex.
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]); // placing the pivotValue at it correct index pivotIndex
    // all the elements from the pivotIndex to the arr[high-1] are larger than the pivotValue. 
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}