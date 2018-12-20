// 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

// 示例:

// 给定 1->2->3->4, 你应该返回 2->1->4->3.
// 说明:

// 你的算法只能使用常数的额外空间。
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 迭代
class Solution1 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        ListNode *pre = dummy;
        dummy->next = head;
        while (pre->next && pre->next->next) {
            ListNode *temp = pre->next->next;
            pre->next->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
            pre = temp->next;
        }
        return dummy->next;
    }
};

// 递归，利用回溯的思想，递归遍历到链表末尾，然后先交换末尾两个，然后依次往前交换
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *temp = head->next;
        head->next = swapPairs(head->next->next);
        temp->next = head;
        return temp;
    }
};