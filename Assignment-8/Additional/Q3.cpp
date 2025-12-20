#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return NULL;
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size()) {
        Node* cur = q.front();
        q.pop();
        if (arr[i] != -1) {
            cur->left = new Node(arr[i]);
            q.push(cur->left);
        }
        i++;
        if (i < arr.size() && arr[i] != -1) {
            cur->right = new Node(arr[i]);
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    int L = maxDepth(root->left);
    int R = maxDepth(root->right);
    return 1 + max(L, R);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) 
    cin >> arr[i];
    Node* root = buildTree(arr);
    cout << maxDepth(root);
}
