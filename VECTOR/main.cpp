#include <iostream>
#include <vector>
using namespace std;

void printElements( vector<int> elements){
        cout<<endl;
        cout<<" Elements in the Vector  "<<endl;
    for(int i=0; i<elements.size(); i++){

        cout<<elements[i]<<"  ";
    }
    cout<<endl;
}

int main(){
    vector<int> b(4,3);
    vector<int> v;
    v.push_back(10);
    v.push_back(20);

    cout<< " Values of b is "<<b[0]<<endl;
    cout<< " Values of b is "<<b[1]<<endl;
    cout<< " Values of b is "<<b[2]<<endl;
    cout<< " Values of b is "<<b[3]<<endl;
    cout<< " The size of b "<<b.size()<<endl;
    cout<<" Value     :  "<<v[1]<<endl;
    cout<<" Size      :  "<<v.size()<<endl;
    cout<<" Size      :  "<<v.size()<<endl;
    cout<<" Capacity  :  "<<v.capacity()<<endl;
    cout<<" Capacity  :  "<<v.capacity()<<endl;
    v.push_back(50);

//     v[4] = 45;
    v.push_back(75);
    v.push_back(90);
    v.push_back(100);
    v.push_back(300);
    v.push_back(430);
    v.push_back(400);

    printElements(v);
    cout<<" Size      :  "<<v.size()<<endl;
    cout<<" Capacity  :  "<<v.capacity()<<endl;

    return 0;
}
