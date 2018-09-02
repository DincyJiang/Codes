//题目描述
//输入一个链表，从尾到头打印链表每个节点的值。

//利用vector的insert方法，insert在指定位置之前插入元素，
//返回插入后的第一个元素的迭代器，在begin迭代器前插入可以实现push_front的效果。
#include<vector>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(nullptr) {
	}
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> result;
		while (head != nullptr)
		{
			result.insert(result.begin(), head->val);
			head = head->next;
		}
		return result;
	}
};