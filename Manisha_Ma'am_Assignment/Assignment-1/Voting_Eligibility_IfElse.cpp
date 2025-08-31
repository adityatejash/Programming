/* Write a program to enter age and display a message whether the user is eligible for voting or not. Use if-else statement.*/

#include <iostream>
using namespace std;

int main() {
    int age;

    cout << "Enter your age: ";
    cin >> age;

    if (age >= 18) {
        cout << "You are eligible to vote!" << endl;
    } 
    else {
        cout << "You are NOT eligible to vote. You must be at least 18 years old." << endl;
    }

    return 0;
}
