// 给定一个二叉树，检查它是否是镜像对称的。

// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

//     1
//    / \
//   2   2
//    \   \
//    3    3
// 说明:

// 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。

#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
判断二叉树是否是平衡树，比如有两个节点n1, n2，我们需要比较n1的左子节点的值和n2的右子节点的值是否相等，
同时还要比较n1的右子节点的值和n2的左子结点的值是否相等，以此类推比较完所有的左右两个节点。
我们可以用递归和迭代两种方法来实现，写法不同，但是算法核心都一样。
*/
class Solution1 {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if ((left && !right) || (!left && right) || (left->val != right->val)) return false;
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};

// 迭代法，使用双队列，左右两边层序遍历，方向相反
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q1{{root->left}};
        queue<TreeNode*> q2{{root->right}};
        while (!q1.empty() && !q2.empty()) {
            TreeNode *node1 = q1.front();
            q1.pop();
            TreeNode *node2 = q2.front();
            q2.pop();
            if ((!node1 && node2) || (node1 && !node2)) return false;
            if (node1 && node2) {
                if (node1->val != node2->val) return false;
                q1.push(node1->left);
                q1.push(node1->right);
                q2.push(node2->right);
                q2.push(node2->left);
            }
        }
        return true;
    }
};