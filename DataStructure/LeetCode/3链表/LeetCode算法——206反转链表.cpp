/*
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 迭代
// 从头开始改变链表指针的指向
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *new_head = nullptr;
        while (head){
            ListNode *temp = head->next;
            head->next = new_head;
            new_head = head;
            head = temp;
        }
        return new_head;
    }
};

// 递归
// 递归解法的思路是，不断的进入递归函数，直到head指向最后一个节点，p指向之前一个节点，
// 然后调换head和p的位置，再返回上一层递归函数，再交换p和head的位置，
// 每次交换后，head节点后面都是交换好的顺序，直到p为首节点，然后再交换，首节点就成了为节点，此时整个链表也完成了翻转
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next){
            return head;
        }
        ListNode *p = head;
        head = reverseList(p->next);
        p->next->next = p;
        p->next = nullptr;
        return head;
    }
};