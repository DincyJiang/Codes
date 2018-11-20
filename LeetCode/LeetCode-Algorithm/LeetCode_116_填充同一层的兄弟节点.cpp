// 给定一个二叉树

// struct TreeLinkNode {
//   TreeLinkNode *left;
//   TreeLinkNode *right;
//   TreeLinkNode *next;
// }
// 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

// 初始状态下，所有 next 指针都被设置为 NULL。

// 说明:

// 你只能使用额外常数空间。
// 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
// 你可以假设它是一个完美二叉树（即所有叶子节点都在同一层，每个父节点都有两个子节点）。
// 示例:

// 给定完美二叉树，

//      1
//    /  \
//   2    3
//  / \  / \
// 4  5  6  7
// 调用你的函数后，该完美二叉树变为：

//      1 -> NULL
//    /  \
//   2 -> 3 -> NULL
//  / \  / \
// 4->5->6->7 -> NULL

#include <queue>

using namespace std;

// 每一个节点构造的时候，next指针已经是nullptr,所以每行的最后一个节点不一定要显式地令next为nullptr
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

// 递归，只使用常数额外空间，
class Solution1 {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        if (root->left) root->left->next = root->right; // 若节点的左子结点存在的话，其右子节点必定存在
        if (root->right) root->right->next = root->next ? root->next->left : nullptr; // 若父节点的next不为空，则指向其next指针指向的节点的左子结点，若为空则指向NULL
        connect(root->left);
        connect(root->right);
    }
};

// 非递归，使用队列，但是占用额外空间，不符合题意
class Solution2 {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> q{{root}};
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeLinkNode *node = q.front();
                q.pop();
                if (i < n - 1) node->next = q.front();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
    }
};

// 最好的办法，用两个指针start和cur，其中start标记每一层的起始节点，cur用来遍历该层的节点
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode *start = root;
        TreeLinkNode *cur = nullptr;
        while (start->left) { // 有下一层才会进入循环
            cur = start;
            while (cur) {
                cur->left->next = cur->right;
                if (cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            start = start->left;
        }
    }
};