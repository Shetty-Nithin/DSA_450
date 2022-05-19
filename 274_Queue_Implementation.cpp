/*
Implementation of Queue
*/

#include<iostream>
using namespace std;

// approach 1 : Using Arrays

class queue{
    int size;
    int *arr;
    int q_front;
    int q_rear;

    queue(){
        this->size = 100000;
        arr = new int[size];
        this->q_front = 0;
        this->q_rear = 0;
    }

    void enqueue(int element){
        if(q_rear == size){
            cout << "queue is full." << endl;
        }else{
           arr[q_rear] = element;
           q_rear++; 
        }
    }

    int dequeue(){
        if(q_front == q_rear){
            return -1;
        }else{
            int ans = arr[q_front];
            arr[q_front] = -1;
            q_front++;

            if(q_front == q_rear){
                q_front = 0;
                q_rear = 0;
            }
            
            return ans;
        }
    }

    int front(){
        if(q_front == q_rear){
            return -1;
        }else{
            return arr[q_front];
        }
    }

    bool isEmpty(){
        if(q_front == q_rear){
            return true;
        }else{
            return false;
        }
    }
};
 







// approach 2 : Using Linked list


// Circular Linked List
class MyCircularQueue {
    int *arr;
    int front;
    int rear;
    int size;
public:
    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    
    bool enQueue(int value) {
        if((front == 0 && rear == size-1) || (front == rear+1)){
            cout << front-1 << size-1<< endl;
            return false;
        }else if(front == -1){
            front = 0;
            rear = 0;
        }else if(rear == size-1 && front != 0){
            rear = 0;
        }else{
            rear++;;
        }
        
        arr[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(front == -1){
            return false;
        }
        
        arr[front] = -1;
        
        if(front == rear){
            front = rear = -1;
        }else if(front == size-1){
            front = 0;
        }else{
            front++;
        }
        
        return true;
    }
    
    int Front() {
        if(front == -1){
            return -1;
        }
        return arr[front];
    }
    
    int Rear() {
        if(rear == -1){
            return -1;
        }
        return arr[rear]; 
    }
    
    bool isEmpty() {
        if(front == -1){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if((front == 0 && rear == size-1) || (front == rear+1)){
            return true;
        }  
        return false;
    }
};