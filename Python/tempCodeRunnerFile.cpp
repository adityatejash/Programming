#include <iostream>
#include <vector>
using namespace std;

int grayCode(int n) {
    return n ^ (n >> 1);
}

// void Prime (int k, vector<int>& v){
//     v.push_back(6 * k - 1);
//     v.push_back(6 * k + 1);
    
//     return;
// }

int main(){
    // vector<int> v = {2,3};
    // int n = 501;

    // int i = 1;
    // while (v.size() < n){
    //     Prime (i, v);
    //     i++;
    // }

    // for (int i : v){
    //     cout << i << ", ";
    // }

    // cout << endl;

    // cout << v.size();


    int a = 5;
    cout << (a << 1);
}