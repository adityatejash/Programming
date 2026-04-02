#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& v, int l, int mid, int r) {

    int i = l;
    int j = mid + 1;

    vector<int> temp;

    while (i <= mid && j <= r) {
        if (v[i] <= v[j])
            temp.push_back(v[i++]);
        else
            temp.push_back(v[j++]);
    }

    while (i <= mid)
        temp.push_back(v[i++]);

    while (j <= r)
        temp.push_back(v[j++]);

    for (int k = 0; k < temp.size(); k++) {
        v[l + k] = temp[k];
    }
}

void mergeSort(vector<int>& arr, int l, int r) {

    if (l >= r)
        return;

    int mid = (l + r) / 2;

    mergeSort(arr, l, mid);        
    mergeSort(arr, mid + 1, r);    

    merge(arr, l, mid, r);         
}

void printArray(vector<int> v){
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> a = {
        8, 9, 4, -5, 3, 84, 15, -75, 27, -13, 56, 91, -42, 67, 33, -10, 2, 14, -31, 79, 60, -23, 7, -90, 18, 45, -67, 39, -8, 22, 51, 11, -19, 73, -2, 5, 88, -45, 64, -36, 99, -55, 12, 37, -6, 85, 41, -77, 23, 59, -33, 26, 44, -20, 70, -18, 35, -48, 62, -28, 94, -15, 10, 80, -50, 46, -3, 58, -25, 29, 92, -9, 53, -60, 19, 76, -12, 31, 43, -17, 68, -40, 32, 21, -61, 6, 66, -27, 90, -84, 28, 13, -72, 54, -35, 97, 17, -58, 30, 42
    };

    mergeSort(a, 0, a.size()-1);

    cout << "MergeSort: ";
    printArray(a);
}
