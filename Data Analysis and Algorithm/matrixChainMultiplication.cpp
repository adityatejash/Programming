#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int p[] = {5, 4, 6, 2, 7};

    int m[n][n] = {0};
    int s[n][n] = {0};

    for (int d = 2; d < n; d++){
        for (int i=1; i<n-d+1; i++){
            int j = i+d-1;
            m[i][j] = 1000000000;
        
            for (int k=i; k<j; k++){
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum Cost: " << m[1][n-1] << endl;
}
