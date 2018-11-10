// 题目描述
// 输入一棵二叉树，求该树的深度。
// 从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

//递归
class Solution {
public:
    int TreeDepth(TreeNode* pRoot) {
        if (!pRoot) return 0;
        return max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
    }
};

// 思路：层序遍历，迭代
class Solution1 {
public:
    int TreeDepth(TreeNode* pRoot) {
		if (pRoot == nullptr) return 0;
		int res = 0;
		queue<TreeNode*> q;
		q.push(pRoot);
		while (!q.empty()) {
			++res;
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				TreeNode *t = q.front();
				q.pop();
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}
		}
		return res;
    }
};