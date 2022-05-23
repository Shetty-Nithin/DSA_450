/*
Implementation of Stack.
*/

#include<iostream>
#include<stack>
using namespace std;


// approach 1 : using array.
class Stack {
    public:
    int *arr;
    int top;
    int size;

    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(abs(size - top) > 1){
            top++;
            arr[top] = element;
        }else{
            cout << "Stack overflow" << endl;
        }
    }

    void pop(){
        if(top >= 0){
            top--;
        }else{
            cout << "Stack underflow" << endl;
        }
    }

    int peek(){
        if(top >= 0){
            return arr[top];
        }else{
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }else{
            return false;
        }
    }
};


int main(){
    // Stack* s = new Stack(5);
    // s->push(10);
    // s->push(20);
    // s->push(30);
    // cout << s->peek() << endl;
    // s->pop();
    // cout << s->peek() << endl;

    Stack s2(5);

    s2.push(50);
    cout << s2.isEmpty() << endl;
    s2.push(50);
    s2.push(50);
    s2.push(50);
    s2.push(60);
    cout << s2.peek() << endl;
    cout << s2.peek() << endl;
    s2.pop();
    s2.pop();
    s2.pop();
    s2.pop();
    s2.pop();
    s2.pop();
    cout << s2.isEmpty() << endl;
}


// approach 2 : using linked list.