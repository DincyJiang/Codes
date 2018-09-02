// 题目描述
// 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
// 第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。


#include <iostream>
#include <queue>
#include <algorithm>
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if (!pRoot) return res;
        queue<TreeNode*> q;
        q.push(pRoot);
        bool even = false;
        while (!q.empty()) {
            vector<int> vec;
            const int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *tmp = q.front();
                q.pop();
                vec.push_back(tmp->val);
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            if (even) {
                reverse(vec.begin(), vec.end());
            }
            res.push_back(vec);
            even = !even;
        }
        return res;
    }
};