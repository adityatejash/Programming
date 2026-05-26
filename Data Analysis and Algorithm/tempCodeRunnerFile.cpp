#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<vector<int>> v = {
        {1,5,6},
        {2,4,9},
        {9,-1,0}
    };

    sort(v.begin(), v.end());

    for (auto& row : v) {
        for (auto& x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}