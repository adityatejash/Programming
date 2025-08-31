// WAP for pointer to string

#include <iostream>
using namespace std;

int main(){
    char str[] = "Hello World!!" ;
    char  *p = str;

    cout << "Value of p (*p): " << *p << endl;
    cout << "Address of p (&p): " << &p << endl;
    cout << "Address stored in p (p): " << p << endl;

    cout << "Value of str (str): " << str << endl;
    cout << "Address of str (&str): " << &str << endl;

    return 0;
}