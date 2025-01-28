#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
  int val;
  Node *prevLink;
  Node *nextLink;

  Node(int val){
    this->val = val;
    this->prevLink = NULL;
    this->nextLink = NULL;
  }

  ~Node(){
    if(this->nextLink != NULL){
      delete nextLink;
      nextLink = NULL;
    }
  }
};

class doubly_Linked_List {
  public:
  Node *head;
  Node *tail;
  int length;
  
  doubly_Linked_List(){
    head = NULL;
    tail = NULL;
    length = 0;
  }

  void insertAtHead(int element){
    Node *newNode = new Node(element);

    if(length == 0){
      head = newNode;
      tail = newNode;
      length++;
    }
    else{
      head->prevLink = newNode;
      newNode->nextLink = head;
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
      tail->nextLink = newNode;
      newNode->prevLink = tail;
      tail = newNode;
      length++; 
    }
  }

  void insertAtPosition(int pos, int element){
    if(pos <= 1){
      insertAtHead(element);
    }
    else if(pos > length){
      insertAtTail(element);
    }
    else{
      Node *newNode = new Node(element);

      Node *temp = head;
      while(pos-2){
        temp = temp->nextLink;
        pos--;
      }
      newNode->nextLink = temp->nextLink;
      temp->nextLink->prevLink = newNode;
      temp->nextLink = newNode;
      newNode->prevLink = temp;
      length++;
    }

  }

  void updateAt(int pos, int element){
    Node* curr = head;

    while(pos-1){
        curr = curr->nextLink;
        pos--;
    }
    curr->val = element;
  }
  
  void deleteAt(int pos){
      Node *deleteNode = head;

      if(pos == 1){
        head = deleteNode->nextLink;
        head->prevLink = NULL;

        deleteNode->nextLink = NULL;
        length--;
        delete deleteNode;
      }
      else{
        int count = pos-1;
        while(count){
          deleteNode = deleteNode->nextLink;
          count--;
        }   

        if(pos == length){
          Node *prevOfDeleteNode = deleteNode->prevLink;
          prevOfDeleteNode->nextLink = NULL;

          tail = prevOfDeleteNode;
          deleteNode->prevLink = NULL;
        }
        else{
          Node *prevOfDeleteNode = deleteNode->prevLink;
          prevOfDeleteNode->nextLink = deleteNode->nextLink;
          deleteNode->nextLink->prevLink = prevOfDeleteNode;

          deleteNode->nextLink = NULL;
          deleteNode->prevLink = NULL;
        }
        delete deleteNode;
        length--;
      }

  }
  
  void print(){
    Node *temp = head;
    while(temp != NULL){
      cout << temp->val << " <--> ";
      temp = temp->nextLink;
    }
    cout << endl;
  }
};



int main(){
  doubly_Linked_List *dll = new doubly_Linked_List();
  cout << endl;

  dll->insertAtHead(8);
  dll->insertAtHead(6);
  dll->insertAtHead(4);
  cout << "insertAtHead : ";
  dll->print();

  dll->insertAtTail(2);
  cout << "insertAtTail : ";
  dll->print();

  dll->insertAtPosition(3, 10);
  cout << "insertAtPosition 3 : ";
  dll->print();
    
  dll->updateAt(1, 20);
  cout << "update position 3 : ";
  dll->print();

  dll->deleteAt(5);
  cout << "deleting 2nd node : ";
  dll->print();

  cout << endl;
  
  cout << "head is : " << dll->head->val << endl;
  cout << "tail is : " << dll->tail->val << endl;
  cout << "length is : " << dll->length << endl;
}
