// 根据一棵树的中序遍历与后序遍历构造二叉树。

// 注意:
// 你可以假设树中没有重复的元素。

// 例如，给出

// 中序遍历 inorder = [9,3,15,20,7]
// 后序遍历 postorder = [9,15,7,20,3]
// 返回如下的二叉树：

//     3
//    / \
//   9  20
//     /  \
//    15   7

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 递归
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode *buildTree(vector<int> &inorder, int inLeft, int inRight, vector<int> &postorder, int postLeft, int postRight) {
        if (inLeft > inRight || postLeft > postRight) return nullptr;
        TreeNode *cur = new TreeNode(postorder[postRight]);
        int i = inLeft;
        for (; i <= inRight; ++i)
            if (inorder[i] == postorder[postRight]) break; 
        cur->left = buildTree(inorder, inLeft, i - 1, postorder, postLeft, postLeft + i - inLeft - 1); // i- inLeft是中序遍历中左子树节点的长度
        cur->right = buildTree(inorder, i + 1, inRight, postorder, postLeft + i - inLeft, postRight - 1);
        return cur;
    }
};