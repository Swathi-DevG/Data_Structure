#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define TYPE int
class Node {
    public:
    TYPE data;
    Node *left;
    Node *right;

    Node(TYPE val) {
        data = val;
        left = right = nullptr;
    }

};

Node* buildTree(vector<TYPE> postorder, int &index) {
    
    if (index < 0 || postorder[index] == -1) {
        index--;
        return NULL;
    }

    Node* root = new Node(postorder[index]);
    index --;

    root->right = buildTree(postorder, index);
    root->left = buildTree(postorder, index);
    
    return root;
}

void postorderTraverse(Node *root) {
    if(root == nullptr) {
        cout<<"-1, "; 
        return;
    }
    
    postorderTraverse(root->left);
    postorderTraverse(root->right);
    cout<<root->data<<", ";
    return;
}

int main() {
    vector<TYPE> postorder = { -1, -1, 2, -1, -1, 4, -1, -1, 5, 3, 1 };

    int index = postorder.size() - 1;

    cout<<"Size = "<<index<<endl;
    Node* root = buildTree(postorder, index);

    postorderTraverse(root);

    return 0;
}