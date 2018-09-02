// 题目描述
// 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        
    }
};

//思路：合并不难，关键是要考虑代码鲁棒性问题，指针不能越界
//使用递归
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==nullptr)
            return pHead2;
        else if(pHead2==nullptr)
            return pHead1;
        ListNode* newHead=nullptr;
        if(pHead1->val<=pHead2->val)
        {
            newHead=pHead1;
            pHead1->next=Merge(pHead1->next,pHead2);
        }else{
            newHead=pHead2;
            pHead2->next=Merge(pHead1,pHead2->next);
        }
        return newHead;
    }
};


