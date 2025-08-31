// Q1. Write a C++ program to input an array of integers, display the array, and find the sum of all elements using functions with proper function prototyping.
#include <iostream>
using namespace std;
void input(int array[], int size){
    for (int i=0; i<size; i++){
        cout << "Enter element " << i+1 << ": ";
        cin >> array[i];
    }
} 
void display(int array[], int size){
    for (int i=0; i<size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}
int summation(int array[], int size){
    int sum = 0;
    for (int i=0; i<size; i++){
        sum += array[i];
    }
    return sum;
}
int main(){
    int size;
    cout << "Enter size of an array: ";
    cin >> size;
    int array[size];
    input(array, size);
    display(array,size);
    cout << "Sum: "<< summation(array,size);
    return 0;
}