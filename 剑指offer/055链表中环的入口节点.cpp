// 题目描述
// 给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

//先说个定理：两个指针一个fast、一个slow同时从一个链表的头部出发
//fast一次走2步，slow一次走一步，如果该链表有环，两个指针必然在环内相遇
//此时只需要把其中的一个指针重新指向链表头部，另一个不变（还在环内），
//这次两个指针一次走一步，相遇的地方就是入口节点。

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if (pHead == nullptr) return nullptr;
        ListNode *fast = pHead;
        ListNode *slow = pHead->next;
        while (fast != nullptr &&
               slow != nullptr &&
               fast != slow) {
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr)
                fast = fast->next;
        }
        int count = 1; // 统计环结点数
        ListNode *temp = fast->next;
        if (fast == slow && fast != nullptr)
            while (temp != fast) {
                temp = temp->next;
                ++count;
            }
        else
            return nullptr;
        // 再设两指针，一先一后
        ListNode *p1 = pHead;
        ListNode *p2 = pHead;
        for (int i = 0; i < count; ++i)
            p1 = p1->next;
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};