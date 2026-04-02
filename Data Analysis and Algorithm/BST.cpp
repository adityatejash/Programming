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

int main(){
    vector<int> v;
    v = {1,2,3,4,5,6,7,8,9,10};

    int target = 0;

    int found = recursive(v,0, v.size()-1, target);
    // cout << found;

    cout <<( found ? "Found" : "NOT Found" );
}