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

int findIndex(vector<int>& in, int start, int end, int val) {
    for (int i = start; i <= end; i++)
        if (in[i] == val) return i;
    return -1;
}

Node* build(vector<int>& pre, vector<int>& in, int& idx, int l, int r) {
    if (l > r) return NULL;
    int rootVal = pre[idx++];
    Node* root = new Node(rootVal);

    int mid = findIndex(in, l, r, rootVal);

    root->left = build(pre, in, idx, l, mid - 1);
    root->right = build(pre, in, idx, mid + 1, r);

    return root;
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int idx = 0;
    return build(preorder, inorder, idx, 0, inorder.size() - 1);
}

int main() {
    int n;
    cin >> n;

    vector<int> preorder(n), inorder(n);
    for (int i = 0; i < n; i++) cin >> preorder[i];
    for (int i = 0; i < n; i++) cin >> inorder[i];

    Node* root = buildTree(preorder, inorder);
    return 0;
}
