// 题目描述
// 输入一个链表，反转链表后，输出链表的所有元素。

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
    ListNode* ReverseList(ListNode* pHead) {

    }
};

// 思路：使用辅助节点把链表掉头
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (!pHead) return nullptr;
        ListNode *result = nullptr;
        ListNode *cur = pHead;
        ListNode *pre = nullptr;
        while (cur) {
            ListNode *temp = cur->next;
            if (!temp) result = cur; // 尾节点时才把值赋给result
            cur->next = pre; // 指针反转
            pre = cur;
            cur = temp;
        }
        return result;
    }
};

// 思路二：递归
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        //如果链表为空或者链表中只有一个元素
        if(pHead==NULL||pHead->next==NULL) return pHead;         
        //先反转后面的链表，走到链表的末端结点
        ListNode* pReverseNode=ReverseList(pHead->next);      
        //再将当前节点设置为后面节点的后续节点
        pHead->next->next=pHead;
        pHead->next=NULL;
        return pReverseNode;        
    }
};