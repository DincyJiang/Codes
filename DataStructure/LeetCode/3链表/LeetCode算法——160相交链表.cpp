/*
编写一个程序，找到两个单链表相交的起始节点。

例如，下面的两个链表：

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
在节点 c1 开始相交。
注意：

如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 方法1 ： 先求出两条链表的长度差，把长的链表头节点向后移动长度差个节点，
//         这时两条链表头节点后面的节点书就相同了，一起向后遍历，
//         有相同的节点就返回， 如果到最后都没有相同的节点就返回nullptr
class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB){
            return nullptr;
        }
        int lenA = getLength(headA), lenB = getLength(headB);
        if (lenA < lenB){
            for (int i = 0; i < lenB - lenA; ++i){
                headB = headB->next;
            }
        } else {
            for (int i = 0; i < lenA - lenB; ++i){
                headA = headA->next;
            }
        }
        while (headA && headB && headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return (headA && headB) ? headA : nullptr;
    }
    int getLength(ListNode* head){
        int count = 0;
        while (head){
            ++count;
            head = head->next;
        }
        return count;
    }
};

// 虽然题目中强调了链表中不存在环，但是我们可以用环的思想来做，我们让两条链表分别从各自的开头开始往后遍历，
// 当其中一条遍历到末尾时，我们跳到另一个条链表的开头继续遍历。
// 两个指针最终会相等，而且只有两种情况，一种情况是在交点处相遇，另一种情况是在各自的末尾的空节点处相等。
// 为什么一定会相等呢，因为两个指针走过的路程相同，是两个链表的长度之和，所以一定会相等。

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB){
            return nullptr;
        }
        ListNode *a = headA, *b = headB;
        while (a != b){
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};