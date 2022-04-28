//#include <iostream>
//using namespace std;
//
//struct Node
//{
//    int data;
//    int priority;
//    struct Node* next;
//
//} node;
//
//Node * newNode(int d, int p)
//{
//    Node* temp = new Node;
//    temp->data = d;
//    temp->priority = p;
//    temp->next = NULL;
//    return temp;
//}
//
//int peek(Node** head)
//{
//    return (*head)->data;
//}
//
//void pop(Node** head)
//{
//    Node* temp = *head;
//    (*head) = (*head)->next;
//    free(temp);
//}
//
//// Function to push according to priority
//void push(Node** head, int d, int p)
//{
//    Node* start = (*head);
//
//    Node* temp = newNode(d, p);
//
//    if ((*head)->priority > p)
//    {
//
//        temp->next = *head;
//        (*head) = temp;
//    }
//    else
//    {
//
//        while (start->next != NULL &&
//               start->next->priority < p)
//        {
//            start = start->next;
//        }
//
//        temp->next = start->next;
//        start->next = temp;
//    }
//}
//
//// Function to check is list is empty
//int isEmpty(Node** head)
//{
//    return (*head) == NULL;
//}
//
//// Driver code
//int main()
//{
//
//    Node* pq = newNode(4, 1);
//    push(&pq, 5, 2);
//    push(&pq, 6, 3);
//    push(&pq, 7, 0);
//
//    while (!isEmpty(&pq))
//    {
//        cout << " " << peek(&pq);
//        pop(&pq);
//    }
//    return 0;
//}

#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

struct Node
{
    int priority;
    int data;
    struct Node *next;
}*front=NULL, *rear=NULL,*temp;

void enqueue(int value, int p)
{
    Node  *q;
    temp = new Node;
    temp->data = value;
    temp->priority = p;
    if (front == NULL || p < front->priority)
    {
        temp->next = front;
        front= temp;
    }
    else
    {
        q = front;
        while (q->next != NULL && q->next->priority <= p)
            q = q->next;
        temp->next = q->next;
        q->next = temp;
    }
}

void dequeue()
{
    if (front == NULL) cout << "Queue is empty\n";

    temp = front;
    cout << "Element Deleted : " << temp->data << endl;
    front = front->next;
    free(temp);

}

void display()
{
    Node *ptr;
    ptr = front;
    if (front == NULL)cout << "Queue is empty\n";

    while (ptr != NULL)
    {
        cout << "Element  :  " <<ptr->data<< " Priority  "<< ptr->priority << endl;
        ptr = ptr->next;
    }
}

int main()
{
    int element,number, priority,choice,flag=1;

cout<<endl;
    while( flag == 1)
    {
        cout<<"                 MENU           "<<endl;
        cout<<"                1. Insert     "<<endl;
        cout<<"                2. Delete     "<<endl;
        cout<<"                3. Display   "<<endl;
        cout<<"                4. Quit      "<<endl;
        cin>>choice;
        int i =0;
        switch (choice)
        {



            case 1:
                cout<<"   How many elements do you want to insert ?  "<<endl;
                cin>>number;
                while (i<number){
                    cout<<"Enter the "<<i+1<<" Element "<<endl;
                    cin>>element;
                    cout<<"Enter Priority for the "<<i+1<<" Element  "<<endl;
                    cin>>priority;
                    enqueue(element,priority);
                    i++;
                }


                break;
            case 2: dequeue();
                break;
            case 3: display();
                break;
            case 4: flag = 0;
                break;
            default: flag=1;
                break;


        }

    }
    return 0;
}
