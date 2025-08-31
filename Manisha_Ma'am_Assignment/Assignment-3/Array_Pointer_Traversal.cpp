#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50}; 
    int *ptr = arr; 
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Array elements using pointer:\n";
    for (int i = 0; i < size; i++) {
        cout << "Element at index " << i << " is: " << *(ptr + i) << endl; 
    }

    return 0;
}