// 给定一个二叉树，找出其最大深度。

// 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

// 说明: 叶子节点是指没有子节点的节点。

// 示例：
// 给定二叉树 [3,9,20,null,null,15,7]，

//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回它的最大深度 3 。

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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// 层序遍历，层数
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q{{root}};
        int res{0};
        while (!q.empty()) {
            int n = q.size();
            TreeNode *node = nullptr;
            for (int i = 0; i < n; ++i) {
                node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ++res;
        }
        return res;
    }
};