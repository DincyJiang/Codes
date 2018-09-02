/*
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int change_len = n - m + 1;
        ListNode *pre_head = nullptr;
        ListNode *result = head;
        while (head && --m){
            pre_head = head;   // 记录head的前驱
            head = head->next; // 一直找到逆置段的首节点
        }
        ListNode *modify_list_tail = head;
        ListNode *new_head = nullptr;
        while (head && --change_len){
            ListNode *next = head->next;
            head->next = new_head;
            new_head = head;
            head = next;
        }
        modify_list_tail->next = head;
        if (pre_head){
            pre_head->next = new_head;
        } else {
            result = new_head;
        }
        return result;
    }
};