// 题目描述
// 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。


#include <iostream>
#include <queue>
using namespace std;


// 思路：层序遍历
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
    vector<vector<int>> Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if (pRoot == nullptr)
            return res;
        queue<TreeNode*> q;
        q.push(pRoot);
        while (!q.empty()) {
            vector<int> vec;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode *node = q.front();
                q.pop();
                vec.push_back(node->val);
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            res.push_back(vec);
        }
        return res;
    }
};