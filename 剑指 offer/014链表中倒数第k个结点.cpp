// 题目描述
// 输入一个链表，输出该链表中倒数第k个结点。

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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        
    }
};

// 思路：不要先遍历一遍，设置哨兵
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==nullptr)
            return nullptr;
        ListNode* a=pListHead;
        ListNode* b=pListHead;
        for(int i=0;i!=k;++i)
            if(b==nullptr)   //这个判断不能省，不然可能发生指针越界
                return nullptr;
            else
                b=b->next;   //循环后b会指向第K个节点
        while(b)
        {
            b=b->next;
            a=a->next;
        }
        return a;            
    }
};

    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (!pListHead) return nullptr;
        ListNode *_1 = pListHead;
        ListNode *_2 = pListHead;
        for (int i = 0; i < k; ++i) {
            if (_1 != nullptr) {
                _1 = _1->next;
            } else {
                return nullptr;
            }
        }
        while (_1) {
            _1 = _1->next;
            _2 = _2->next;
        }
        return _2;
    }
};