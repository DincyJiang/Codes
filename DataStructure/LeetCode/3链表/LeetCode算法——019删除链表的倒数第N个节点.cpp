/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 使用双指针
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *p = dummyNode;
        ListNode *q = dummyNode;
        for (int i = 0; i < n + 1; ++i)
            q = q->next;
        while (q) {
            p = p->next;
            q = q->next;
        }
        ListNode *delNode = p->next;
        p->next = delNode->next;
        delete delNode;
        delNode = nullptr;
        return dummyNode->next;
    }
};