// 题目描述
// 给定一棵二叉搜索树，请找出其中的第k小的结点。
// 例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。


#include <iostream>

using namespace std;


// 思路：中序遍历
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if (!pRoot || k < 1) return nullptr;
        TreeNode *res = nullptr;
        count = k;
        inorder(pRoot, res);
        return res;
    }
    void inorder(TreeNode* root, TreeNode* &res) {
        if (root) {
            inorder(root->left, res);
            --count;
            if (!count) res = root;
            inorder(root->right, res);
        }
    }

private:
    int count;
};