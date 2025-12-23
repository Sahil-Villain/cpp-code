#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int data;
    Tree* left;
    Tree* right;

    Tree(int val) {
        data = val;
        left = right = nullptr;
    }
};

Tree* buildtree(vector<int>& pre) {
    if (pre.size() == 0) return nullptr;

    Tree* root = new Tree(pre[0]);
    queue<Tree*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < pre.size()) {
        Tree* curr = q.front();
        q.pop();

        if (i < pre.size() && pre[i] != -1) {
            curr->left = new Tree(pre[i]);
            q.push(curr->left);
        }
        i++;

        if (i < pre.size() && pre[i] != -1) {
            curr->right = new Tree(pre[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void topview(Tree* root) {
    if (!root) return;

    map<int, int> mp; // hd -> node value
    queue<pair<Tree*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        Tree* node = curr.first;
        int hd = curr.second;

        // store first node seen at this horizontal distance
        if (mp.find(hd) == mp.end()) {
            mp[hd] = node->data;
        }

        if (node->left)
            q.push({node->left, hd - 1});

        if (node->right)
            q.push({node->right, hd + 1});
    }

    for (auto &it : mp) {
        cout << it.second << " ";
    }
}

int main() {
    vector<int> v = {1, 2, 3, -1, 4, -1, 5};
    Tree* root = buildtree(v);
    topview(root);
    return 0;
}