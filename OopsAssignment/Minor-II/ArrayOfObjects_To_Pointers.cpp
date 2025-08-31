// Q8.Write a program ARRAY OF OBJECTS TO POINTERS

#include <iostream>
using namespace std;

class Students {
    int age;
    string name;
public:
    Students (string name, int age) : name(name), age(age) {}

    void display(){
        cout << "Name: " << name << " | Age: " << age << endl;
    }
};

int main(){
    Students* s[2];
    s[0] = new Students("Alice",20);
    s[1] = new Students("Bob",14);
    for (int i=0; i<2; i++){
        s[i]->display();
    }
}