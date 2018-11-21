// 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

// 示例:

// 输入: [1,2,3,null,5,null,4]
// 输出: [1, 3, 4]
// 解释:

//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---

#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 递归
class Solution1 {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return res;
        f(root, 0);
        return res;
    }
    void f(TreeNode* node, int i) {
        if (res.size() == i) // 第一次遇到该层就把这个值压入结果
            res.push_back(node->val);
        if (node->right) f(node->right, i+1);
        if (node->left) f(node->left, i+1);
    }
private:
    vector<int> res;
};

// 层序遍历，取每层的最后一个数
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            int n = q.size();
            TreeNode *node = nullptr;
            for (int i = 0; i < n; ++i) {
                node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(node->val);
        }
        return res;
    }
};