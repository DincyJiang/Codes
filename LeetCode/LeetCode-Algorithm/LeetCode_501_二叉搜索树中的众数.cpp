// 给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

// 假定 BST 有如下定义：

// 结点左子树中所含结点的值小于等于当前结点的值
// 结点右子树中所含结点的值大于等于当前结点的值
// 左子树和右子树都是二叉搜索树
// 例如：
// 给定 BST [1,null,2,2],

//    1
//     \
//      2
//     /
//    2
// 返回[2].

// 提示：如果众数超过1个，不需考虑输出顺序

// 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）

#include <vector>
#include <unordered_map>
#include <algorithm>

using std::max;
using std::unordered_map;
using std::vector;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 中序遍历，没有使用二叉搜索树的性质
class Solution1 {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res{};
        int mx{0};
        unordered_map<int, int> hash{};
        inOrder(root, hash, mx);
        for (auto &a : hash) {
            if (a.second == mx)
                res.push_back(a.first);
        }
        return res;
    }
    void inOrder(TreeNode* root, unordered_map<int, int>& hash, int& mx) {
        if (!root) 
            return;
        inOrder(root->left, hash, mx);
        mx = max(mx, ++hash[root->val]);
        inOrder(root->right, hash, mx);
    }
};

// 不适用额外的空间，就是不能使用哈希表
// 二分搜索树，中序遍历的结果是有序的，只要比较前后两个元素是否相等的，就等于统计出现某个元素的次数
class Solution2 {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res{};
        int mx{0};
        int count{1};
        TreeNode *pre{nullptr};
        inOrder(root, pre, count, mx, res);
        return res;
    }
    void inOrder(TreeNode* node, TreeNode*& pre, int& count, int& mx, vector<int>& res) {
        if (!node) return;
        inOrder(node->left, pre, count, mx, res);
        if (pre)
            count = (node->val == pre->val) ? count+1 : 1;
        if (count >= mx) {
            if (count > mx) res.clear();
            res.push_back(node->val);
            mx = count;
        }
        pre = node;
        inOrder(node->right, pre, count, mx, res);
    }
};