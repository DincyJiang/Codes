// 给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。

// 注意：两个节点之间的路径长度由它们之间的边数表示。

// 示例 1:

// 输入:

//               5
//              / \
//             4   5
//            / \   \
//           1   1   5
// 输出:

// 2
// 示例 2:

// 输入:

//               1
//              / \
//             4   5
//            / \   \
//           4   4   5
// 输出:

// 2
// 注意: 给定的二叉树不超过10000个结点。 树的高度不超过1000。

#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution1 {
public:
    int longestUnivaluePath(TreeNode* root) {
        int res{0};
        func(root, res);
        return res;
    }
    int func(TreeNode* node, int& res) {
        if (!node) return 0;
        int left = func(node->left, res);
        int right = func(node->right, res);
        left = (node->left && node->val == node->left->val) ? left+1 : 0;
        right = (node->right && node->val == node->right->val) ? right+1 : 0;
        res = max(res, left + right);
        return max(left, right);
    }
};

class Solution2 {
public:
    int longestUnivaluePath(TreeNode* root) {
        int res{0};
        if (root) func(root, root->val, res);
        return res;
    }
    int func(TreeNode* node, int parent, int& res) {
        if (!node) return 0;
        int left = func(node->left, node->val, res);
        int right = func(node->right, node->val, res);
        res = max(res, left + right);
        if (node->val == parent) return max(left, right) + 1;
        return 0;
    }
};