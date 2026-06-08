#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    struct Node {
        Node* child[26];
        bool isEnd;

        Node() {
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
            isEnd = false;
        }
    };

    Node* root = new Node();

    void insert(string s) {
        Node* temp = root;

        for (char c : s) {
            int ind = c - 'a';

            if (temp->child[ind] == nullptr) {
                temp->child[ind] = new Node();
            }

            temp = temp->child[ind];
        }

        temp->isEnd = true;
    }

    bool search (string s){
        Node* temp = root;

        for (char c : s){
            int ind = c - 'a';

            if (temp->child[ind] == nullptr) return false;

            temp = temp->child[ind];
        }

        return temp->isEnd;
    }

    bool prefix (string s){
        Node* temp = root;

        for (char c : s){
            int ind = c - 'a';

            if (temp->child[ind] == nullptr) return false;

            temp = temp->child[ind];
        }

        return true;
    }
};

int main() {
    Trie obj;

    obj.insert("abcd");
    obj.insert("acd");

    cout << obj.search("abcd") << endl; // 1
    cout << obj.search("acd") << endl;  // 1
    cout << obj.search("abc") << endl;  // 0
    cout << obj.search("bcd") << endl;  // 0



    cout << obj.prefix("abc") << endl;
}