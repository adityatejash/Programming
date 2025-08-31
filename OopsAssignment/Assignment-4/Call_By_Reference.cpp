// wap for call by reference
#include <iostream>
using namespace std;

int swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
    cout << "Inside Function : A --> " << a << ", B --> " << b << endl ;
}

int main(){
    int a, b;
    cout << "Enter Number A & B: ";
    cin >> a >> b;

    cout << "Bofore Function Call : A --> " << a << ", B --> " << b << endl ;
    swap(a, b);
    cout << "After Function Call : A --> " << a << ", B --> " << b << endl ;

    return 0;
}