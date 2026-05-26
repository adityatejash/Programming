#include<iostream>
#include<vector>
using namespace std;

void bubble(vector<int>& v){
    for (int i=0; i<v.size()-1; i++){
        for (int j=0; j<v.size()-i-1; j++){
            if (v[j] > v[j+1]){
                swap(v[j+1], v[j]);
            }
        }
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

    bubble(v);
    print(v);

    return 0;
}
