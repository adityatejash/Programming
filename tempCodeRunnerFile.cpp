#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

long long ncr(int n, int r) {
    r = min (r, n-r);

    int res = 1;
    for (int i=1; i<=r; i++){
        res = res * (n + 1 - i) / i;
    }

    return res;
}

long long npr (int n, int r){
    long long res = 1;

    for (int i=0; i<r; i++){
        res *= (n - i);
    }

    return res;
}

int main() {
    int n = 10;
    int r = 6;

    cout << ncr(n, r) << endl;
    cout << npr(n, r) << endl;
}