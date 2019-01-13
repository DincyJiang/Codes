// 给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.

// 示例 1:

// 输入:
//     3
//    / \
//   9  20
//     /  \
//    15   7
// 输出: [3, 14.5, 11]
// 解释:
// 第0层的平均值是 3,  第1层是 14.5, 第2层是 11. 因此返回 [3, 14.5, 11].
// 注意：

// 节点值的范围在32位有符号整数范围内。

#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 层序遍历
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        vector<double> res{};
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            int n = q.size();
            double sum{};
            for (int i{0}; i < n; ++i) {
                TreeNode *t = q.front();
                q.pop();
                sum += t->val;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.push_back(sum/n);
        }
        return res;
    }
};