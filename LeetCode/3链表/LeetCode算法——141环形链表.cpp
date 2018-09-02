/*
给定一个链表，判断链表中是否有环。

进阶：
你能否不使用额外空间解决此题？
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 利用快慢指针
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head){
            return false;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow){
                return true;
            }
        }
        return false;
    }
};