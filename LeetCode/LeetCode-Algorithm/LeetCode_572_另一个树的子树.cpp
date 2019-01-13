// 给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

// 示例 1:
// 给定的树 s:

//      3
//     / \
//    4   5
//   / \
//  1   2
// 给定的树 t：

//    4 
//   / \
//  1   2
// 返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。

// 示例 2:
// 给定的树 s：

//      3
//     / \
//    4   5
//   / \
//  1   2
//     /
//    0
// 给定的树 t：

//    4
//   / \
//  1   2
// 返回 false。

#include <sstream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution1 {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        if (isSame(s, t)) return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    bool isSame(TreeNode* s, TreeNode* t) { // 相同的树
        if (!s && !t) return true;  // 两个空节点
        if (!s || !t) return false;
        if (s->val != t->val) return false;
        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
};

// 将两棵树序列化，各生成一个字符串
// t的字符串是s的子串
class Solution2 {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        stringstream ss1, ss2;
        serialize(s, ss1);
        serialize(t, ss2);
        return ss1.str().find(ss2.str()) != string::npos;
    }
    void serialize(TreeNode* node, stringstream& ss) {
        if (!node)
            ss << ",#";
        else {
            ss << ',' << node->val;
            serialize(node->left, ss);
            serialize(node->right, ss);
        }
    }
};