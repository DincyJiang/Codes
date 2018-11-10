//题目描述
//输入一个链表，从尾到头打印链表每个节点的值。

#include <vector>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(nullptr) {
	}
};

// 用栈
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> stack;
        while (head != nullptr) {
            stack.push(head->val);
            head = head->next;
        }
        int n = stack.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            res[i] = stack.top();
            stack.pop();
        }
        return res;
    }
};

// 利用vector的insert方法，insert在指定位置之前插入元素，
// 返回插入后的第一个元素的迭代器，在begin迭代器前插入可以实现push_front的效果。
// 这种方法效果很差，vector的insert方法效率很低，可能要多次重新分配空间
class Solution1 {
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

// 也可以先反转链表，然后在遍历打印