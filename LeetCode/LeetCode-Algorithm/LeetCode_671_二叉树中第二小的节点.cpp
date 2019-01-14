// 给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或 0。如果一个节点有两个子节点的话，那么这个节点的值不大于它的子节点的值。 

// 给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。

// 示例 1:

// 输入: 
//     2
//    / \
//   2   5
//      / \
//     5   7

// 输出: 5
// 说明: 最小的值是 2 ，第二小的值是 5 。
// 示例 2:

// 输入: 
//     2
//    / \
//   2   2

// 输出: -1
// 说明: 最小的值是 2, 但是不存在第二小的值。

#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 根节点一定是最小值，暴力搜索第二小的数
class Solution1 {
public:
    int findSecondMinimumValue(TreeNode* root) {
        int first = root->val;
        int second = __INT_MAX__;
        func(root, first, second);
        return (second == first || second == __INT_MAX__) ? -1 : second;
    }
    void func(TreeNode* node, int& first, int& second) {
        if (!node) return;
        if (node->val != first && node->val < second) {
            second = node->val;
        }
        func(node->left, first, second);
        func(node->right, first, second);
    }
};

class Solution2 {
public:
    int findSecondMinimumValue(TreeNode* root) {
        return func(root, root->val);
    }
    int func(TreeNode* node, int first) {
        if (!node) return -1;
        if (node->val != first) return node->val;
        int left = func(node->left, first);
        int right = func(node->right, first);
        return (left == -1 || right == -1) ? max(left, right) : min(left, right);
    }
};

class Solution3 {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root->left) return -1;
        int left = (root->left->val == root->val) ? findSecondMinimumValue(root->left) : root->left->val;
        int right = (root->right->val == root->val) ? findSecondMinimumValue(root->right) : root->right->val;
        return (left == -1 || right == -1) ? max(left, right) : min(left, right);
    }
};

// 迭代
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        int first = root->val;
        int second = __INT_MAX__;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (t->val != first && t->val < second) {
                second = t->val;
            }
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
        return (second == first || second == __INT_MAX__) ? -1 : second;
    }
};