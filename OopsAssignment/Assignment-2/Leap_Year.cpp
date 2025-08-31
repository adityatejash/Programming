// Leap Year

#include <iostream>
using namespace std;

int main(){
    int n;

    cout << "Enter Year: ";
    cin >> n;

    cout << "The Year " << n << " is" << ((n%4 == 0 && n%100 != 0) || (n%400 == 0) ? "" : " not" ) << " a Leap Year." << endl;

    return 0;
}