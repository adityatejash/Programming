#include <iostream>
using namespace std;

int length(int number) {
    int l = 0;
    while (number > 0) {
        number /= 10;
        l++;
    }
    return l;
}

int power(int base, int exp){
    int result =
    for (int i=1; i<=exp; i++){
        result *= base;
    }
    return result;
}

int main() {
    int number, armstrong_number = 0;
    cout << "Enter Number: ";
    cin >> number;

    int original_number = number;
    int l = length(number);

    while (number > 0) {  // Extract digits and calculate sum
        int digit = number % 10;
        armstrong_number += power(digit, l);
        number /= 10;
    }

    cout << "The Number " << original_number << " is ";
    cout << (armstrong_number == original_number ? "" : "not ");
    cout << "an Armstrong Number.\n";
}
