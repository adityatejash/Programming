// Q4. Implement a class Complex for complex numbers. Overload the + operator to add two complex numbers and demonstrate compile-time polymorphism through function overloading. 
#include <iostream>
using namespace std;
class Complex {
public:
    int a,b;
    Complex (int a=0, int b=0){
        this->a = a;
        this->b = b;
    }
    Complex operator+ (const Complex& other){
        return Complex (a + other.a , b + other.b);
    }
    void display(){
        cout << a << " + " << b << "i" << endl; 
    }
    void input(int a){
        this->a = a;
    }
    void input(int a, int b){
        this->a = a;
        this->b = b;
    }
};
int main(){
    Complex c1, c2, sum;
    c1.input(5);
    c2.input(3,4);
    sum = c1 + c2 ;
    sum.display();
    return 0;
}