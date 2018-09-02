/*

给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.
说明:

你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *pre = dummyNode;
        ListNode *node1 = head;
        while (node1 && node1->next) {
            ListNode *node2 = node1->next;
            ListNode *next = node2->next;
            node2->next = node1;
            node1->next = next;
            pre->next = node2;
            pre = node1;
            node1 = next;
        }
        return dummyNode->next;
    }
};