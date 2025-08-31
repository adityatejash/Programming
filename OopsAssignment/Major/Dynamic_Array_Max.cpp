// Q7. Implement a program to dynamically allocate memory for an a of integers, input values, find the maximum element, and then deallocate the memory.
#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int* a = new int[n];
    for (int i=0; i<n; i++){
        cout << "Enter element " << i+1 << ": ";
        cin >> a[i];
    }
    int max = a[0];
    for (int i=1; i<n; i++){
        if (a[i] > max){
            max = a[i];
        }
    }
    cout << "Maximum element is " << max << endl;
    delete[] a;
    return 0;    
}