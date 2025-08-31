/* Program to print the largest of three numbers. */

#include <iostream>
using namespace std;

int main(){
    int a, b, c;

    cout << "Enter the three numbers: " ;
    cin >> a >> b >> c;

    cout << "The Largest Number is " << ((a > b && a > c) ? a : (b > c ? b : c)) << "." << endl;

    return 0;
}