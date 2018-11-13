// 给定一个二叉树，判断其是否是一个有效的二叉搜索树。

// 假设一个二叉搜索树具有如下特征：

// 节点的左子树只包含小于当前节点的数。
// 节点的右子树只包含大于当前节点的数。
// 所有左子树和右子树自身必须也是二叉搜索树。
// 示例 1:

// 输入:
//     2
//    / \
//   1   3
// 输出: true
// 示例 2:

// 输入:
//     5
//    / \
//   1   4
//      / \
//     3   6
// 输出: false
// 解释: 输入为: [5,1,4,null,null,3,6]。
//      根节点的值为 5 ，但是其右子节点值为 4 。

#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 左<根<右，可以用中序遍历来做，递归
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        vector<int> vals;
        inorder(root, vals);
        for (int i = 0, n = vals.size(); i < n-1; ++i) {
            if (vals[i] >= vals[i+1]) return false;
        }
        return true;
    }
    void inorder(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }
};

// 非递归中序遍历，栈
class Solution1 {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode *p = root;
        vector<int> vals;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            TreeNode* temp = s.top();
            s.pop();
            vals.push_back(temp->val);
            p = temp->right;
        }
        for (int i = 0, n = vals.size(); i < n-1; ++i) {
            if (vals[i] >= vals[i+1]) return false;
        }
        return true;
    }
};

// 非递归中序遍历，栈，只保存前一个节点的值
class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode *p = root, *pre = nullptr;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            TreeNode *temp = s.top();
            s.pop();
            if (pre && temp->val <= pre->val) return false;
            pre = temp;
            p = temp->right;
        }
        return true;
    }
};