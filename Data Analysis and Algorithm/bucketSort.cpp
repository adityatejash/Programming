#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(vector<float>& arr) {
    int n = arr.size();

    vector<vector<float>> bucket(n);

    for (int i = 0; i < n; i++) {
        int index = n * arr[i];
        bucket[index].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        sort(bucket[i].begin(), bucket[i].end());
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (float value : bucket[i]) {
            arr[k++] = value;
        }
    }
}

int main() {
    vector<float> arr = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};

    bucketSort(arr);

    cout << "Sorted array: ";
    for (float x : arr) {
        cout << x << " ";
    }

    return 0;
}
