#include <iostream>
#include <climits>
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

Node* buildTree(){
    int val;
    cout << "Enter value (-1 for NULL): ";
    cin >> val;

    if(val == -1)
        return nullptr;

    Node* root = new Node(val);

    cout << "Enter left child of " << val << ":\n";
    root->left = buildTree();

    cout << "Enter right child of " << val << ":\n";
    root->right = buildTree();

    return root;
}

bool isBSTUtil(Node* root, int minVal, int maxVal){
    if(root == nullptr)
        return true;

    if(root->data <= minVal || root->data >= maxVal)
        return false;

    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root){
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main(){
    Node* root = buildTree();

    cout << (isBST(root) ? "This is a BST\n" : "This is NOT a BST\n");

    return 0;
}
