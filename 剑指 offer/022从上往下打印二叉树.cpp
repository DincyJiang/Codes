// 题目描述
// 从上往下打印出二叉树的每个节点，同层节点从左至右打印

#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};

//思路：层序遍历，使用队列s
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> q;
        TreeNode* a;
        if(root==nullptr)
            return result;
        q.push(root);
        while(!q.empty())
        {
            a=q.front();
            result.push_back(a->val);
            if(a->left!=nullptr)
                q.push(a->left);
            if(a->right!=nullptr)
                q.push(a->right);
            q.pop();
        }
        return result;
    }
};

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *t;
        while (!q.empty()) {
            t = q.front();
            q.pop();
            result.push_back(t->val);
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
        return result;
    }
};