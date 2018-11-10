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
        if (pRoot == nullptr || k < 1)
            return nullptr;
        TreeNode *res = nullptr;
        count = k;
        inorder(pRoot, res);
        return res;
    }
    void inorder(TreeNode* node, TreeNode* &res) {
        if (node != nullptr && count >= 0) {
            inorder(node->left, res);
            --count;
            if (count == 0)
                res = node;
            inorder(node->right, res);
        }
    }
private:
    int count;
};