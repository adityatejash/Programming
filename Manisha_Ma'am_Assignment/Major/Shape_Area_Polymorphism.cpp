// Q5. Create a base class Shape with a virtual function area(). Derive classes Circle and Rectangle from Shape, override the area() function, and demonstrate dynamic polymorphism through base class pointers.
#include <iostream>
#include <cmath>
using namespace std;
class Shape {
public:
    Shape () {}
    virtual double area () = 0;
    virtual ~Shape() {}
};
class Circle : public Shape {
public:
    double radius;
    Circle (int radius=0){
        this->radius = radius;
    }
    double area () override {
        return M_PI * radius * radius;
    }  
};
class Rectangle : public Shape {
public:
    double length, breadth;
    Rectangle (int length, int breadth){
        this->length = length;
        this->breadth = breadth;
    }
    double area() override {
        return length * breadth;
    }
};
int main(){
    Shape* s1 = new Circle(6);
    Shape* s2 = new Rectangle(4,3);
    cout << "Area of Circle: " << s1->area() << endl;
    cout << "Area of Rectangle: " << s2->area() << endl;
    delete s1;
    delete s2;
    return 0;
}