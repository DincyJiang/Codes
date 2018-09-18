// 题目描述
// 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
// 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

//思路：深度优先遍历，回溯法， 前序遍历

#include<vector>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};

class Solution {
public:
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        if (root == nullptr)
            return res;
        vec.push_back(root->val);
        if (expectNumber == root->val &&
            root->left == nullptr &&
            root->right == nullptr)
            res.push_back(vec);
        FindPath(root->left, expectNumber - root->val);
        FindPath(root->right, expectNumber - root->val);
        vec.pop_back();
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> vec;
};

class Solution1 {
public:
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> res;
        vector<int> vec;
        if (root != nullptr)
            dfs(root, expectNumber, res, vec);
        return res;
    }
private:
    void dfs(TreeNode* node, int num, 
             vector<vector<int>>& res, vector<int>& vec) {
        vec.push_back(node->val);
        if (node->left == nullptr &&
            node->right == nullptr && 
            num == node->val)
            res.push_back(vec);
        if (node->left)
            dfs(node->left, num - node->val, res, vec);
        if (node->right)
            dfs(node->right, num - node->val, res, vec);
        vec.pop_back();
    }
};