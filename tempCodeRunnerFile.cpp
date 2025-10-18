#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s = "HELLO";
    s.erase(0, 1);   // erase(position = 0, length = 1)
    cout << s;       // Output: ELLO
    cout << s.size(); 
}