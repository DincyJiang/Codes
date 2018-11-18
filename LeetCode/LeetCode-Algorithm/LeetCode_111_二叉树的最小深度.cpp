// 给定一个二叉树，找出其最小深度。

// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

// 说明: 叶子节点是指没有子节点的节点。

// 示例:

// 给定二叉树 [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回它的最小深度  2.

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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) 
            return 1;
        if (!root->left) 
            return minDepth(root->right) + 1;
        else if (!root->right) 
            return minDepth(root->left) + 1;
        else 
            return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

// 层序遍历，遇到第一个叶子结点的那一层就是最小深度
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q{{root}};
        int res{0};
        while (!q.empty()) {
            ++res;
            int n = q.size();
            TreeNode *node = nullptr;
            for (int i = 0; i < n; ++i) {
                node = q.front();
                q.pop();
                if (!node->left && !node->right) return res;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
};

