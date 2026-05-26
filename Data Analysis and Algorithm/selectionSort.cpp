#include<iostream>
#include<vector>
using namespace std;

void selection (vector<int>& v){
    for (int i=0; i<v.size()-1; i++){
        int min = i;

        for (int j=i+1; j<v.size(); j++){
            if (v[j] < v[min]){
                min = j;
            }
        }

        swap(v[min], v[i]);
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

    selection(v);
    print(v);

    return 0;
}
