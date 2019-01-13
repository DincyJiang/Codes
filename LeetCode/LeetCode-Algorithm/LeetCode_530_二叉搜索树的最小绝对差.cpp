// 给定一个所有节点为非负值的二叉搜索树，求树中任意两节点的差的绝对值的最小值。

// 示例 :

// 输入:

//    1
//     \
//      3
//     /
//    2

// 输出:
// 1

// 解释:
// 最小绝对差为1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
// 注意: 树中至少有2个节点。

#include <algorithm>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 二叉搜索树，中序遍历的结果是从小到大的，最小绝对差就在相邻数字之间
class Solution1 {
public:
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        int pre{-1};
        inOrder(root, pre, res);
        return res;
    }
    void inOrder(TreeNode* root, int& pre, int& res) {
        if (!root) return;
        inOrder(root->left, pre, res);
        if (pre != -1)
            res = min(res, root->val - pre);
        pre = root->val;
        inOrder(root->right, pre, res);
    }
};

// 先序遍历
class Solution2 {
public:
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        func(root, INT_MAX, INT_MAX, res);
        return res;
    }
    void func(TreeNode* root, int low, int high, int& res) {
        if (!root) return;
        if (low != INT_MAX)
            res = min(res, root->val - low);
        if (high != INT_MAX)
            res = min(res, high - root->val);
        func(root->left, low, root->val, res);
        func(root->right, root->val, high, res);
    }
};

// 中序遍历的迭代写法
class Solution3 {
public:
    int getMinimumDifference(TreeNode* root) {
        int res{INT_MAX};
        int pre{-1};
        stack<TreeNode*> st{};
        TreeNode *p = root;
        while (p || !st.empty()) {
            while (p) {
                st.push(p);
                p = p->left;
            }
            p = st.top();
            st.pop();
            if (pre != -1)
                res = min(res, p->val - pre);
            pre = p->val;
            p = p->right;
        }
        return res;
    }
};