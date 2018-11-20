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
// 示例:

// 给定二叉树，

//      1
//    /  \
//   2    3
//  / \    \
// 4   5    7
// 调用你的函数后，该二叉树变为：

//      1 -> NULL
//    /  \
//   2 -> 3 -> NULL
//  / \    \
// 4-> 5 -> 7 -> NULL

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

// 递归，由于子树有可能残缺，故需要平行扫描父节点同层的节点，找到他们的左右子节点。
class Solution1 {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode *node = root->next;
        while (node) { // node是父节点同一层节点的孩子
            if (node->left) {
                node = node->left;
                break;
            }
            if (node->right) {
                node = node->right;
                break;
            }
            node = node->next;
        }
        if (root->right) root->right->next = node;
        if (root->left) root->left->next = root->right ? root->right : node;
        connect(root->right); // 先连接右孩子，不然左边可能连接不到右孩子
        connect(root->left);
    }
};

// 常数空间的解
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *dummy = new TreeLinkNode(0);
        TreeLinkNode *cur = dummy; // 每层的首结点的前一个结点
        TreeLinkNode *pre = root; // pre表示上一层的节点
        while (pre) {
            if (pre->left) {
                cur->next = pre->left;
                cur = cur->next;
            }
            if (pre->right) {
                cur->next = pre->right;
                cur = cur->next;
            }
            pre = pre->next;
            if (!pre) { // root为空，表示这一层已经遍历完毕
                cur = dummy; // 当前指针回到虚假头节点dummy
                pre = dummy->next; // 上一层的节点回到下一层第一个
                dummy->next = nullptr; // 虚假头节点清空，也就表示下移了一层
            }
        }
    }
};
