// 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

// 例如：
// 给定二叉树 [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回其自底向上的层次遍历为：

// [
//   [15,7],
//   [9,20],
//   [3]
// ]

#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 自底向上的层序遍历，每一层的结果插入到头部即可
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res{};
        if (!root) return res;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            int n = q.size();
            vector<int> vec;
            TreeNode *node = nullptr;
            for (int i = 0; i < n; ++i) {
                node = q.front();
                q.pop();
                vec.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.insert(res.begin(), vec);
        }
        return res;
    }
};