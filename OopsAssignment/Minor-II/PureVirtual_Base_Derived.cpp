// Q5.Write a program for Pure virtual function using base class and derived class

#include <iostream>
using namespace std;

class Base {
public:
    Base (){
        cout << "This is Base Class." << endl;
    }
    
    virtual void func() = 0;
};

class Derived: public Base {
public: 
    Derived() {
        cout << "This is Derived Class." << endl;
    }
    
    void func() override {
        cout << "This is virtual function overrrided in Derived Class." << endl;
    }
};

int main(){
    Derived d;
    d.func();
    return 0;
}