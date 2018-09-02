// 题目描述
// 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。


#include <iostream>
#include <queue>
using namespace std;


// 思路：层序遍历
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if (!pRoot) return res;
        queue<TreeNode*> q;
        q.push(pRoot);
        while (!q.empty()) {
            vector<int> vec;
            const int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *tmp = q.front();
                q.pop();
                vec.push_back(tmp->val);
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            res.push_back(vec);
        }
        return res;
    }
};