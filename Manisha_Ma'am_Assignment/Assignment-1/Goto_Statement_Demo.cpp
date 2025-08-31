/*Write a program to demonstrate the use of goto statement.*/

#include <iostream>
using namespace std;

int main() {
    int n;

input:
    cout << "Enter Positive Number: ";
    cin >> n;
    if (n < 0) {
        cout << "Invalid Input! Please Enter a Positive Number.\n";
        goto input;
    }
    cout << "You entered " << n << endl;

    return 0;
}
