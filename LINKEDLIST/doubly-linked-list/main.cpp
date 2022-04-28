#include <iostream>
using namespace std;
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*head = NULL;

void create(int value[],int length){
    Node * temp, * last = new Node;
    head = new Node;
    head->data=value[0];
    head->prev=head->next=NULL;
    last=head;
    for(int i=1; i<length; i++){
        temp = new Node;
        temp->data = value[i];
        temp->prev = last;
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}
void insertAtTheHead(){
    Node * temp = new Node;
    if(temp == NULL){
        cout<<" No enough memory";
    }
    temp->data = 7;
    temp->next = head;
    temp->prev = NULL;
    head->prev = temp;
    head = temp;
}
void insertAtTheEnd(){
    Node * temp= new Node;
    Node * newNode = new Node;

    if(temp == NULL || newNode == NULL){
        cout<<" No enough memory"<<endl;
    }
    newNode->data = 8;
    temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = NULL;
}
void insertAfter(int searchValue){
    Node *newNode = new Node;
    Node *temp = new Node;
    if(newNode ==NULL || temp == NULL){
        cout<<" No enough memory  "<<endl;
    }
    newNode->data = 9;
    newNode->next = NULL;
    newNode->prev = NULL;
    temp = head;
    while (temp->data != searchValue){
        if(temp->next){
            temp = temp->next;
        }else{
            cout<<"  No search value found  "<<endl;
        }
    }
    temp->next->prev =newNode;
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}
void insertBefore(int searchValue){
    Node *temp = new Node;
    Node * newNode = new Node;
    if(temp == NULL || newNode == NULL){
        cout << "No enough memory  "<<endl;
    }
    newNode->data = 10;
    temp = head;

    while (temp->data != searchValue){

        temp = temp->next;


    }

    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
}
void deleteAtHead(){
    Node * temp = new Node;
    if(temp == NULL){
        cout <<" No enough memory  "<<endl;
    }
    temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}
void deleteFromTheEnd(){
    Node * temp = new Node;
    if (temp == NULL){
        cout<<" No enough memory "<<endl;
    }
    temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
}
void deleteInTheMiddle(int searchValue){
    Node * ptr = new Node;
    Node * temp = new Node;
    if(ptr == NULL || temp == NULL){
        cout<<" No enough memory "<<endl;
    }
    ptr = head;
    while (ptr->data != searchValue){

        if(ptr->next){
            ptr = ptr->next;
        }else{
            cout<<" No search value found "<<endl;
        }
    }
    temp = ptr->next;
    ptr->next = temp->next;
    temp->next->prev = ptr;
    delete temp;

}
void deleteAfter(int searchValue){
    Node * ptr = new Node;
    Node * temp = new Node;
    if(ptr == NULL || temp == NULL){
        cout<<" No enough memory "<<endl;
    }
    ptr = head;
    while (ptr->data != searchValue){
        ptr = ptr->next;

    }
    temp = ptr->next;
    ptr->next = temp->next;
    temp->next->prev = ptr;
    delete temp;

}
//void deletingBefore(int searchValue){
//
//}
void display(){
    Node * startingNode = new Node;
    startingNode = head;
    while (startingNode !=NULL){
        cout<<"  "<<startingNode->data;
        startingNode = startingNode->next;
    }
    cout<< endl;
}
int main(){
    int myArray[]= {1,2,3,4,5,6};
    create(myArray,6);
    cout<<" AFTER CREATING THE NODES  "<<endl;
    display();

    insertAtTheHead();
    cout<<" AFTER INSERTING AT THE HEAD  "<<endl;
    display();
    insertAtTheEnd();
    cout<<" AFTER INSERTING AT THE END "<<endl;
    display();

    insertAfter(5);
    cout<<" AFTER INSERTING IN THE MIDDLE  "<<endl;
    display();
    insertBefore(5);
    cout<<" AFTER INSERTING BEFORE "<<endl;
    display();
    deleteAtHead();
    cout<<" AFTER DELETING FROM THE HEAD "<<endl;
    display();
    deleteFromTheEnd();
    cout<<" AFTER DELETING FROM THE END "<<endl;
    display();
    deleteInTheMiddle(5);
    cout<<" AFTER DELETING IN THE MIDDLE "<<endl;
    display();
    deleteAfter(2);
    cout<<" AFTER DELETING AFTER A NODE  "<<endl;
    display();
}
