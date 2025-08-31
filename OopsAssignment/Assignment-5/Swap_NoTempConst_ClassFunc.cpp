// WAP to swap two numbers without third variable. The swapping must be done in a function of a particular class.
#include <iostream>
using namespace std;
class swapping{
public:
    void swap_numbers(int &a, int &b){
        a = a + b; 
        b = a - b;
        a = a - b;
    }
};
int main(){
    int a=72, b=13;

    cout << "Before Swapping A = " << a << " B = " << b << endl;

    swapping object;
    object.swap_numbers(a,b);

    cout << "After Swapping A = " << a << " B = " << b << endl;
}