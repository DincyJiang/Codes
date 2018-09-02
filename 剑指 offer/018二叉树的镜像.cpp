// 题目:
// 操作给定的二叉树，将其变换为源二叉树的镜像。
// 输入描述:
// 二叉树的镜像定义：源二叉树 
//     	    8
//     	   /  \
//     	  6   10
//     	 / \  / \
//     	5  7 9 11
//     	镜像二叉树
//     	    8
//     	   /  \
//     	  10   6
//     	 / \  / \
//     	11 9 7  5

// 思路：递归，交换左右子树
#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution{
public:
    void Mirror(TreeNode *pRoot){
        if(!pRoot)
            return;
        // TreeNode* tmp=pRoot->left;
        // pRoot->left=pRoot->right;
        // pRoot->right=tmp;
        swap(pRoot->left,pRoot->right);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};

