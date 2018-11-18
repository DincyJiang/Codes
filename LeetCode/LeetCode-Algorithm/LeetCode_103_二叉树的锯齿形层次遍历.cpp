// 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

// 例如：
// 给定二叉树 [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回锯齿形层次遍历如下：

// [
//   [3],
//   [20,9],
//   [15,7]
// ]

#include <queue>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 层序遍历，偶数行反转输出
class Solution1 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res{};
        if (!root) return res;
        queue<TreeNode*> q{{root}};
        int flag = true; // true是奇数行
        while (!q.empty()) {
            int n = q.size();
            vector<int> vec(n);
            TreeNode *node = nullptr;
            for (int i = 0; i < n; ++i) {
                node = q.front();
                q.pop();
                vec[i] = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (!flag) {
                reverse(vec.begin(), vec.end());
            }
            flag = !flag;
            res.push_back(vec);
        }
        return res;
    }
};

// 双栈，进栈的顺序不相同，一个栈是先进左子结点然后右子节点，另一个栈是先进右子节点然后左子结点，这样出栈的顺序就是我们想要的之字形了
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res{};
        if (!root) return res;
        stack<TreeNode*> s1{{root}};
        stack<TreeNode*> s2;
        vector<int> vec{};
        while (!s1.empty() || !s2.empty()) {
            TreeNode *node = nullptr;
            while (!s1.empty()) {
                node = s1.top();
                s1.pop();
                vec.push_back(node->val);
                if (node->left) s2.push(node->left);
                if (node->right) s2.push(node->right);
            }
            if (!vec.empty()) {
                res.push_back(vec);
                vec.clear();
            }
            while (!s2.empty()) {
                node = s2.top();
                s2.pop();
                vec.push_back(node->val);
                if (node->right) s1.push(node->right);
                if (node->left) s1.push(node->left);
            }
            if (!vec.empty()) {
                res.push_back(vec);
                vec.clear();
            }
        }
        return res;
    }
};