/*
给定一个二叉树，它的每个结点都存放着一个整数值。

找出路径和等于给定数值的路径总数。

路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

示例：

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

返回 3。和等于 8 的路径有:

1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 在以root为根节点的二叉树中，寻找和为sum的路径，返回这样的路径个数
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        int res = findPath(root, sum);
        res += pathSum(root->left, sum);
        res += pathSum(root->right, sum);
        return res;
    }
private:
    // 找从node节点开始的和为num的路径个数
    int findPath(TreeNode* node, int num) {
        if (!node) return 0;
        int res = 0;
        // 如果当前节点的值已经等于num，路径条数加1，但是不能直接返回，因为可能往下走还有，可能包含负数
        if (node->val == num) res += 1;
        res += findPath(node->left, num - node->val);
        res += findPath(node->right, num - node->val);
        return res;
    }
};
