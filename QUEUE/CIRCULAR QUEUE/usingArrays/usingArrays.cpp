#include <iostream>
using namespace std;
struct Queue{
    int rear;
    int front;
    int size;
    int *arr;

};
void create(struct Queue *que, int size){
    que->front = que->rear = -1;
    que->size = size;
    que->arr = new int[que->size];

}

void enQueue(struct Queue *queue,int value){
    if((queue->front == 0 && queue->rear == queue->size-1) || (queue->rear == (queue->front-1)%(queue->size-1))){
        cout<<" Queue is full  "<<endl;
        return;
    }
    else if(queue->front == -1){
        queue->front = queue->rear = 0;
        queue->arr[queue->rear] = value;
    }
    else if(queue->rear == queue->size - 1 && queue->front!=0){
        queue->rear = 0;
        queue->arr[queue->rear] = value;
    }else{
        queue->rear++;
        queue->arr[queue->rear] = value;
    }
}
int deQueue(Queue *queue) {
    if(queue->front == -1){
        cout<<" The queue is empty  "<<endl;

    }
    int data = queue->arr[queue->front];
    queue->arr[queue->front] = -1;
    if(queue->front == queue->rear){
        queue->front = -1;
        queue->rear = -1;
    }
    else if(queue->front == queue->size - 1){
        queue->front = 0;
    }else{
        queue->front++;
    }
    return data;
}
void displayQueue(struct Queue *queue){
    if(queue->front == -1){
        cout<<" Queue is empty  "<<endl;
    }
        cout<<"     Elements in the circular queue are :  "<<endl;
        if(queue->rear >= queue->front){
            for(int i =queue->front; i<=queue->rear; i++){
                cout<<queue->arr[i]<<" ";

            }
            cout<<endl;
        }else{
            for(int i=queue->front; i<queue->size; i++){
                cout<<queue->arr[i]<<" ";

            }
            for(int i=0; i<=queue->rear; i++){
                cout<<queue->arr[i]<<" ";
            }
        }

}
int main(){
    struct Queue que;
   create(&que,5);
     enQueue(&que,90);
    enQueue(&que,20);
    enQueue(&que,60);
    displayQueue(&que);

    int deleted= deQueue(&que);
    cout<<" Deleted Value  "<<deleted<<endl;
    displayQueue(&que);

    return 0;
}