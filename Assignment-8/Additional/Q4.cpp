#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* buildTree() {
    int val;
    cin >> val;
    if (val == -1) return nullptr;
    Node* root = new Node(val);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

vector<int> rightSideView(Node* root) {
    vector<int> ans;
    if (!root) return ans;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            Node* node = q.front();
            q.pop();
            if (i == sz - 1) ans.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return ans;
}

vector<int> leftSideView(Node* root) {
    vector<int> ans;
    if (!root) return ans;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            Node* node = q.front();
            q.pop();
            if (i == 0) ans.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return ans;
}

int main() {
    Node* root = buildTree();

    vector<int> rightView = rightSideView(root);
    vector<int> leftView = leftSideView(root);

    for (int x : rightView) cout << x << " ";
    cout << "\n";

    for (int x : leftView) cout << x << " ";
    cout << "\n";
}
