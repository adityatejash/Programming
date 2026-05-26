#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    vector<int> v;

    while (t--) {
        int w;
        cin >> w;

        vector<int> arr(w);

        for (int i = 0; i < w; i++) {
            cin >> arr[i];
        }

        int sum = 0;
        int ans = 0;

        for (int i = 0; i < w; i++) {
            sum += arr[i];

            if (sum % 3 == 0) {
                ans++;
                sum = 0;
            }
        }

        v.push_back(ans);
    }

    for (int i : v){
        cout << i << endl;
    }

    return 0;
}