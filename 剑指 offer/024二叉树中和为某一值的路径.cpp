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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(!root) return result;
        tmp.push_back(root->val);
        if(expectNumber==root->val && !root->left && !root->right)
            result.push_back(tmp);
        FindPath(root->left, expectNumber - root->val);
        FindPath(root->right, expectNumber - root->val);
        tmp.pop_back();
        return result;
    }
private:
    vector<vector<int>> result;
    vector<int> tmp;
};

