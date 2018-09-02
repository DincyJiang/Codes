//��Ŀ����
//����һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ��

//����vector��insert������insert��ָ��λ��֮ǰ����Ԫ�أ�
//���ز����ĵ�һ��Ԫ�صĵ���������begin������ǰ�������ʵ��push_front��Ч����
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