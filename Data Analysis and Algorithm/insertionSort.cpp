#include <iostream>
#include <vector>
using namespace std;

void insertion(vector<int>& v) {
    for (int i = 1; i < v.size(); i++) {
        int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = key;
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

    insertion(v);
    print(v);

    return 0;
}
