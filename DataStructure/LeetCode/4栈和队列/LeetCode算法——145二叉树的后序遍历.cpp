/*
给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        preOrder(root, res);
        return res;
    }
    void preOrder(TreeNode* root, vector<int>& res) {
        if (!root) return;
        preOrder(root->left, res);
        preOrder(root->right, res);
        res.push_back(root->val);
    }
};

// 迭代算法
// 后序遍历有一种巧妙的方式：前序遍历根节点，先后将左右子节点压栈。
// 这样的遍历顺序为：中，右，左。最后reverse结果，则遍历结果变为：左，右，中。
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *temp = s.top();
            s.pop();
            res.push_back(temp->val);
            if (temp->left) s.push(temp->left);
            if (temp->right) s.push(temp->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};