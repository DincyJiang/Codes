// 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。

// 示例 :
// 给定二叉树

//           1
//          / \
//         2   3
//        / \     
//       4   5    
// 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

// 注意：两结点之间的路径长度是以它们之间边的数目表示。

#include <algorithm>
#include <unordered_map>

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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int res = getHeight(root->left) + getHeight(root->right);
        return max(res, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
    int getHeight(TreeNode* node) {
        if (!node) return 0;
        if (hash.count(node)) return hash[node]; // 如果该节点的深度已经计算过，就直接返回
        int h = 1 + max(getHeight(node->left), getHeight(node->right));
        return hash[node] = h;
    }
private:
    unordered_map<TreeNode*, int> hash{}; // 记录每个节点的高度
};

// 只使用一个递归函数
class Solution2 {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res{};
        maxDepth(root, res);
        return res;
    }
    int maxDepth(TreeNode* node, int& res) { // 当前节点的高度
        if (!node) return 0;
        int left = maxDepth(node->left, res);
        int right = maxDepth(node->right, res);
        res = max(res, left + right);
        return max(left, right) + 1;
    }
};

// 对上面的单个递归函数优化：哈希表记录已经遍历过的节点高度
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res{};
        maxDepth(root, res);
        return res;
    }
    int maxDepth(TreeNode* node, int& res) {
        if (!node) return 0;
        if (hash.count(node)) return hash[node];
        int left = maxDepth(node->left, res);
        int right = maxDepth(node->right, res);
        res = max(res, left + right);
        return hash[node] = (max(left, right) + 1);
    }
private:
    unordered_map<TreeNode*, int> hash{};
};