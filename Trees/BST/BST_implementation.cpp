#include <iostream>
using namespace std;

#define TYPE int
class Node {
    public:
    TYPE data;
    Node* left;
    Node* right;

    Node(TYPE val) : data(val) , left(nullptr), right(nullptr) {}

};

int findmin(Node *root) {
    if(root == NULL) {
        cout<<"Empty Tree\n";
        return -1;
    }
    while(root->left) {
        root = root->left;
    }

    return root->data;
}

int findmax(Node *root) {
    if(root == NULL) {
        cout<<"Empty Tree\n";
        return -1;
    }
    while(root->right) {
        root = root->right;
    }

    return root->data;
}

void searchNode (Node *root, TYPE data)  {
    if(root == NULL) {
        cout<<"Empty Tree\n";
        return;
    }
    while(root) {
        if (data == root->data) {
            cout<<data<<" found in Tree\n";
            return;
        }
        else if ( data < root->data) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    cout<<data<<" not found in tree\n";
    return;
}

void insert(Node **root, TYPE val) {
    Node *newNode = new Node(val); 
    if(*root == NULL) {
        *root = newNode;
        return;
    }

    Node *temp = *root;
    Node *parent = NULL;
    int flag ;
    while(temp) {
        if(val < temp->data) {
            parent = temp;
            flag = 0;
            temp = temp->left;
        }
        else if(val > temp->data) {
            parent = temp;
            flag = 1;
            temp = temp->right;
        }
        else {
            cout<<"No duplicates\n";
            return;
        }
    }
    if(flag) {
        parent->right = newNode;
    }
    else {
        parent->left = newNode;
    }
    return; 
}


void deleteNode(Node **root, TYPE val) {
    if (*root == NULL) {
        cout<<"Error: Empty Tree\n";
        return;
    }

    Node *temp = *root;
    Node *parent = *root;
    int flag;
    while(temp) {
        if (val < temp->data) {
            flag = 0;
            parent = temp;
            temp = temp->left;
        }
        else if (val > temp->data) {
            flag = 1;
            parent = temp;
            temp = temp->right;
        }
        else {
            if(temp->left == NULL && temp->right == NULL) {
                if (flag) parent->right = NULL;
                else parent->left = NULL;
                delete temp;
                return;
            }
            else if(temp->left == NULL && temp->right != NULL) {
                if (flag) parent->right = temp->right;
                else parent->left = temp->right;
                delete temp;
                return;
            }
            else if(temp->left != NULL && temp->right == NULL) {
                if (flag) parent->right = temp->left;
                else parent->left = temp->left;
                delete temp;
                return;
            }
            else {
                int res = findmin(temp->right);
                deleteNode(root, res);
                temp->data = res;
                return;
            }
        }
    }
    cout<<"Element not found\n";
    return;  
}

void inorder(Node *root) {
    if(root) {
        inorder(root->left);
        cout<<root->data<<", ";
        inorder(root->right);
    }
}

void preorder(Node *root) {
    if(root) {
        cout<<root->data<<", ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root) {
    if(root) {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<", ";
    }
}

unsigned int total_nodes(Node *root) {
    if(root == NULL) return 0;
    int left = total_nodes(root->left);
    int right = total_nodes(root->right);
    
    return left+right+1;
}
unsigned int height_of_tree(Node *root) {
    if(root == NULL) return 0;
    int left = height_of_tree(root->left);
    int right = height_of_tree(root->right);

    if(left>right)  return left+1;
    else return right+1;
}
int main() {
    Node* root = NULL;

    while (true) {
        cout<<"Press\n1. To Insert\n2. To View Inorder tree\n3. To View Postorder tree\n4. To View Preorder tree\n5. To Find min\n6. To find max\n7. To search data\n8. To delete node\n9. Height of tree\n10. Total nodes\n11. Exit\n";
        int choice;
        cin>>choice;
        switch(choice) {
            case 1:
            {
                TYPE val;
                cout<<"Enter data to insert: ";
                cin>>val;
                insert(&root, val);
                break;
            }
            case 2:
            inorder(root);
            cout<<endl;
            break;
            case 3:
            postorder(root);
            cout<<endl;
            break;
            case 4:
            preorder(root);
            cout<<endl;
            break;
            case 5:
            cout<<"Min: "<<findmin(root)<<endl;
            break;
            case 6:
            cout<<"Max: "<<findmax(root)<<endl;
            break;
            case 7:
            {
                TYPE data;
                cout<<"Enter the data to search: ";
                cin>>data;
                searchNode(root, data);
                break;
            }
            case 8:
            {
                TYPE data;
                cout<<"Enter the data to delete: ";
                cin>>data;
                deleteNode(&root, data);
                break;
            }
            case 9:
            cout<<"Height: "<<height_of_tree(root)<<endl;
            break;
            case 10:
            cout<<"Total nodes: "<<total_nodes(root)<<endl;
            break;
            case 11:
            return 0;
        }
    }
    
    return 0;
}