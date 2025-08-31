// Write a program that uses a class where the member functions are defined outside a class
#include <iostream>
using namespace std;

class B; 

class A {
private:
    int numA;

public:
    A(int a){ 
        numA = a; 
    }
    
    friend void findGreater(A, B);
};

class B {
private:
    int numB;

public:
    B(int b){ 
        numB = b; 
    }
    
    friend void findGreater(A, B);
};

void findGreater(A objA, B objB){
    if (objA.numA > objB.numB)
        cout << objA.numA << " is greater than " << objB.numB << endl;
    else if (objA.numA < objB.numB)
        cout << objB.numB << " is greater than " << objA.numA << endl;
    else
        cout << "Both numbers are equal: " << objA.numA << endl;
}

int main(){
    int x, y;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;

    A objA(x);
    B objB(y);

    findGreater(objA, objB);

    return 0;
}
