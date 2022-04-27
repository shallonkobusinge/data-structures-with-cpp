#include <iostream>
using namespace std;

template <class E>
E sum(E num1, E num2){
    return num1 + num2;
}

int main() {
    double num1,num2;
    int firstNumber = 30 ,lastNumber =30;
    cout<<"Enter the first double number "<<endl;
    cin>>num1;

    cout<<"Enter the second double number "<<endl;
    cin>>num2;

    cout<<" The sum of the two double numbers is "<<sum(num1,num2);
    cout<<" The sum of integer numbers is "<<sum(firstNumber,lastNumber);

    return 0;
}
