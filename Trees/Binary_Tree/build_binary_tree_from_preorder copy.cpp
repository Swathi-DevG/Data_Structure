#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define TYPE int
class Node {
    public:
    TYPE data;
    Node *left;
    Node *right;

    Node(TYPE data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

Node* buildTree(vector<TYPE> preorder) {
    static int index = -1;
    index++;

    if (preorder[index] == -1) return NULL;

    Node *root = new Node(preorder[index]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

void preorderTraverse(Node *root) {
    if(root == nullptr) {
        cout<<"-1, ";
        return;
    }
    cout<<root->data<<", ";
    preorderTraverse(root->left);
    preorderTraverse(root->right);

    return;
}

int main() {
    vector<TYPE> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(preorder);
    preorderTraverse(root);
    
    return 0;
}