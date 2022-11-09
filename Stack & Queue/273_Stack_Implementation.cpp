/*
Implementation of Stack.
*/

#include<iostream>
#include<stack>
using namespace std;


// approach 1 : using array.
class array_Stack {
    public:
    int *arr;
    int top;
    int size;

    array_Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if((size - top) > 1){
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



// approach 2 : using linked list.
struct Node {
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class LL_Stack {
    private:
    Node* top;
    int size;

    public:
    LL_Stack(){
        top = NULL;
        size = 0;
    }

    void push(int val){
        Node* newNode = new Node(val);

        if(top == NULL){
            top = newNode;
            size++;
        }else{
            newNode->next = top;
            top = newNode;
        }
    }

    void pop(){
        if(top == NULL){
            cout << "Stack is empty" << endl;
            return;
        }else{
            Node* deletNode = top;
            top = top->next;
            delete deletNode;
            size--;
        }
    }

    int peek(){
        if(top == NULL){
            return -1;
        }else return top->data;
    }

    bool isEmpty(){
        if(top == NULL) return true;
        return false;
    }

    void print(){
        Node* t = top;
        cout << "Stack : ";
        
        while(t != NULL){
            cout << t->data << " -> ";
            t = t->next;
        }
        cout << endl;
    }
};


int main(){

    cout << "-------------Stack implemented using Array---------------" << endl;
    array_Stack* s = new array_Stack(5);
    s->push(10);
    s->push(20);
    s->push(30);
    cout << s->peek() << endl;
    s->pop();
    cout << s->peek() << endl << endl << endl;

    cout << "--------------Stack implemented using Linked List----------------" << endl;
    LL_Stack* s2 = new LL_Stack();
    s2->push(50);
    cout << s2->isEmpty() << endl;
    s2->push(50);
    s2->push(50);
    s2->push(50);
    s2->push(60);
    s2->print();
    cout << s2->peek() << endl;
    s2->pop();
    cout << s2->peek() << endl;
    s2->pop();
    s2->pop();
    s2->pop();
    s2->pop();
    s2->pop();
    cout << s2->peek() << endl;
    cout << s2->isEmpty() << endl;
    s2->print();
}