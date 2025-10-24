#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node (int value){
        data = value;
        left = right = nullptr;
    }
};

node* insert (node* root, int value){
    if (root == nullptr){
        return new node(value);
    }

    if (value < root->data){
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

void inOrder (node* root){
    if (root != nullptr){
        inOrder(root->left);
        cout << root->data << ", "; 
        inOrder(root->right);
    }
    return;
}

void preOrder (node* root){
    if (root != nullptr){
        cout << root->data << ", "; 
        preOrder(root->left);
        preOrder(root->right);
    }
    return;
}

void postOrder (node* root){
    if (root != nullptr){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << ", "; 
    }
    return;
}

int main(){
    node* root = nullptr;

    int n, value;

    cout << "Enter number of nodes: " ;
    cin >> n;

    for (int i=0; i<n; i++){
        cout << "Enter Value " << i+1 << ": ";
        cin >> value;
        root = insert(root, value);
    }

    cout << "Inorder: ";
    inOrder(root);
    cout << endl;

    cout << "preOrder: ";
    preOrder(root);
    cout << endl;
    
    cout << "postOrder: ";
    postOrder(root);    
    cout << endl;

    return 0;
}