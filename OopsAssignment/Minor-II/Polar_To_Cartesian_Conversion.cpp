// Q2. . Create two classes: Polar and Cartesian, to represent Polar and Cartesian coordinates of a podouble. Demonstrate how to convert Polar coordinates to Cartesian coordinates by writing the conversion code in source class.

#include <iostream>
#include <cmath>
using namespace std;

class Cartesian {
    int x,y;
public:
    Cartesian (int x, int y) : x(x), y(y) {}

    void display(){
        cout<<"---Cartesian Form---"<<endl;
        cout << "z = " << x <<" + "<<y<<"i" << endl;
    }
};

class Polar {
    int x, y;
public:
    double r, angle_degree;
    Polar (int x, int y) : x(x), y(y) {}

    void conversion(){
        r = sqrt(x*x + y*y);
        angle_degree = atan2(y,x) * 180 / M_PI;
    }

    void display(){
        cout<<"-----Polar Form-----" << endl;
        cout<<"z = "<<r<<"(sin "<<angle_degree<<" + "<<"cos "<<angle_degree<<"), or z = "<<r<<"e^i"<<angle_degree << endl;
    }
};

int main(){
    int x=1, y=1;
    
    Cartesian C(x,y);
    C.display();

    Polar P(x,y);
    P.conversion();
    P.display();

    return 0;
}