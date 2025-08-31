#include <iostream>
using namespace std;

int main(){
    int arr[5];
    int *p[5];

    cout << "Enter Input: ";
    for (int i=0; i<5; i++){
        cin >> arr[i] ;
        p[i] = &arr[i];
    }

    cout << "The Addresses are: " << endl ;
    for (int i=0; i<5; i++){
        cout << "arr[" << i << "]: " << arr[i] << " and p[" << i << "]: " << p[i] << endl;
    }

    return 0;
}