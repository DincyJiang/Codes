/*
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 类似归并排序
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(-1);
        ListNode* result_cur = result;
        while (l1 && l2){
            if (l1->val <= l2->val){
                result_cur->next = l1;
                l1 = l1->next;
            } else {
                result_cur->next = l2;
                l2 = l2->next;
            }
            result_cur = result_cur->next;
        }
        result_cur->next = l1 ? l1 : l2;
        return result->next;
    }
};

