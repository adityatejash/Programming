// Q7.Write a program pointer to derived class

#include <iostream>
using namespace std;

class Base {
public:
    virtual void display(){
        cout << "This is Base Class." << endl;
    }
};

class Derived : public Base {
public:
    virtual void display () override {
        cout << "This is Derived Class." << endl;
    }
};

int main(){
    // Base* d = new Derived;
    // d->display();
    Base d;
    d.display();
    delete d;
    return 0;
}