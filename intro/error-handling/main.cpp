#include <iostream>
using namespace std;

class A{
public:
    ~A(){
        cout<<"  Destructor called  "<<endl;
    }

};

// void read(const char* filename, char data[]){
// FILE *fp = fopen(filename,"r");
// if(fp == NULL){
// throw "file open error ";
// }
// };

class FileReadError
{

};

void read(const char* filename, char data[])
{
    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
        throw FileReadError(); // indicate error

    // read file contents into data

}
int main(){

    char data[128];
    try {
        read("test.txt", data);
    }
    catch(FileReadError error) {
        // if read throws an exception,
        // we will come here
    }
// read(NULL,NULL);
    return 0;
}