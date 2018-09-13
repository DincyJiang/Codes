//��Ŀ����
//������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
//
//<����>��
//��ӣ���Ԫ�ؽ�ջA
//���ӣ��ж�ջB�Ƿ�Ϊ�գ����Ϊ�գ���ջA������Ԫ��pop����push��ջB��ջB��ջ��
//�����Ϊ�գ�ջBֱ�ӳ�ջ��

#include<stack>
using namespace std;

// ������ջ
class Solution {
public:
    void push(int node) {
        stack1.push(node);
    }
    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int res = stack2.top();
        stack2.pop();
        return res;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};

// һ����ջ��һ��������
class Solution1 {
public:
	void push(int node) {
		while (!stack1.empty()) {
			stack2.push(stack1.top());
			stack1.pop();
		}
		stack1.push(node);
		while (!stack2.empty()) {
			stack1.push(stack2.top());
			stack2.pop();
		}
	}
	int pop() {
		int res = stack1.top();
		stack1.pop();
		return res;
	}
private:
	stack<int> stack1;
	stack<int> stack2;
};