// 给定一个 N 叉树，返回其节点值的前序遍历。

// 例如，给定一个 3叉树 :

// 返回其前序遍历: [1,3,5,6,2,4]。

// 说明: 递归法很简单，你可以使用迭代法完成此题吗?

#include <vector>
#include <stack>

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

// 递归
class Solution1 {
public:
    vector<int> preorder(Node* root) {
        vector<int> res{};
        func(root, res);
        return res;
    }
    void func(Node* node, vector<int>& res) {
        if (!node) return;
        res.push_back(node->val);
        for (auto &child : node->children) {
            func(child, res);
        }
    }
};

// 迭代，栈
class Solution2 {
public:
    vector<int> preorder(Node* root) {
        if (!root) return {};
        vector<int> res{};
        stack<Node*> s{{root}};
        while (!s.empty()) {
            Node *t = s.top();
            s.pop();
            res.push_back(t->val);
            for (int i = t->children.size() - 1; i >= 0; --i) { // 从右往左遍历
                s.push(t->children[i]);
            }
        }
        return res;
    }
};