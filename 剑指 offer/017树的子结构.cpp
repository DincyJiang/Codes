// 题目描述
// 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};

// 递归
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot1 == nullptr || pRoot2 == nullptr)
            return false;
        if (pRoot1->val == pRoot2->val)
            if (isSub(pRoot1, pRoot2))
                return true;
        return HasSubtree(pRoot1->left, pRoot2) || 
               HasSubtree(pRoot1->right, pRoot2);
    }
private:
    // 判断p2是不是p1的子结构，两棵树必须完全相同（左右子树）
    bool isSub(TreeNode* p1, TreeNode* p2) {
        if (p2 == nullptr) return true;
        if (p1 == nullptr) return false;
        if (p1->val != p2->val) return false;
        return isSub(p1->left, p2->left) &&
               isSub(p1->right, p2->right);
    }
};
