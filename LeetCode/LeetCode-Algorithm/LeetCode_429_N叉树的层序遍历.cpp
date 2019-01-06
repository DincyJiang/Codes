// 给定一个 N 叉树，返回其节点值的层序遍历。 (即从左到右，逐层遍历)。

// 例如，给定一个 3叉树 :

// 返回其层序遍历:

// [
//      [1],
//      [3,2,4],
//      [5,6]
// ]
 

// 说明:

// 树的深度不会超过 1000。
// 树的节点总数不会超过 5000。

#include <vector>
#include <queue>

using std::queue;
using std::vector;

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

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        vector<vector<int>> res{};
        queue<Node*> q{{root}};
        while (!q.empty()) {
            vector<int> vec{};
            for (int i = q.size(); i > 0; --i) {
                auto t = q.front();
                q.pop();
                vec.push_back(t->val);
                if (!t->children.empty()) {
                    for (auto node : t->children)
                        q.push(node);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};