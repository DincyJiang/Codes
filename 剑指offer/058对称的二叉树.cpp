// 题目描述
// 请实现一个函数，用来判断一颗二叉树是不是对称的。
// 注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。


#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

// 思路：层序遍历
// 用两个队列分别层序遍历左右子树 
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot) {
        if (pRoot == nullptr) return true;
        queue<TreeNode*> q1, q2;
        TreeNode *left, * right;
        q1.push(pRoot->left);
        q2.push(pRoot->right);
        while (!q1.empty() && !q2.empty()) {
            left = q1.front();
            q1.pop();
            right = q2.front();
            q2.pop();
            if (left == nullptr && right == nullptr)
                continue;
            if (left == nullptr ||
                right == nullptr ||
                left->val != right->val)
                return false;
            q1.push(left->left);
            q2.push(right->right);
            q1.push(left->right);
            q2.push(right->left);
        }
        return true;
    }
};