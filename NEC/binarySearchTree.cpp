#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode (int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert (Node* root, int value){
    if (root == nullptr){
        return createNode(value);
    }

    value < root->data ? root->left = insert(root->left, value) : root->right = insert(root->right, value);

    return root;
}

bool search (Node* root, int key){
    if (root == nullptr){
        return false;
    }

    if (root->data == key){
        return true;
    }

    if (key < root->data){
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

void inOrder (Node* root){
    if (root == nullptr){
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main(){
    Node* tree = nullptr;
    vector<int> v = {8,9,6,4,2,3,6,7,-5,4,1,0};

    for (int i : v){
        tree = insert(tree, i);
    }

    cout << "InOrder Traversal : ";
    inOrder(tree);

    cout << endl;
    
    int key = 2;
    cout << (search(tree, key) ? "Key FOUND" : "Key NOT Found") ;

    return 0;
}