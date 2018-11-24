// 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

// push(x) -- 将元素 x 推入栈中。
// pop() -- 删除栈顶的元素。
// top() -- 获取栈顶元素。
// getMin() -- 检索栈中的最小元素。
// 示例:

// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> 返回 -3.
// minStack.pop();
// minStack.top();      --> 返回 0.
// minStack.getMin();   --> 返回 -2.

#include <stack>

using namespace std;

// 使用双栈
class MinStack1 {
public:
    /** initialize your data structure here. */
    MinStack1() {
        
    }
    
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= s2.top())
            s2.push(x);
    }
    
    void pop() {
        if (!s2.empty() && s1.top() == s2.top())
            s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }

private:
    stack<int> s1; // 主栈
    stack<int> s2; // 最小值的栈
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

// 使用单栈和一个变量
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (x <= min) {
            s.push(min); // 每次遇到更小的元素时，先把当前最小值压栈，这样就记住了每一个最小值的稍大一点的值
            min = x;
        }
        s.push(x);
    }
    
    void pop() {
        int num = s.top();
        s.pop();
        if (num == min) {
            min = s.top();
            s.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min;
    }

private:
    int min{INT32_MAX}; // 存放最小值
    stack<int> s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */