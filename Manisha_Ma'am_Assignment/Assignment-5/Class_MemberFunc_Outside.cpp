// Write a program that uses a class where the member functions are defined outside a class
#include <iostream>
#include <string>
using namespace std;

class details{
    string name;
    int age;

public:
    void insert_details(string n, int a);
    void display_details();
};

void details::insert_details(string n, int a){
    name = n;
    age = a;
}

void details::display_details(){
    cout << "Your name is " << name << ", and your age is " << age << ".\n";
}

int main(){
    details d;
    string name;
    int age;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;

    d.insert_details(name, age);
    d.display_details();

    return 0;
}