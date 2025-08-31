// Factorial of a number. 

#include <iostream>
using namespace std;

int main() {
    int n, f = 1 ;

    cout << "Enter Number: ";
    cin >> n ;

    for (int i=n; i>1; i--){
        f *= i;
    }

    cout << "Factorial of " << n << "! is " << f << "." << endl;

    return 0;
}
