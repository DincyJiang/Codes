// 根据一棵树的前序遍历与中序遍历构造二叉树。

// 注意:
// 你可以假设树中没有重复的元素。

// 例如，给出

// 前序遍历 preorder = [3,9,20,15,7]
// 中序遍历 inorder = [9,3,15,20,7]
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
class Solution1 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& preorder, int preLeft, int preRight, vector<int>& inorder, int inLeft, int inRight) {
        if (preLeft > preRight || inLeft > inRight) return nullptr;
        int i = inLeft; //中序遍历根节点的下标
        for (; i <= inRight; ++i)
            if (preorder[preLeft] == inorder[i]) break;
        TreeNode *cur = new TreeNode(preorder[preLeft]);
        cur->left = buildTree(preorder, preLeft + 1, preLeft + i - inLeft, inorder, inLeft, i - 1); // i - inLeft是中序遍历中左子树节点的长度
        cur->right = buildTree(preorder, preLeft + i - inLeft + 1, preRight, inorder, i + 1, inRight);
        return cur;
    }
};

// 递归，好理解，但是运行时间很长，还需要额外的空间
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() && inorder.empty()) return nullptr;
        int n = preorder.size();
        vector<int> l_pre, l_in, r_pre, r_in;
        TreeNode *node = new TreeNode(preorder[0]);
        int in_root = 0; // 中序遍历根节点的下标
        for (; in_root < n; ++in_root) {
            if (inorder[in_root] == preorder[0]) break;
        }
        for (int i = 0; i < in_root; ++i) {
            l_in.push_back(inorder[i]);
            l_pre.push_back(preorder[i+1]);
        }
        for (int i = in_root + 1; i < n; ++i) {
            r_in.push_back(inorder[i]);
            r_pre.push_back(inorder[i]);
        }
        node->left = buildTree(l_pre, l_in);
        node->right = buildTree(r_pre, r_in);
        return node;
    }
};

