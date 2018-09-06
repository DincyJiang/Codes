/*
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 首先找到第一个大于或等于给定值的节点，用题目中给的例子来说就是先找到4，
// 然后再找小于3的值，每找到一个就将其取出置于4之前即可

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;
        while (pre->next && pre->next->val < x)
            pre = pre->next; // 找到第一个大于x的节点之前的一个节点
        cur = pre;
        while (cur->next) {
            if (cur->next->val < x) {
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
                pre = pre->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};

// 此题还有一种解法，就是将所有小于给定值的节点取出组成一个新的链表，
// 此时原链表中剩余的节点的值都大于或等于给定值，只要将原链表直接接在新链表后即可
class Solution1 {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return nullptr;
        ListNode *dummy = new ListNode(-1);    // 原链表的虚假头节点
        ListNode *newDummy = new ListNode(-1); // 小值链表的虚假头节点
        dummy->next = head;
        ListNode *cur = dummy, *p = newDummy;
        while (cur->next) {
            if (cur->next->val < x) {
                p->next = cur->next;
                p = p->next;
                cur->next = cur->next->next;
                p->next = nullptr;
            } else
                cur = cur->next;
        }
        p->next = dummy->next;
        return newDummy->next;
    }
};