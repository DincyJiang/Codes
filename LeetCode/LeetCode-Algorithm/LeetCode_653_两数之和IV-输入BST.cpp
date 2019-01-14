// 给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。

// 案例 1:

// 输入: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7

// Target = 9

// 输出: True
 

// 案例 2:

// 输入: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7

// Target = 28

// 输出: False

#include <unordered_set>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
     TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 集合
// 前序遍历
class Solution1 {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        unordered_set<int> s{};
        return func(root, k ,s);
    }
    bool func(TreeNode* node, int k, unordered_set<int>& s) {
        if (!node) return false;
        if (s.count(k - node->val)) return true;
        s.insert(node->val);
        return func(node->left, k, s) || func(node->right, k , s);
    }
};

// 层序遍历
class Solution2 {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        unordered_set<int> s{};
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (s.count(k - t->val)) return true;
            s.insert(t->val);
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
        return false;
    }
};