#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct cmp {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCode(Node* root, string s) {
    if (!root) return;

    if (root->ch != '$')
        cout << root->ch << " : " << s << endl;

    printCode(root->left, s + "0");
    printCode(root->right, s + "1");
}

int main() {
    char ch[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int n = 6;

    priority_queue<Node*, vector<Node*>, cmp> pq;

    for (int i = 0; i < n; i++)
        pq.push(new Node(ch[i], freq[i]));

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* node = new Node('$', left->freq + right->freq);
        node->left = left;
        node->right = right;

        pq.push(node);
    }

    printCode(pq.top(), "");
    return 0;
}
