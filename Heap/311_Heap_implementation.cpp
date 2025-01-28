/*
Given an array of N elements. The task is to build a Binary Heap from the 
given array. The heap can be either Max Heap or Min Heap.

Link : https://www.geeksforgeeks.org/building-heap-from-array/

Example 1: 
    Input: arr[] = {4, 10, 3, 5, 1}
    Output: Corresponding Max-Heap:
          10
         /   \
        5     3
       /  \
      4    1

Example 2:
    Input: arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17}
    Output: Corresponding Max-Heap:
                  17
                /     \
              15        13
            /    \     /  \
          9      6    5   10
         / \    /  \
        4   8  3    1
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Heap {
    public:
    int arr[100];
    int size = 0;

    Heap(){
        arr[0] = -1; // making 1-based index
        size = 0;
    }

    void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;

       // bubble up
        while(index > 1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }else{
                return;
            }
        }
    }

    void deleteRoot(){
        if(size == 0){
            cout << "nothing to delete." << endl;
            return;
        }

        arr[1] = arr[size]; // replacing first node with last node.(that is deleting the top root node)
        size--; // deleting the last node;

        // sink down
        int i=1;
        while(i < size){
            int leftNodeIndex = 2*i;
            int rightNodeIndex = 2*i+1;

            if(leftNodeIndex < size && arr[i] < arr[leftNodeIndex]){
                swap(arr[i], arr[leftNodeIndex]);
                i = leftNodeIndex;
            }else if(rightNodeIndex < size && arr[i] < arr[rightNodeIndex]){
                swap(arr[i], arr[rightNodeIndex]);
                i = rightNodeIndex;
            }else{
                return;
            }
        }
    }

    // Note : leaf nodes will be present from n/2+1 to nth position in heaps. Therefore we can run the loop only for 1 - n/2;
    void heapify(int arr[], int n, int i){
        int largest = i;
        int leftNodeIndex = 2*i;
        int rightNodeIndex = 2*i+1;

        if(leftNodeIndex < n && arr[largest] < arr[leftNodeIndex]){
            largest = leftNodeIndex;
        }
        if(rightNodeIndex < n && arr[largest] < arr[rightNodeIndex]){
            largest = rightNodeIndex;
        }

        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    void print(){
        for(int i=1; i<=size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main(){
    // Heap *h = new Heap();
    Heap h;

    h.print();
    h.insert(10);
    h.print();
    h.insert(20);
    h.print();
    h.insert(30);
    h.print();
    h.insert(0);
    h.print();
    h.insert(50);
    h.print();

    h.deleteRoot();
    h.print();
    h.deleteRoot();
    h.print();
    h.deleteRoot();
    h.print();
    h.deleteRoot();
    h.print();
    h.deleteRoot();
    h.print();
    h.deleteRoot();
    h.print();
    h.deleteRoot();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n=5;
    for(int i=n/2; i>0; i--){
        h.heapify(arr, n, i);
    }
    cout << "printing the array." << endl;
    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}