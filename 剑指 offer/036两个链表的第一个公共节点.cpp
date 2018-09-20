// 题目描述
// 输入两个链表，找出它们的第一个公共结点。

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

//思路：
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        while (p1 != p2) {
            p1 = p1 ? p1->next : pHead2;
            p2 = p2 ? p2->next : pHead1;
        }
        return p1;
    }
};


// 计算两条链表的长度，长的先走长度差，然后再一起走
class Solution1 {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        int n1 = 0, n2 = 0;
        while (p1) {
            ++n1;
            p1 = p1->next;
        }
        while (p2) {
            ++n2;
            p2 = p2->next;
        }
        if (n1 > n2) {
            int m = n1 - n2;
            while (m--)
                pHead1 = pHead1->next;
            while (pHead1) {
                if (pHead1 == pHead2)
                    return pHead1;
                pHead1 = pHead1->next;
                pHead2 = pHead2->next;
            }
        } else {
            int m = n2 - n1;
            while (m--)
                pHead2 = pHead2->next;
            while (pHead2) {
                if (pHead2 == pHead1)
                    return pHead2;
                pHead1 = pHead1->next;
                pHead2 = pHead2->next;
            }
        }
        return nullptr;
    }
};