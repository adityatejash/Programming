#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void display(const vector<int> &vec) {
    for (int i : vec)
        cout << i << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {5, 6, 8, 4, 3};
    vector<int> even, odd, merged;

    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) even.push_back(arr[i]);
        else odd.push_back(arr[i]);
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    int e = 0, o = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) merged.push_back(even[e++]);
        else merged.push_back(odd[o++]);
    }

    int found = 0;
    for (int i = 0; i < merged.size() - 1; i++) {
        if (merged[i] > merged[i + 1]) {
            found = 1;
            break;
        }
    }

    cout << "Original: ";
    display(arr);

    cout << "Even: ";
    display(even);

    cout << "Odd: ";
    display(odd);

    cout << "Merged: ";
    display(merged);

    if (!found)
        cout << "OK" << endl;
    else
        cout << "Error" << endl;

    return 0;
}
