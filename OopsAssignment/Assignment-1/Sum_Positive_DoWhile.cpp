/* Sum of Positive Numbers Only (Using do While) */ 

#include <iostream>
using namespace std;

int main() {
    double num, sum = 0;

    cout << "Enter numbers to sum (enter a negative number to stop):" << endl;

    do {
        cin >> num;

        if (num >= 0) {
            sum += num;
        }

    } 
    while (num >= 0); 
    
    cout << "Sum of positive numbers is: " << sum << endl;

    return 0;
}
