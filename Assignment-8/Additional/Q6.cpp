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

int findIndex(vector<int>& in, int l, int r, int val) {
    for (int i = l; i <= r; i++)
        if (in[i] == val) return i;
    return -1;
}

Node* build(vector<int>& in, vector<int>& post, int& idx, int l, int r) {
    if (l > r) return NULL;
    int rootVal = post[idx--];
    Node* root = new Node(rootVal);
    int mid = findIndex(in, l, r, rootVal);

    root->right = build(in, post, idx, mid + 1, r);
    root->left = build(in, post, idx, l, mid - 1);

    return root;
}

Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int idx = postorder.size() - 1;
    return build(inorder, postorder, idx, 0, inorder.size() - 1);
}

int main() {
    int n;
    cin >> n;

    vector<int> inorder(n), postorder(n);
    for (int i = 0; i < n; i++) cin >> inorder[i];
    for (int i = 0; i < n; i++) cin >> postorder[i];

    Node* root = buildTree(inorder, postorder);
    return 0;
}
