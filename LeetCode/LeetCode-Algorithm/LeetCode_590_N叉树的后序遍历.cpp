// 给定一个 N 叉树，返回其节点值的后序遍历。

// 例如，给定一个 3叉树 :

// 返回其后序遍历: [5,6,3,2,4,1].


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
    vector<int> postorder(Node* root) {
        vector<int> res{};
        func(root, res);
        return res;
    }
    void func(Node* node, vector<int>& res) {
        if (!node) return;
        for (auto &child : node->children) {
            func(child, res);
        }
        res.push_back(node->val);
    }
};

// 迭代
class Solution2 {
public:
    vector<int> postorder(Node* root) {
        if (!root) return {};
        vector<int> res{};
        stack<Node*> s{{root}};
        while (!s.empty()) {
            Node *t = s.top();
            s.pop();
            res.insert(res.begin(), t->val); // 插入到最前面
            for (auto &child : t->children) { // 从左往右遍历
                if (child) s.push(child);
            }
        }
        return res;
    }
};