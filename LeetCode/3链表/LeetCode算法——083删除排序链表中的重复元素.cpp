/*
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 不用考虑节点释放的问题，不delete也能通过
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *cur = head;
        while (cur->next != nullptr) {
            ListNode *temp = cur->next;
            if (cur->val == temp->val) {
                cur->next = temp->next;
                delete temp;
                temp = nullptr;
            } else
                cur = cur->next;
        }
        return head;
    }
};
