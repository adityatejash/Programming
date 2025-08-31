// WAP for pointer to pointer 

#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int *p = &a;   
    int **pp = &p; 

    cout << "Value of a: " << a << endl;
    cout << "Address of a (&a): " << &a << endl;

    cout << "Value stored in p (*p): " << *p << endl;
    cout << "Address stored in p (p): " << p << endl;
    cout << "Address of p (&p): " << &p << endl;

    cout << "Value stored in pp (**pp): " << **pp << endl;
    cout << "Address stored in pp (*pp): " << *pp << endl;
    cout << "Address of pp (&pp): " << &pp << endl;

    return 0;
}