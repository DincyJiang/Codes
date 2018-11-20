// 给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

// 例如:
// 给定二叉树: [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回其层次遍历结果：

// [
//   [3],
//   [9,20],
//   [15,7]
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

// 非递归，用队列
class Solution1 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res{};
        if (!root) return res;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            vector<int> vec;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode *t = q.front();
                q.pop();
                vec.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.push_back(vec);
        }
        return res;
    }
};

// 递归, 核心就在于一个二维数组和一个变量level，当level递归到上一层的个数，新建一个空层，继续往里面加数字
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelOrder(root, 0, res);
        return res;
    }
    void levelOrder(TreeNode* root, int level, vector<vector<int>>& res) {
        if (!root) return;
        if (res.size() == level) res.push_back({});
        res[level].push_back(root->val);
        if (root->left) levelOrder(root->left, level + 1, res);
        if (root->right) levelOrder(root->right, level + 1, res);
    }
};
