/*
给定一个二叉树，返回它的 前序 遍历。

 示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [1,2,3]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
*/

#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归方法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preOrder(root, res);
        return res;
    }
    void preOrder(TreeNode* root, vector<int>& res) {
        if (!root) return;
        res.push_back(root->val);
        preOrder(root->left, res);
        preOrder(root->right, res);
    }
};

// 迭代算法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *temp = s.top();
            s.pop();
            res.push_back(temp->val);
            if (temp->right) s.push(temp->right);
            if (temp->left) s.push(temp->left);
        }
        return res;
    }
};