//Q6. Write a program using This pointer for length, Breadth and Height

#include <iostream>
using namespace std;

class A {
    int length, breadth , height;
public:
    A (int length, int breadth, int height){
        this->length = length;
        this->breadth = breadth;
        this->height = height;
    }

    void display(){
        cout << "Length: " << length << endl
             << "Breadth: " << breadth << endl
             << "Height: " << height << endl; 
    }
};

int main(){
    A a(5,9,4);
    a.display();
    return 0;
}