// Q9. Create an abstract class Shape with a pure virtual function draw(). Derive classes Circle and Square and implement the draw() function. Instantiate objects via pointers to Shape.
#include <iostream>
using namespace std;
class Shape {
public:
    Shape(){}
    virtual void draw () = 0;
    virtual ~Shape(){}
};

class Circle : public Shape {
public:
    Circle(){}
    void draw () override {
        cout << "Drawing Circle!!!" << endl;
    }
    ~Circle(){}
};

class Square : public Shape {
public:
    Square(){}
    void draw () override {
        cout << "Drawing Square!!!" << endl;
    }
    ~Square(){}
};

int main(){
    Shape* s1 = new Circle;
    Shape* s2 = new Square;
    s1->draw();
    s2->draw();
    delete s1;
    delete s2;
    return 0;
}