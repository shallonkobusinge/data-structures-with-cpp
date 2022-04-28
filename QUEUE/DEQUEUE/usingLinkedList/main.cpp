#include <iostream>
using namespace std;
struct Node {
    int data;
    struct Node *next;
}*initial = NULL;
void insertAtFront(int value){
    Node *p = new Node;
    p->data = value;
    p->next = initial;
    initial = p;
}
void insertAtRear(int value){
    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;
    Node *p = initial;
    while (p->next != NULL) p = p->next;
    p->next = temp;
}
void deleteAtFront(){
    Node  *temp = new Node;
    temp = initial;
    initial = initial->next;
    free(temp);
}
void deleteAtRear(){
    Node *prev = new Node;
    Node *p = initial;
    if (p->next == NULL) {
        initial = NULL;
    } else {
        while (p->next != NULL) {
            prev = p;
            p = p->next;
        }
        prev->next = NULL;
        free(p);
    }
}
void display(struct Node *p) {
    while (p != NULL){
        cout << p->data<< "\t";
        p = p->next;
    }
    cout<<"\n";
}
int main(){
    cout<<"After inserting at Front    : ";
    insertAtFront(10);
    insertAtFront(50);
    insertAtFront(30);
    insertAtFront(27);
    display(initial);
    cout<<endl;
    cout<<"After Inserting at the Rear : ";
    insertAtRear(19);
    display(initial);
    cout<<endl;
    cout<<"After deleting at Rear      : ";
    deleteAtRear();
    display(initial);
    cout<<endl;
    cout<<"After deleting at Front     : ";
    deleteAtFront();
    display(initial);
    cout<<endl;
    return 0;
}