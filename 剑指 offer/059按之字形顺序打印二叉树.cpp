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
    vector<vector<int>> Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if (pRoot == nullptr) return res;
        queue<TreeNode*> q;
        q.push(pRoot);
        bool even = false; // 判断是否是偶数层，偶数层反过来打印
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
            if (even) // 如果是偶数层，就反转
                reverse(vec.begin(), vec.end());
            res.push_back(vec);
            even = !even;
        }
        return res;
    }
};