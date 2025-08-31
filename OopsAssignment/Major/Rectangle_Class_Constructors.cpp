// Q3 Design a class Rectangle with data members for length and breadth. Implement parameterized constructors, default constructors, and destructors. Create objects to demonstrate constructor overloading and destruction.
#include <iostream>
using namespace std;
class Rectangle {
public:
    int length, breadth;
    Rectangle (int length = 0, int breadth = 0){
        this->length = length;
        this->breadth = breadth;
    }
    double area(){
        return length*breadth;
    }
    double perimeter(){
        return (length+breadth)*2;
    }
    void show(){
        cout << "Length: " << length << endl
             << "Breadth: " << breadth << endl
             << "Perimeter: " << perimeter() << endl
             << "Area: " << area() << endl
             << endl;
    }
    ~Rectangle () {}
};
int main(){
    Rectangle r1;
    r1.show();
    Rectangle r2(6,8);
    r2.show();
    return 0;
}