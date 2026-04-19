#include<iostream>
#include<vector>
using namespace std;

int recursive (vector<int>& arr, int l, int u, int target){
    if (l > u){
        return 0;
    }
    int mid = (l + u) / 2;
    if (target == arr[mid]){
        return 1;
    } 

    if (target < arr[mid]){
        return recursive(arr, l, mid-1, target);
    } else {
        return recursive (arr, mid+1, u, target);
    }

    return 0;
}

int iterative(vector<int>& v, int l, int r, int key) {
    while (l <= r){
        int m = (l+r)/2;
        
        if (v[m] == key) return 1;

        else if (key < v[m]){
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return 0;
}

int main(){
    vector<int> v;
    v = {1,2,3,4,5,6,7,8,9,10};

    int target = 5;

    // int found = recursive(v,0, v.size()-1, target);
    // cout << found;
    
    
    int found = iterative(v, 0, v.size(), target);

    cout <<( found ? "Found" : "NOT Found" );
}