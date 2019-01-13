// 给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。

// 例如：

// 输入: 二叉搜索树:
//               5
//             /   \
//            2     13

// 输出: 转换为累加树:
//              18
//             /   \
//           20     13

#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 从右向左的中序遍历，右中左
class Solution1 {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum{};
        func(root, sum);
        return root;
    }
    void func(TreeNode*& node, int& sum) {
        if (!node) return;
        func(node->right, sum);
        node->val += sum;
        sum = node->val;
        func(node->left, sum);
    }
};

// 自身递归
class Solution2 {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return nullptr;
        convertBST(root->right);
        root->val += sum;
        sum = root->val;
        convertBST(root->left);
        return root;
    }
private:
    int sum{};
};

// 中序遍历的迭代写法
class Solution3 {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return nullptr;
        int sum{};
        stack<TreeNode*> st{};
        TreeNode *p = root;
        while (p || !st.empty()) {
            while (p) {
                st.push(p);
                p = p->right;
            }
            p = st.top();
            st.pop();
            p->val += sum;
            sum = p->val;
            p = p->left;
        }
        return root;
    }
};