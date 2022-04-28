#include<iostream>
using namespace std;

struct Queue{
	int size;
	int front;
	int rear;
	float *Q;
};

void create(struct Queue *q, int size ){
	q->size=size;
	q->front=q->rear=-1;
	q->Q= new float(q->size);
}

void enqueue(struct Queue *q, float x){
	if(q->rear == q->size-1)cout<<"Queue is full"<<endl;
	if(q->front==-1 && q->rear==-1){
		q->front=q->rear=0;
	}else q->rear = q->rear + 1;
	q->Q[q->rear]= x;
}

float dequeue(struct Queue *q){
	float x=-1;
	if(q->front>q->rear || q->front ==-1){
		cout<<"Queue is empty"<<endl;
		return x;
	}
	x=q->Q[q->front];
	q->Q[q->front]=0;
	q->front = q->front+1;
	return x;
}

void display(struct Queue *q){
	for(int i=q->front; i<=q->rear; i++){
		cout<<q->Q[i]<<" ";
	}
}

int main(){
	struct Queue q;

	create(&q, 10);
	enqueue(&q, 45.09);
	enqueue(&q, 9.00);
	enqueue(&q, 10.02);
	enqueue(&q, 2.05);
	enqueue(&q, 50.00);

	cout<<"All Values: "<<endl;
	display(&q);

	cout<<"\nValues after DEQUEUE: "<< dequeue(&q)<<endl;
	display(&q);

	return 0;
}
