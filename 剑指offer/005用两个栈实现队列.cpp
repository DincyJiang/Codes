//题目描述
//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
//
//<分析>：
//入队：将元素进栈A
//出队：判断栈B是否为空，如果为空，则将栈A中所有元素pop，并push进栈B，栈B出栈；
//如果不为空，栈B直接出栈。

#include<stack>
using namespace std;

// 用两个栈
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

// 一个主栈，一个做辅助
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