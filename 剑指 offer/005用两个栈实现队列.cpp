//题目描述
//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
//
//<分析>：
//入队：将元素进栈A
//出队：判断栈B是否为空，如果为空，则将栈A中所有元素pop，并push进栈B，栈B出栈；
//如果不为空，栈B直接出栈。

#include<stack>
using namespace std;

class Solution
{
public:
	void push(int node) //入队的过程就是栈1压栈的过程  
	{
		stack1.push(node);
	}
	int pop()
	{
		int a;//用来储存出队的元素  
		if (stack2.empty())//如果栈2是空的，  
		{
			while (!stack1.empty())//栈1中有元素就把所有元素弹出然后压入栈2中  
			{
				a = stack1.top();
				stack2.push(a);
				stack1.pop();
			}
		}
		a = stack2.top();//取出栈2的栈顶元素放入a中  
		stack2.pop();//弹出栈2的栈顶元素  
		return a;
	}
private:
	stack<int> stack1;
	stack<int> stack2;
};
