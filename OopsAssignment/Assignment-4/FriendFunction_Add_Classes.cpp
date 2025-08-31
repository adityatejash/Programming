// wap using friend function to add data objects of two different classes
#include <iostream>
using namespace std;

class two;

class one {
    int n;
public: 
    one(int a) {
        n = a;
    }
    friend int add(one, two);
};

class two {
    int n;
public:
    two(int a) {  
        n = a;
    }
    friend int add(one, two); 
};

int add(one a, two b) {
    return a.n + b.n;
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    one A(a); 
    two B(b);

    cout << "Sum: " << add(A, B) << endl;

    return 0; 
}

