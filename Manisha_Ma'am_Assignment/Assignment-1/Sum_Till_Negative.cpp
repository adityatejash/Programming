/* program to find the sum of positive numbers
if the user enters a negative numbers, break ends the loop
the negative number entered is not added to sum (Using Break) */

#include <iostream>
using namespace std;

int main() {
    double num, sum = 0;

    cout << "Enter numbers to sum (enter a negative number to stop):" << endl;

    while (1) {
        cin >> num;

        if (num < 0) {
            break;
        }

        sum += num;
    }

    cout << "Sum of positive numbers is: " << sum << endl;

    return 0;
}
