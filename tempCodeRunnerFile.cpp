#include <bits/stdc++.h>
using namespace std;

void print(int top, char stack[]){
    for (int i=top; i>=0; i--){
        cout << stack[i] << endl;
    }
}

// int main(){
//     string s = "aditya prakash";

//     char stack[s.size()];
//     int top = -1;

//     // Push
//     for (int i=0; i<s.size(); i++){
//         stack[++top] = s[i];
//     }

//     // Pop
//     while (top != -1){
//         cout << stack[top--];
//     }

//     print(top, stack);
// }


int main(){
    char a = 'z';
    cout << int(a) - 97;
}