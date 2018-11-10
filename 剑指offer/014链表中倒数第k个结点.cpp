// 题目描述
// 输入一个链表，输出该链表中倒数第k个结点。


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) { }
};

// 双指针，一个先走k 步，然后两个指针一起走，先走的走到尾，后走的就是倒数第k个
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == nullptr) return nullptr;
        ListNode* pre = pListHead;
        ListNode* cur = pListHead;
        while (k--) {
            if (pre == nullptr)
                return nullptr;
            pre = pre->next;
        }
        while (pre != nullptr) {
            pre = pre->next;
            cur = cur->next;
        }
        return cur;
    }
};