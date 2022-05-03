#include <iostream>
#include <string>
using namespace std;

class Animal{
private:
    string type;
public:
    Animal() : type("Animal"){};
    virtual string getType(){
        return type;
    }
};

class Dog: public Animal{
private:
    string type;
public:
    Dog(): type("Cat") { };
    string getType() override{
        return type;
    }
};
class Cat: public Animal{
private:
    string type;
public:
    Cat(): type("Cat"){};
    string getType() override{
        return type;
    }
};
void print(Animal * animal){
    cout<<"  Animal:  "<<animal->getType()<<endl;
}

int main(){
    Animal * animal = new Animal();
    Animal * animal1 = new Dog();
    Animal * cat = new Cat();
    print(animal);
    print(animal1);
    print(cat);
}