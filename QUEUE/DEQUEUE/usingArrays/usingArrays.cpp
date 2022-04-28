#include <iostream>
using namespace std;

struct Deque{

    int rear;
    int front;
    int size;
    int *arr;
};

Deque* create( Deque *deque, int size){
    deque = new Deque();
    deque->front = deque->rear = -1;
    deque->size = size;
    deque->arr = new int[deque->size];
}
void insertRear(Deque *deque){
    int added_item;
if ((deque->front == 0 && deque->rear == deque->size-1) || (deque->front == deque->rear+1)){
    cout<<"  Queue overflow  ";
    return;
}
if(deque->front == -1){
    deque->front = 0;
    deque->rear = 0;
}
 else{
   if(deque->rear == deque->size-1)
       deque->rear =0;
   else
       deque->rear = deque->rear +1;

}
    cout<<" Input element for adding in queue : " ;
    cin>>added_item;
    deque->arr[deque->rear] = added_item;
}
void insertFront(Deque *deque){
    int added_item;
   if((deque->front == 0 && deque->rear == deque->size-1) || (deque->front == deque->rear+1)){
       cout<<"  Queue Overflow  ";
       return;
   }
   if(deque->front == -1){
       deque->front =0;
       deque->rear =0;
   }
   else{

       if(deque->front == 0)
           deque->front = deque->size - 1;
       else
           deque->front = deque->front - 1;

   }

    cout<<"  Enter an element to add in the queue : ";
    cin>>added_item;
    deque->arr[deque->front] = added_item;
}
void deleteFront(Deque *deque){
   if(deque->front == -1){
       cout<<"  Queue Underflow  ";
       return;
   }
    cout<<" Element Deleted from the queue  "<< deque->arr[deque->front];
   if(deque->front == deque->rear){
       deque->front = -1;
       deque->rear = -1;
   }else{
       if(deque->front == deque->size - 1){
           deque->front = 0;
       }else{
           deque->front = deque->front + 1;
       }
   }
}
void deleteRear(Deque *deque){
    if(deque->front == -1){
        cout<<" Queue Underflow  ";
        return;
    }
    cout<<" Element deleted at the rear  "<<deque->arr[deque->rear];
    if(deque->front == deque->rear){//queue has only one element
        deque->front = -1;
        deque->rear = -1;
    }else{
        if(deque->rear == 0){
            deque->rear = deque->size - 1;
        }else{
            deque->rear = deque->rear - 1;
        }
    }
}
void display_deque(Deque *deque){
    int front_pos = deque->front;
    int rear_pos = deque->rear;

    if(deque->front == -1){
        cout<<" Queue is empty  ";
        return;
    }
    cout<<" Queue Elements : ";
    if(front_pos <= rear_pos){
        while (front_pos <= rear_pos){
            cout<<deque->arr[front_pos]<<" ";
            front_pos++;

        }
    }else{
        while (front_pos <= deque->size - 1){
            cout<<deque->arr[front_pos]<<" ";
            front_pos++;
        }
        front_pos =0;
        while(front_pos <= deque->size-1){
            cout<<deque->arr[front_pos];
            front_pos++;
        }
    }
    cout<<endl;
}
void restricted(Deque *deque){
    int choice;


    do{

        cout<<"1.Insert at rear\n";
        cout<<"2.Delete from front\n";
        cout<<"3.Delete from rear\n";
        cout<<"4.Display\n";
        cout<<"5.Quit\n";
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice)
        {	case 1:
                insertRear(deque);
                break;
            case 2:
                deleteFront(deque);
                break;
            case 3:
                deleteRear(deque);
                break;
            case 4:
                display_deque(deque);
                break;
            case 5:
                break;
            default:
                cout<<" Wrong choice "<<endl;
        }
    } while (choice != 5);
}
void not_restricted(Deque *deque){
    int choice;

    do{

        cout<<"1.Insert at front\n";
        cout<<"2.Insert at rear\n";
        cout<<"3.Delete from front\n";
        cout<<"4.Display\n";
        cout<<"5.Quit\n";
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice)
        {	case 1:
                insertFront(deque);
                break;
            case 2:
                insertRear(deque);
                break;
            case 3:
                deleteFront(deque);
                break;
            case 4:
                display_deque(deque);
                break;
            case 5:
                break;
            default:
                cout<<" Wrong choice "<<endl;
        }
    } while (choice != 5);
}
int main(){
    Deque *deque= create(deque,10);
    int choice;
    cout<<"                    MENU                     "<<endl;
    cout<<"       1. Output restricted dequeue"<<endl;
    cout<<"       2. Input restricted dequeue"<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;
    switch(choice)
    {
        case 2 :
            restricted(deque);
            break;
        case 1:
            not_restricted(deque);
            break;
        default:
            cout<<"Wrong choice\n";
    }

    return 0;
}