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
        ListNode *p1 = pHead1, *p2 = pHead2;
        while (p1 != p2) {
            p1 = p1 == nullptr ? pHead2 : p1->next;
            p2 = p2 == nullptr ? pHead1 : p2->next;
        }
        return p1;
    }
};
