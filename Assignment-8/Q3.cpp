#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int val){
    if(root == nullptr)
        return new Node(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else if(val > root->data)
        root->right = insert(root->right, val);

    return root;
}

Node* minElement(Node* root){
    if(!root)
        return nullptr;
    while(root->left)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key){
    if(root == nullptr)
        return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);

    else if(key > root->data)
        root->right = deleteNode(root->right, key);

    else{
        if(root->left == nullptr){
            Node* t = root->right;
            delete root;
            return t;
        }
        else if(root->right == nullptr){
            Node* t = root->left;
            delete root;
            return t;
        }
        Node* t = minElement(root->right);
        root->data = t->data;
        root->right = deleteNode(root->right, t->data);
    }
    return root;
}

int maxDepth(Node* root){
    if(!root)
        return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return (l > r ? l : r) + 1;
}

int minDepth(Node* root){
    if(!root)
        return 0;

    int l = minDepth(root->left);
    int r = minDepth(root->right);

    if(root->left == nullptr || root->right == nullptr)
        return l + r + 1;

    return (l < r ? l : r) + 1;
}

void inorder(Node* root){
    if(!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    Node* root = nullptr;

    int arr[] = {20, 10, 30, 5, 15, 25, 35};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    cout << "Inorder: ";
    inorder(root);
    cout << "\n";

    int key = 10;

    root = deleteNode(root, key);

    cout << "After deleting " << key << ": ";
    inorder(root);
    cout << "\n";

    cout << "Max Depth: " << maxDepth(root) << "\n";
    cout << "Min Depth: " << minDepth(root) << "\n";

    return 0;
}
