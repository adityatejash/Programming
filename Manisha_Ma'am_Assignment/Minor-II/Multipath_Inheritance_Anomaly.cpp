// Q3.Write a program to demonstrate anomaly caused in Multi-path Inheritance. Also, write a program to overcome the anomaly.

#include <iostream>
using namespace std;

class A {
public:
    void show() {
        cout << "Class A show()" << endl;
    }
};

class B : virtual public A { };

class C : virtual public A { };

class D : public B, public C { };

int main() {
    D obj;
    // obj.B::show(); {anamoly}
    // obj.C::show(); {anamoly}
    obj.show(); 
    return 0;
}
