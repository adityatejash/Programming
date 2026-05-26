#include<iostream>
#include<vector>
using namespace std;

int partition (vector<int>& v, int low, int high){
    int pivot = v[low];
    int i = low + 1;
    int j = high;

    while (i <= j){
        while (i <= high && v[i] <= pivot){
            i++;
        }

        while (j >= low && v[j] > pivot){
            j--;
        }

        if (i < j){
            swap(v[i], v[j]);
        }
    }

    swap(v[low], v[j]);
    return j;
}

void quickSort (vector<int>& v, int low, int high){
    if (low < high){
        int pi = partition(v, low, high);
        quickSort(v, low, pi-1);
        quickSort(v, pi+1, high);
    }
}

void print(vector<int> v) {
    for (int i : v) {
        cout << i << ", ";
    }
    cout << endl;
}

int main() {
    vector<int> v = {4, 5, 6, 67, 3, 35, 6, 1};

    quickSort(v, 0, v.size()-1);
    print(v);

    return 0;
}