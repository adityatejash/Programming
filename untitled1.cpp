#include <iostream>
using namespace std;

int points(const int& N){
    return N*(N-1)/2;
}
int main(){
    int T;
    cin >> T;
    int testCases[T];
    int testCasesPoints[T];
    for (int i=0; i<T; i++){
        int N;
        cin >> N;
        testCasesPoints[i] = points(N);
    }
    for (int i=0; i<T; i++){
        cout << testCasesPoints[i];
        if (T-1 != i){
            cout << "\n";
        }
    }
    return 0;
}