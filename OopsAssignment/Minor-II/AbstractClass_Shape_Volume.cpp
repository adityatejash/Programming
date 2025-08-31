// Q4.Create an abstract class Shape which has a field P1=3.14 as final and it has an abstract method Volume. Make two sub-classes 'Cone' and 'Sphere' from this class and they should print their volume.

#include <iostream>
using namespace std;

class Shape {
protected:
    const float pi = 3.14;
public:
    virtual void Volume() = 0;
};

class Sphere : public Shape {
    double radius;
public:
    Sphere (double radius) : radius(radius){}
    void Volume() override {
        double vol = (4 * pi * radius * radius * radius)/3;
        cout << "Volume of Sphere: " << vol << endl;
    }
};

class Cone : public Shape {
    double radius, height;
public:
    Cone (double radius, double height) : radius(radius), height(height){}
    void Volume () override {
        double vol = (pi  * radius * radius * height)/3;
        cout << "Volume of Cone: " << vol << endl;
    }
};

int main(){
    Cone c(5,7);
    Sphere s(8);

    c.Volume();
    s.Volume();

    return 0;
}