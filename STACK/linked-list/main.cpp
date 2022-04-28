#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*head = NULL;

void push(int val){
    Node * newNode = new Node;
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void pop(){
  if(head == NULL){
      cout<<"  Stack Underflow  "<<endl;
  } else{
      cout<<" The popped element is "<<head->data<<endl;
      head = head->next;
  }
}
void peek(){
    cout<<" "<<head->data<<endl;
}

void display(){
    Node * tempNode = new Node;

    if(head == NULL){
        cout<<"  Stack Underflow  "<<endl;
    }
    else{
        tempNode = head;
        while (tempNode!=NULL)
        {
        cout<<tempNode->data;
        tempNode = tempNode->next;
        }
        cout<<endl;


    }
}


int main(){
push(2);
push(4);
push(3);
push(5);
push(6);
push(7);
display();
pop();
display();
peek();
    return 0;
}