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

vector<Node*> build(int l, int r) {
    if (l > r) return {NULL};
    vector<Node*> res;
    for (int i = l; i <= r; i++) {
        vector<Node*> L = build(l, i - 1);
        vector<Node*> R = build(i + 1, r);
        for (int a = 0; a < L.size(); a++) {
            for (int b = 0; b < R.size(); b++) {
                Node* root = new Node(i);
                root->left = L[a];
                root->right = R[b];
                res.push_back(root);
            }
        }
    }
    return res;
}

vector<Node*> generateTrees(int n) {
    return build(1, n);
}

void printLevelOrder(Node* root) {
    if (!root) {
        cout << "null\n";
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* t = q.front();
        q.pop();
        if (t) {
            cout << t->val << " ";
            q.push(t->left);
            q.push(t->right);
        } else {
            cout << "null ";
        }
    }
    cout << "\n";
}

int main() {
    int n;
    cin >> n;
    vector<Node*> trees = generateTrees(n);
    for (int i = 0; i < trees.size(); i++) {
        printLevelOrder(trees[i]);
    }
}
