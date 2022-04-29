#include <iostream>
using namespace std;

template < class T>

void swapping(T lh, T rh){
    T temp = lh;
    lh = rh;
    rh = temp;
    cout<<" After swappp  "<<lh<<"  "<<rh<<"  "<<endl;
}

int main(){

int x = 3, y = 4;

cout<<" Before Swapp "<<x<<"  "<<y<<endl;
swapping(3,4);


    return 0;
}