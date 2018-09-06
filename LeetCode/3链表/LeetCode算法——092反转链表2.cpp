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

// 分为三段： 前一段，反转段，后一段
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head) return nullptr;
        ListNode *tou = nullptr; // 前一段的最后一个节点
        ListNode *cur = head;
        for (int i = 0; i < m-1; ++i) {
            tou = cur;
            cur = cur->next; // cur表示反转段第一个节点
        }
        ListNode *end = cur; // 反转段翻转之后的最后一个节点
        ListNode *pre = cur;
        cur = cur->next;
        // 把指针一个一个反转
        for (int i = m+1; i <= n; ++i) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        end->next = cur; // 循环之后的cur指向后一段第一个节点，反转段反转之后的最后一个节点应该指向它
        if (tou)
            tou->next = pre;
        else
            head = pre;
        return head;
    }
};

class Solution2 {
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

class Solution1s {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode *cur = dummyNode;
        ListNode *pre = nullptr;  
        ListNode *front = nullptr; // 倒转部分的倒转之后的头部 
        ListNode *last = nullptr;  // 倒转部分的倒转之后的尾部
        for (int i = 1; i <= m-1; ++i)
            cur = cur->next;
        pre = cur;
        last = cur->next;
        for (int i = m; i <= n; ++i) {
            cur = pre->next;
            pre->next = cur->next;
            cur->next = front;
            front = cur;
        }
        cur = pre->next;
        pre->next = front;
        last->next = cur;
        return dummyNode->next;
    }
};
