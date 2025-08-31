/* Write a program to enter the percentage of marks obtained by a student and display the class obtained.*/

#include <iostream>

using namespace std;

int main() {
    float percentage;

    cout << "Enter the percentage of marks obtained: ";
    cin >> percentage;

    if (percentage >= 70 && percentage <= 100) {
        cout << "First Class" << endl;
    } 
    else if (percentage >= 50 && percentage < 70) {
        cout << "Second Class" << endl;
    } 
    else if (percentage >= 30 && percentage < 50) {
        cout << "Third Class" << endl;
    } 
    else if (percentage >= 0 && percentage < 30) {
        cout << "Fail Class" << endl;
    } 
    else {
        cout << "Percentage should be between 0 to 100 only." << endl;
    }

    return 0;
}
