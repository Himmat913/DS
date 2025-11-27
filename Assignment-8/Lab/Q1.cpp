#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* buildTree() {
    int val;
    cout << "Enter value (-1 for NULL): ";
    cin >> val;

    if (val == -1) return nullptr;

    Node* root = new Node(val);

    cout << "Enter left child of " << val << ":\n";
    root->left = buildTree();

    cout << "Enter right child of " << val << ":\n";
    root->right = buildTree();

    return root;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    cout << "Build your tree:\n";
    Node* root = buildTree();

    cout << "\nPre-order Traversal: ";
    preorder(root);

    cout << "\nIn-order Traversal: ";
    inorder(root);

    cout << "\nPost-order Traversal: ";
    postorder(root);

    cout << endl;
    return 0;
}
