/*
删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode *cur = dummyNode;
        while (cur && cur->next) {
            if (cur->next->val == val) {
                ListNode *delNode = cur->next;
                cur->next = delNode->next;
                delete delNode;
                delNode = nullptr;
            } else 
                cur = cur->next;
        }
        return dummyNode->next;
    }
};