//��Ŀ����
//����һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ��

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

// ��ջ
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

// ����vector��insert������insert��ָ��λ��֮ǰ����Ԫ�أ�
// ���ز����ĵ�һ��Ԫ�صĵ���������begin������ǰ�������ʵ��push_front��Ч����
// ���ַ���Ч���ܲvector��insert����Ч�ʺܵͣ�����Ҫ������·���ռ�
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

// Ҳ�����ȷ�ת����Ȼ���ڱ�����ӡ