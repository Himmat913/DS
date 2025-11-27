#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x; left = right = nullptr; 
    }
};

Node* insert(Node* root, int val){
    if(root == nullptr) 
        return new Node(val);
    if(val < root->data)
        root->left = insert(root->left, val);
    else 
        root->right = insert(root->right, val);
    return root;
}

Node* searchRecursive(Node* root, int key){
    if(root == nullptr || root->data == key) 
        return root;
    if(key < root->data) {
        return searchRecursive(root->left, key);
    }
    return searchRecursive(root->right, key);
}

Node* searchIterative(Node* root, int key){
    while(root != nullptr && root->data != key){
        if(key < root->data) 
            root = root->left;
        else 
            root = root->right;
    }
    return root;
}

Node* minElement(Node* root){
    if(!root) 
        return nullptr;
    while(root->left) 
        root = root->left;
    return root;
}

Node* maxElement(Node* root){
    if(!root) 
        return nullptr;
    while(root->right) {
        root = root->right;
    }
    return root;
}

Node* inorderSuccessor(Node* root, Node* node){
    if(node == nullptr)
        return nullptr;

    if(node->right)
        return minElement(node->right);

    Node* succ = nullptr;
    Node* p = root;

    while(p != nullptr){
        if(node->data < p->data){
            succ = p;
            p = p->left;
        }
        else if(node->data > p->data){
            p = p->right;
        }
        else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* node){
    if(node == nullptr) return nullptr;

    if(node->left)
        return maxElement(node->left);

    Node* pred = nullptr;
    Node* p = root;

    while(p != nullptr){
        if(node->data > p->data){
            pred = p;
            p = p->right;
        }
        else if(node->data < p->data){
            p = p->left;
        }
        else break;
    }
    return pred;
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

    cout << "Inorder: "; inorder(root); cout << "\n";

    int key = 15;

    Node* r = searchRecursive(root, key);
    Node* it = searchIterative(root, key);

    cout << (r ? "Recursive Found\n" : "Recursive Not Found\n");
    cout << (it ? "Iterative Found\n" : "Iterative Not Found\n");

    cout << "Min: " << (minElement(root) ? minElement(root)->data : -1) << " ";
    cout << "Max: " << (maxElement(root) ? maxElement(root)->data : -1) << "\n";

    cout << "Successor: " << (it ? (inorderSuccessor(root,it) ? inorderSuccessor(root,it)->data : -1) : -1) << "\n";
    cout << "Predecessor: " << (it ? (inorderPredecessor(root,it) ? inorderPredecessor(root,it)->data : -1) : -1) << "\n";

    return 0;
}
