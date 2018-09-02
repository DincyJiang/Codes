//题目描述
//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
//假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如输入前序遍历序列{ 1,2,4,7,3,5,6,8 }和中序遍历序列{ 4,7,2,1,5,3,8,6 }，则重建二叉树并返回。

#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		int treeSize = pre.size();
		if (treeSize != 0)
		{
			vector<int> left_pre, right_pre, left_vin, right_vin;
			//创建根节点，根节点是前序遍历的第一个数  
			TreeNode* tree = new TreeNode(pre[0]);
			//找到中序遍历根节点所在位置,存放于变量vin_root中  
			int vin_root = 0;
			for (int i = 0; i < treeSize; i++)
			{
				if (vin[i] == pre[0])
				{
					vin_root = i;
					break;
				}
			}
			//对于中序遍历，根节点左边的节点位于二叉树的左边，根节点右边的节点位于二叉树的右边,利用上述这点，对二叉树节点进行归并  
			for (int i = 0; i < vin_root; i++)
			{
				left_vin.push_back(vin[i]);
				left_pre.push_back(pre[i + 1]);//前序第一个为根节点  
			}
			for (int i = vin_root + 1; i < treeSize; i++)
			{
				right_vin.push_back(vin[i]);
				right_pre.push_back(pre[i]);
			}
			//递归，再区分子树的左、右子树，直到叶节点  
			tree->left = reConstructBinaryTree(left_pre, left_vin);
			tree->right = reConstructBinaryTree(right_pre, right_vin);
			return tree;
		}
		return nullptr;
	}
};

class Solution {
public:
    TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty() || vin.empty()) return nullptr;
		TreeNode *tree = new TreeNode(pre[0]);
		int treeSize = pre.size();
		vector<int> left_pre, left_vin, right_pre, right_vin;
		int current_root = 0;
		for (int i = 0; i < treeSize; ++i) {
			if (vin[i] == pre[0]) {
				current_root = i;
				break;
			}
		}
		for (int i = 0; i < current_root; ++i) {
			left_pre.push_back(pre[i + 1]);
			left_vin.push_back(vin[i]);
		}
		for (int i = current_root + 1; i < treeSize; ++i) {
			right_pre.push_back(pre[i]);
			right_vin.push_back(vin[i]);
		}
		tree->left = reConstructBinaryTree(left_pre, left_vin);
		tree->right = reConstructBinaryTree(right_pre, right_vin);
		return tree;
	}
}
