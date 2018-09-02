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
class Solution {
public:
	int TreeDepth(TreeNode* pRoot) {
		if (!pRoot) return 0;
		queue<TreeNode*> que;
		que.push(pRoot);
		int depth=0;
		while (!que.empty()) {
			int size=que.size();
			depth++;
			for (int i=0;i<size;i++) { //一次处理一层的数据
			TreeNode *node=que.front();
			que.pop();
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
			}
		}
		return depth;
	}
};