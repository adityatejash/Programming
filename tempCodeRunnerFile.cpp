#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

int func (vector<int> v, int k){
    vector<int> t;
    int sum = 0;
    for (int i : v){
        sum += i;
        t.push_back(sum);
    }

    vector<int> nv;
    for (int i=1; i<t.size(); i++){
        if (t[i] <= k){
            nv.push_back(v[i]);
            nv.push_back(v[i-1]);
        }
    }
    return nv.size();
}

int main(){
    vector<int> v = {1,-1,5,-2,3};
    int k = 3;
    cout << func (v, k);
}