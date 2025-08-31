/* Create a Calculator using the switch Statement*/

#include <iostream>
using namespace std;

int main(){
    int a, b;
    char o;

    cout << "Enter two number: " ;
    cin >> a >> b;

    cout << "Enter Operation (+, -, *, /): " ;
    cin >> o ;

    switch (o){
        case '+' :{
            cout << "Addition of " << a << " + " << b << " is " << a+b << "." << endl;
            break;
        }
        case '-' :{
            cout << "Subtraction of " << a << " - " << b << " is " << a-b << "." << endl;
            break;
        }
        case '*' :{
            cout << "Multiplication of " << a << " * " << b << " is " << a*b << "." << endl;
            break;   
        }
        case '/' :{
            if (b != 0){    
                cout << "Division of " << a << " / " << b << " is " << a-b << "." << endl;
            }
            else {
                cout << "ERROR! Division by zero not possible." << endl ;
            }
            break;
        }
        default :{
            cout << "Invalid Opearator!" << endl ;
            break;
        }
    }

    return 0;
}