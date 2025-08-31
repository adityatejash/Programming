// Q1. Create an inheritance hierarchy of Rodent, Mouse, Gerbil, Hamster etc. In the base class provide methods that are common to all Rodents and override these in the derived classes to perform different behaviors, depending on the specific type of Rodent. Create an array of Rodent, fill it with different specific types of Rodents and call your base class methods.

#include <iostream>
using namespace std;

class Rodent {
public:
    Rodent () {
        cout << "Rodent constructor called." << endl;
    }
    virtual void eat(){
        cout<<"Rodent is eating."<< endl;
    }
    virtual void run(){
        cout << "Rodent is running" << endl;
    }
    virtual ~Rodent(){
        cout <<"Rodent destructor called." << endl;
    }
};

class Mouse : public Rodent {
public:
    Mouse () {
        cout << "Mouse constructor called." << endl;
    }
    void eat() override {
        cout<<"Mouse is eating."<< endl;
    }
    void run()override{
        cout << "Mouse is running" << endl;
    }
    ~Mouse() override{
        cout <<"Mouse destructor called." << endl;
    } 
};

class Gerbil : public Rodent {
public:
    Gerbil () {
        cout << "Gerbil constructor called." << endl;
    }
    void eat()override{
        cout<<"Gerbil is eating."<< endl;
    }
    void run()override{
        cout << "Gerbil is running" << endl;
    }
    ~Gerbil()override{
        cout <<"Gerbil destructor called." << endl;
    }
};

class Hamster : public Rodent {
public:
    Hamster (){
        cout << "Hamster constructor called." << endl;
    }
    void eat()override{
        cout<<"Hamster is eating."<< endl;
    }
    void run()override{
        cout << "Hamster is running" << endl;
    }
    ~Hamster () override{
        cout <<"Hamster destructor called." << endl;
    }
};

int main(){
    Rodent* r[3];

    r[0] = new Mouse();
    r[1] = new Gerbil();
    r[2] = new Hamster();

    cout << "-----Rodent in action-----" << endl;

    for (int i=0; i<3; i++){
        r[i]->eat();
        r[i]->run();
    }
}