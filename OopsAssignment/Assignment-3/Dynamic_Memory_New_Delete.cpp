// WAP to allocate dynamic memory allocation using new and delete operator.

#include <iostream>
using namespace std;

int main(){
    int *p1 = new int;
    float *p2 = new float(264.86);
    int *p3 = new int[5];
    *p1 = 10;

    cout << "*p1: " << *p1 << endl;
    cout << "*p2: " << *p2 << endl;

    if (!p3){
        cout << "Memory not allocated.\n" ;
    }
    else {
        for (int i=0; i<5; i++){
            p3[i] = i*20;
        }
        for (int i=0; i<5; i++){
            cout << "p3[" << i << "]: " << p3[i] << endl;
        }
    }
    delete p1;
    delete p2;
    delete[] p3;
}