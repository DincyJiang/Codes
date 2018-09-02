// 题目描述
// 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {

    }
};

//思路

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot1 || !pRoot2) return false;
        // 先找到根相同的，再判断
        if (pRoot1->val == pRoot2->val) {
            if (isSub(pRoot1, pRoot2)) {
                return true;
            }
        }
        return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
    // 两棵树必须完全匹配
    bool isSub(TreeNode *p1, TreeNode *p2) {
        if (!p2) return true;
        if (!p1) return false;
        if (p1->val != p2->val) return false;
        return isSub(p1->left, p2->left) && isSub(p1->right, p2->right);
    }
};






















