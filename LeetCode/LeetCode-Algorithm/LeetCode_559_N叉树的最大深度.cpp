// 给定一个 N 叉树，找到其最大深度。

// 最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。

// 例如，给定一个 3叉树 :


// 我们应返回其最大深度，3。

// 说明:

// 树的深度不会超过 1000。
// 树的节点总不会超过 5000。

#include <vector>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution1 {
public:
    int maxDepth(Node* root) {
        int res{};
        func(root, 1, res);
        return res;
    }
    void func(Node* node, int cur, int& res) {
        if (!node) return;
        if (node->children.empty()) res = max(res, cur);
        for (auto child : node->children) {
            func(child, cur+1, res);
        }
    }
};

class Solution2 {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        int res{1};
        for (auto child : root->children) {
            res = max(res, maxDepth(child) + 1);
        }
        return res;
    }
};

// 用队列，迭代
class Solution3 {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        int res{0};
        queue<Node*> q{{root}};
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                auto t = q.front();
                q.pop();
                for (auto child : t->children) {
                    if (child)
                        q.push(child);
                }
            }
            ++res;
        }
        return res;
    }
};