// 题目描述
// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
// 要求不能创建任何新的结点，只能调整树中结点指针的指向。
#include<stack>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};

//思路一：中序遍历,递归
class Solution {  
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==nullptr)
			return nullptr;
		TreeNode *pointer=nullptr;
		convert2List(pRootOfTree,pointer);
		while(pointer->left!=nullptr)
			pointer=pointer->left;
		return pointer;
    } 
	void convert2List(TreeNode* pRoot,TreeNode* &pointer)
	{
		if(pRoot==nullptr) return;
		if(pRoot->left!=nullptr) convert2List(pRoot->left,pointer);
		pRoot->left=pointer;//最左边的节点的左孩子是空指针
		if(pointer!=nullptr) pointer->right=pRoot;
		pointer=pRoot;
		if(pointer->right!=nullptr) convert2List(pRoot->right,pointer);
	}
};

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (!pRootOfTree) return nullptr;
        TreeNode *pre = nullptr;
        help(pRootOfTree, pre);
        TreeNode *result = pRootOfTree;
        while (result->left) result = result->left;
        return result;
    }
    void help(TreeNode* cur, TreeNode* &pre) {
        if (!cur) return;
        help(cur->left, pre);
        cur->left = pre;
        if (pre) pre->right = cur;
        pre = cur;
        help(cur->right, pre);
    }
};

