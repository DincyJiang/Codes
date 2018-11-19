// 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

// 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

// 示例:

// 给定的有序链表： [-10, -3, 0, 5, 9],

// 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

//       0
//      / \
//    -3   9
//    /   /
//  -10  5

#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 先把链表转换成数组，在用二分法
class Solution1 {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums{};
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode *cur = new TreeNode(nums[mid]);
        cur->left = sortedArrayToBST(nums, left, mid - 1);
        cur->right = sortedArrayToBST(nums, mid + 1, right);
        return cur;
    }
};

// 使用快慢指针寻找中间节点，分成两条链表。二分法
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *last = head; // 前一半节点的最后一个节点
        while (fast && fast->next) {
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next; // 后一半节点的第一个节点
        last->next = nullptr;
        TreeNode *cur = new TreeNode(slow->val); // slow现在是中间节点
        if (head != slow) cur->left = sortedListToBST(head);
        cur->right = sortedListToBST(fast);
        return cur;
    }
};
