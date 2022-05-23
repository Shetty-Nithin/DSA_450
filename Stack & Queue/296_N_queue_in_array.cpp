/*

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

class kQueue {
private: 
    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freeSpot;
    int *next;
public: 
    kQueue(int n, int k){
        this->n = n;
        this->k = k;

        front = new int[k];
        rear = new int[k];
        for(int i=0; i<k; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        for(int i=0; i<n; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;

        arr = new int[n];
        freeSpot = 0;
    }

    void enqueue(int data, int qn){
        if(freeSpot == -1){
            cout << "queue is full" << endl;
            return;
        }

        int index = freeSpot;
        freeSpot = next[index];

        if(front[qn-1] == -1){
            front[qn-1] = index; 
            // checking if its a first element
        }else{
            next[rear[qn-1]] = index; 
            // if not first element, connecting with previous element
        }

        next[index] = -1;
        rear[qn-1] = index;
        arr[index] = data;
    }

    int dequeue(int qn){
        if(front[qn-1] == -1){
            cout << "queue underflow" << endl;
            return -1;
        }

        //find index to pop
        int index = front[qn-1];
        front[qn-1] = next[index];

        next[index] = freeSpot;
        freeSpot = index;
        
        return arr[index];
    }
};

