#include <iostream>
using namespace std;

int main(){
    int *number = new int;
    int *length = new int(0);
    cout << "Enter: ";
    cin >> *number;
    while (*number > 0){
        *number /= 10;
        (*length)++;
    }
    cout << "Length of number is " << *length << endl;
}