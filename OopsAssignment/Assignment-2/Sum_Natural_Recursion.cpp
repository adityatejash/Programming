// Sum of natural number using recursion

#include <iostream>
using namespace std;

int sumOfNaturalNumbers(int n) {
    if (n == 1)
        return 1;
    else
        return n + sumOfNaturalNumbers(n - 1);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Sum of natural numbers up to " << num << " is " << sumOfNaturalNumbers(num) << endl;
    
    return 0;
}
