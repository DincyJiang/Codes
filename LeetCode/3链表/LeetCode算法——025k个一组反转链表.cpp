/*
给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。
如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。

示例 :

给定这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5

说明 :

你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 以每k个为一组来翻转链表，实际上是把原链表分成若干小段，然后分别对其进行翻转，
// 那么肯定总共需要两个函数，一个是用来分段的，一个是用来翻转的，
// 我们就以题目中给的例子来看，对于给定链表1->2->3->4->5，
// 一般在处理链表问题时，我们大多时候都会在开头再加一个dummy node，
// 因为翻转链表时头结点可能会变化，为了记录当前最新的头结点的位置而引入的dummy node，
// 那么我们加入dummy node后的链表变为-1->1->2->3->4->5，
// 如果k为3的话，我们的目标是将1,2,3翻转一下，那么我们需要一些指针，
// pre和next分别指向要翻转的链表的前后的位置，然后翻转后pre的位置更新到如下新的位置
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || k == 1) return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *pre = dummy, *cur = head;
        dummy->next = head;
        int i = 0;
        while (cur) {
            ++i;
            if (i % k == 0) {
                pre = reverseOneGroup(pre, cur->next);
                cur = pre->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
    ListNode *reverseOneGroup(ListNode *pre, ListNode *next) {
        ListNode *last = pre->next;
        ListNode *cur = last->next;
        while(cur != next) {
            last->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = last->next;
        }
        return last;
    }
};

// 我们也可以在一个函数中完成，我们首先遍历整个链表，统计出链表的长度，
// 然后如果长度大于等于k，我们开始交换节点，当k=2时，每段我们只需要交换一次，
// 当k=3时，每段需要交换2此，所以i从1开始循环，注意交换一段后更新pre指针，
// 然后num自减k，直到num<k时循环结束，
class Solution1 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1), *pre = dummy, *cur = pre;
        dummy->next = head;
        int num = 0;
        while (cur == cur->next) 
            ++num; // 链表节点个数
        while (num >= k) {
            cur = pre->next;
            for (int i = 1; i < k; ++i) {
                ListNode *t = cur->next;
                cur->next = t->next;
                t->next = pre->next;
                pre->next = t;
            }
            pre = cur;
            num -= k;
        }
        return dummy->next;
    }
};