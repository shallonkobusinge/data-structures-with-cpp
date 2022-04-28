#include <iostream>
using namespace std;

struct Node{
    int data;
    Node * next;

};
struct Node* front;
struct Node* rear;


void insertNewNode(struct Node *ptr,int value){
    ptr = new Node;
    if(ptr == NULL){
        cout<<" Overflow  "<<endl;
    }else{
        ptr->data = value;
        if(front == NULL){
            front = ptr;
            rear = ptr;
            front->next = NULL;
            rear->next = NULL;
        }else{
            rear->next = ptr;
            rear = ptr;
            rear->next = NULL;
        }
    }

}

void display(){
    Node *ptr = front;
    do{
        cout<<"  Value   "<<ptr->data<<endl;
        ptr = ptr->next;
    } while (ptr->next !=NULL);
}
void deleteNode(){
    if(front ==NULL){
        cout<<"  List is empty "<<endl;
    }
    Node * temp = front;
    front = front->next;
    delete temp;
}
int main() {
    Node * head = NULL;
    insertNewNode(head,20);
    insertNewNode(head,49);
    insertNewNode(head,100);
    insertNewNode(head,120);
    display();
    deleteNode();
    cout<<" New  "<<endl;
    display();
    return 0;
}
