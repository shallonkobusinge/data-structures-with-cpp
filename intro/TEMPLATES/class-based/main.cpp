#include <iostream>
#include "MemoryCell.h"
using namespace std;

int main(){

MemoryCell<int> m;//instantiate int version
MemoryCell<float> f; //instantiate float version
MemoryCell<int> m2;  //use the previously created class

m.write(5);
m2.write(6);
f.write(3.5);
m.write(7);

cout<<" Cell content : " <<m.read() <<endl;
cout<<" Cell content : " <<m2.read() <<endl;
cout<<" Cell content : " <<f.read() <<endl;


// int x = 4;
// TemplateTest::addition(x);

    return 0;
}
// class TemplateTest{

//     public:
//     void f(T a){
//         cout<<" The value of T is "<<a<<endl;
//     }

//     public:
//     int addition(T a){
//         cout<<" After adding 1 "+a+"  is:  "<<(a+1)<<endl;
//     }

// };

//abstraction
// T TemplateTest<T>::addition(T a, T b);

// T TemplateTest<T>::addition(T a, T b){
//     return a+b;
// }
