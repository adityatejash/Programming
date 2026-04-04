#include <iostream>
using namespace std;

// Longest Common Substring

int LCS (int i,  int j, string X, string Y){
    if (i == 0 || j == 0){
        return 0;
    }

    if (X[i - 1] == Y[j - 1]){
        return 1 + LCS (i-1, j-1, X, Y);
    }

    return max(LCS(i-1,j, X, Y), LCS(i,j-1, X, Y));
}

int main(){
    string X = "abdace";
    string Y = "babce";

    int ans = LCS(X.size(), Y.size(), X, Y);

    cout << ans;
}