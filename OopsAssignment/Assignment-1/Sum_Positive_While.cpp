/* Sum of Positive Numbers Only (Using While) */

#include <iostream>
using namespace std;

int main(){
    double n, s = 0;
    
    cout << "Enter Positive Number: ";
    while (1){
        cin >> n ;
        
        if (n < 0){
            break;
        }

        s += n;
    }
    cout << "Sum of Positive Number is " << s << "." << endl ;

    return 0;
}