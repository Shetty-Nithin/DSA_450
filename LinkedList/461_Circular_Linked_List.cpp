#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
  int val;
  Node *nextLink;

  Node(int val){
    this->val = val;
    this->nextLink = NULL;
  }

  ~Node(){
    if(this->nextLink != NULL){
      delete nextLink;
      nextLink = NULL;
    }
  }
};

class circular_Linked_List {
  public:
  Node *tail;
  int length = 0;

  circular_Linked_List(){
    tail = NULL;
  }

  void insertNode(int prevElement, int element){
    Node *newNode = new Node(element);

    if(tail == NULL){
      tail = newNode;
      tail->nextLink = tail;
    }
    else{
      Node *curr = tail;
      while(curr->val != prevElement){
        curr = curr->nextLink;
      }

      newNode->nextLink = curr->nextLink;
      curr->nextLink = newNode;
    }
    length++;
  }

  void deleteNodeAt(int element){
    if(length == 0){
      cout << "List is empty" << endl;
      return;
    }
    else if(length == 1){
      tail = NULL;
      return;
    }

    Node *prev = tail;
    Node *curr = prev->nextLink;

    while(curr->val != element){
        prev = curr;
        curr = curr->nextLink;
    }
    prev->nextLink = curr->nextLink;
    curr->nextLink = NULL;

    if(curr->val == tail->val){
      tail = prev;
    }
    
    delete curr;
    length--;
  }
 
  void print(){
    Node* curr = tail;
    cout << endl << " --> ";
    do{
      cout << curr->val << " --> ";
      curr = curr->nextLink;
    }
    while(curr != tail);
    cout << endl;
  }
};

int main() {
  circular_Linked_List *cll = new circular_Linked_List();
  cll->insertNode(0, 5);
  cll->insertNode(5, 6);
  cll->insertNode(6, 7);
  cll->insertNode(7, 8);
  cll->insertNode(5, 100);
  cll->insertNode(5, 110);
  cll->print();

  cll->deleteNodeAt(5);
  cll->print();

  cout << endl;
  cout << "tail is : " << cll->tail->val << endl;
  cout << "length is : " << cll->length << endl;
}