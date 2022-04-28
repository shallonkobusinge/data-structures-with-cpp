#include <iostream>
using namespace std;

struct Stack{
    int size;
    int top;
    float *S;
}*sample;
void create(int size){
sample = new Stack;
sample->top = -1;
sample->size = size;
sample->S = new float(size);

}
void push( int value){
if(sample->top >= sample->size-1){
    cout<<"  Stack Overflow  "<<endl;
}
else{
    sample->top++;
    sample->S[sample->top] = value;
}
}
void display(){
    int i = sample->top;
    while(i>=0){
        cout<<" "<<sample->S[i];
        i--;
    }
    cout<<endl;
}
int peek(){
	if(sample->top==-1) return -1;
	return sample->S[sample->top];
}
void pop(){
    if(sample->top == -1){
        cout<<" Stack Underflow  "<<endl;
    }else{
    sample->top--;
}
}
int main(){


      create(100);
      push(2);
      push(5);
      push(4);
      display();
    //  cout<<" Value : "<<peek();
      pop();
      display();


    return 0;
}