// 给定一个二叉树，判断它是否是高度平衡的二叉树。

// 本题中，一棵高度平衡二叉树定义为：

// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

// 示例 1:

// 给定二叉树 [3,9,20,null,null,15,7]

//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回 true 。

// 示例 2:

// 给定二叉树 [1,2,2,3,3,null,null,4,4]

//        1
//       / \
//      2   2
//     / \
//    3   3
//   / \
//  4   4
// 返回 false 。

#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 设定不平衡状态，技巧性高
class Solution1 {
public:
    bool isBalanced(TreeNode* root) {
        return judge(root) != nb;
    }
    int judge(TreeNode* root) { // // 返回树的高度或者不平衡状态
        if (!root) return 0;
        int left = judge(root->left);
        if (left == nb) return nb;
        int right = judge(root->right);
        if (right == nb) return nb;
        return abs(left - right) > 1 ? nb : 1 + max(left, right);
    }
private:
    int nb = -1; // 不平衡状态
};

// 求高度的函数，稳扎稳打
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return judge(root); 
    }
    bool judge(TreeNode* root) {
        if (!root) return true;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        if (abs(left - right) > 1) return false;
        else return judge(root->left) && judge(root->right);
    }
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return 1 + max(left, right);
    }
};