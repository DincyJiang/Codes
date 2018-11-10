// 题目描述
// 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
// 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。


#include <iostream>

using namespace std;

// 思路：
struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (pNode == nullptr)
            return nullptr;
        // 如果存在右子树,右子树的最左
        if (pNode->right != nullptr) {
            pNode = pNode->right;
            while (pNode->left)
                pNode = pNode->left;
            return pNode;
        }
        // 如果不存在右子树
        while (pNode->next != nullptr) {
            TreeLinkNode *node = pNode->next;
            // 如果要找的节点是其父节点的左孩子
            if (node->left == pNode)
                return node;
            // 如果要找的节点是其父节点的右孩子
            pNode = pNode->next;
        }
        return nullptr;
    }
};