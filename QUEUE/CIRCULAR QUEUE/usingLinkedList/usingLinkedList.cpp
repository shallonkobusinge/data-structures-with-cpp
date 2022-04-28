
#include <iostream>
using namespace std;


struct Node {
    int data;
    struct Node* next;
};
struct Queue {
    struct Node *front, *rear;
};


void enQueue(Queue* q, int value)
{
    struct Node* temp = new Node;
    temp->data = value;
    if (q->front == NULL)
        q->front = temp;
    else
        q->rear->next = temp;

    q->rear = temp;
    q->rear->next = q->front;
}


int deQueue(Queue* q)
{
    if (q->front == NULL) {
        cout<<"Queue is empty"<<endl;
    }


    int value;
    if (q->front == q->rear) {
        value = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    }
    else // There are more than one nodes
    {
        struct Node* temp = q->front;
        value = temp->data;
        q->front = q->front->next;
        q->rear->next = q->front;
        free(temp);
    }

    return value;
}

void displayQueue(struct Queue* q)
{
    struct Node* temp = q->front;
    cout<<"\nElements in Circular Queue are: ";
    while (temp->next != q->front) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data;
    cout<<endl;
}

int main()
{

    Queue* q = new Queue;
    q->front = q->rear = NULL;
    enQueue(q, 70);
    enQueue(q, 20);
    enQueue(q, 10);
    displayQueue(q);
    cout<<"\nDeleted value  "<<deQueue(q);
    displayQueue(q);

    return 0;
}