// Build a Singly Linked List


#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;    
        }
    }
};

class singly_linked_list {
    public:
    Node* head;
    Node* tail;
    int length;

    singly_linked_list(){
        this->head = NULL;
        this->tail = NULL;
        this->length = 0;
    }

    void insertAtHead(int element){

        Node *newNode = new Node(element);

        if(length == 0){
            head = newNode;
            tail = newNode;
            length++;
        }
        else{
            newNode->next = head;
            head = newNode;
            length++;
        }
    }

    void insertAtTail(int element){

        Node *newNode = new Node(element);

        if(length == 0){
            head = newNode;
            tail = newNode;
            length++;
        }
        else{
            tail->next = newNode;
            tail = newNode;
            length++; 
        }
    }

    void insertAtPosition(int pos, int element){

        if(pos <= 1){
            insertAtHead(element);
            return;
        }
        if(pos > length){
            insertAtTail(element);
            return;
        }

        Node* newNode = new Node(element);
        Node* prevNode = head;

        while(pos-2){
            prevNode = prevNode->next;
            pos--;
        }
        newNode->next = prevNode->next;
        prevNode->next = newNode;
        length++;
    }

    void updateAt(int pos, int element){

        Node* curr = head;

        while(pos-1){
            curr = curr->next;
            pos--;
        }
        curr->data = element;
    }

    void deleteAt(int pos){

        if(pos == 1){
            Node* deletableNode = head;
            head = head->next;
            deletableNode->next = NULL;
            length--;
            delete deletableNode;
        }
        else{
            Node* prevNode = head;
            
            while(pos-2){
                prevNode = prevNode->next;
                pos--;
            }
            Node* deletableNode = prevNode->next;
            prevNode->next = deletableNode->next;
            deletableNode->next = NULL;
            length--;
            delete deletableNode->next;
        }
    }

    void print(){
        Node *temp = head;
        while(temp != NULL){
            cout << temp->data << " --> ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main(){
    singly_linked_list* sll = new singly_linked_list();
    
    cout << endl;

    sll->insertAtHead(8);
    sll->insertAtHead(6);
    sll->insertAtHead(4);
    cout << "insertAtHead : ";
    sll->print();

    sll->insertAtTail(2);
    cout << "insertAtTail : ";
    sll->print();

    sll->insertAtPosition(3, 10);
    cout << "insertAtPosition 3 : ";
    sll->print();

    sll->updateAt(3, 20);
    cout << "update position 3 : ";
    sll->print();

    sll->deleteAt(2);
    cout << "deleting 2nd node : ";
    sll->print();
    
    cout << endl;

    cout << "head is : " << sll->head->data << endl;
    cout << "tail is : " << sll->tail->data << endl;
    cout << "length is : " << sll->length << endl;
}
