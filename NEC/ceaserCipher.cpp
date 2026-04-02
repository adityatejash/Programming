#include <iostream>
using namespace std;

string encrypt (string& s, int key){
    // Encrypt
    for (int i=0; i<s.size(); i++){
        char base;
        if (isalpha(s[i])){
            if (isupper(s[i])){
                base = 'A';
            } else {
                base = 'a';
            }
        }
        s[i] = (s[i] - base + key) % 26 + base;
    }
    return s;
}

string decrypt (string& s, int key){
    // Decrypt
    for (int i=0; i<s.size(); i++){
        char base;
        if (isalpha(s[i])){
            if (isupper(s[i])){
                base = 'A';
            } else {
                base = 'a';
            }
        }
        s[i] = (s[i] - base - key + 26) % 26 + base ;
    }
    return s;    
}

int main(){
    string s;
    int key;

    cout << "Enter string and key: ";
    cin >> s >> key;

    cout << "Decrypt: " ;
    cout << decrypt(s,key) << endl;

    cout << "Encrypt: " ;
    cout << encrypt(s,key) << endl;
}