//��Ŀ����
//������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
//
//<����>��
//��ӣ���Ԫ�ؽ�ջA
//���ӣ��ж�ջB�Ƿ�Ϊ�գ����Ϊ�գ���ջA������Ԫ��pop����push��ջB��ջB��ջ��
//�����Ϊ�գ�ջBֱ�ӳ�ջ��

#include<stack>
using namespace std;

class Solution
{
public:
	void push(int node) //��ӵĹ��̾���ջ1ѹջ�Ĺ���  
	{
		stack1.push(node);
	}
	int pop()
	{
		int a;//����������ӵ�Ԫ��  
		if (stack2.empty())//���ջ2�ǿյģ�  
		{
			while (!stack1.empty())//ջ1����Ԫ�ؾͰ�����Ԫ�ص���Ȼ��ѹ��ջ2��  
			{
				a = stack1.top();
				stack2.push(a);
				stack1.pop();
			}
		}
		a = stack2.top();//ȡ��ջ2��ջ��Ԫ�ط���a��  
		stack2.pop();//����ջ2��ջ��Ԫ��  
		return a;
	}
private:
	stack<int> stack1;
	stack<int> stack2;
};
