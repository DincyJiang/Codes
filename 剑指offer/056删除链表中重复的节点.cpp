// 题目描述
// 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
// 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


// 思路：
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if (pHead == nullptr || pHead->next == nullptr)
            return pHead;
        ListNode *dummy = new ListNode(-1);
        dummy->next = pHead;
        ListNode *pre = dummy;    // 重复节点的前一个节点
        ListNode *cur = pHead;    // 当前节点，重复节点的第一个节点
        ListNode *next = nullptr; // 重复节点的下一个节点
        while (cur != nullptr && cur->next != nullptr) {
            next = cur->next;
            if (cur->val == next->val) {
                while (next != nullptr && next->val == cur->val)
                    next = next->next;
                pre->next = next;
                cur = next;
            } else {
                pre = cur;
                cur = next;
            }
        }
        return dummy->next;
    }
};