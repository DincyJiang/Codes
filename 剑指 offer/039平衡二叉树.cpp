// 题目描述
// 输入一棵二叉树，求该树的深度。
// 从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

#include <iostream>
#include <vector>
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
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int dep = 0;
        return IsBalanced(pRoot, dep);
    }
    bool IsBalanced(TreeNode* root, int& dep) {
        if (!root) return true;
        int left = 0;
        int right = 0;
        if (IsBalanced(root->left, left) && IsBalanced(root->right, right)) {
            int dif = left - right;
            if (dif < -1 || dif > 1) return false;
            dep = (left > right ? left : right) + 1;
            return true;
        }
        return false;
    }
};

// 思路：最直接的做法，遍历每个结点，借助一个获取树深度的递归函数，
// 根据该结点的左右子树高度差判断是否平衡，然后递归地对左右子树进行判断。
// 这种做法有很明显的问题，在判断上层结点的时候，会多次重复遍历下层结点，增加了不必要的开销。
// 如果改为从下往上遍历，如果子树是平衡二叉树，则返回子树的高度；
// 如果发现子树不是平衡二叉树，则直接停止遍历，这样至多只对每个结点访问一次。
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return getDepth(pRoot) != -1;
	}
	int getDepth(TreeNode* root) {
		if (!root) return 0;
		int left = getDepth(root->left);
		if (left == -1) return -1;
		int right = getDepth(root->right);
		if (right == -1) return -1;
		return abs(left - right) > 1 ? -1 : 1 + max(left, right);
	}
};