// 给定两个二叉树，编写一个函数来检验它们是否相同。

// 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

// 示例 1:

// 输入:       1         1
//           / \       / \
//          2   3     2   3

//         [1,2,3],   [1,2,3]

// 输出: true
// 示例 2:

// 输入:      1          1
//           /           \
//          2             2

//         [1,2],     [1,null,2]

// 输出: false
// 示例 3:

// 输入:       1         1
//           / \       / \
//          2   1     1   2

//         [1,2,1],   [1,1,2]

// 输出: false

#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if ((p && !q) || (!p && q) || (p->val != q->val)) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

class Solution1 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> s1, s2;
        if (p) s1.push(p);
        if (q) s2.push(q);
        while (!s1.empty() && !s2.empty()) {
            TreeNode *t1 = s1.top();
            s1.pop();
            TreeNode *t2 = s2.top();
            s2.pop();
            if (t1->val != t2->val) return false;
            if (t1->left) s1.push(t1->left);
            if (t2->left) s2.push(t2->left);
            if (s1.size() != s2.size()) return false;
            if (t1->right) s1.push(t1->right);
            if (t2->right) s2.push(t2->right);
            if (s1.size() != s2.size()) return false;
        }
        return s1.size() == s2.size();
    }
};