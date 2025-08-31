/* Write a program to declare the price of the book with if statement and check its price. If its price is less than or equal to 600, print the output with some comment, else terminate.*/

#include <iostream>

using namespace std;

int main() {
    int price;

    cout << "Enter the price of the book: ";
    cin >> price;

    cout << "The book is " << (price <= 600 ? "" : "NOT ") << "affordable. Price: " << price << "\n";
    
    return 0;
}
