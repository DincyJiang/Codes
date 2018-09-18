/*
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> vec;
        if (root != nullptr)
            dfs(res, vec, root, sum);
        return res;
    }
private:
    void dfs(vector<vector<int>>& res, vector<int>& vec,
             TreeNode* root, int sum) {
        vec.push_back(root->val);
        if (root->left == nullptr &&
            root->right == nullptr &&
            root->val == sum)
            res.push_back(vec);
        if (root->left) dfs(res, vec, root->left, sum - root->val);
        if (root->right) dfs(res, vec, root->right, sum - root->val);
        vec.pop_back();
    }
};