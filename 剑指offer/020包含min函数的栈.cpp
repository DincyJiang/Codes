// 题目描述
// 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。

//思路：两个栈，借助一个辅助栈min，将每次压入的元素与min栈顶的元素比较，比栈顶元素小就压栈

#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    void push(int value) {
        if (m.empty() || value < m.top())
            m.push(value);
        s.push(value);
    }
    void pop() {
        if (s.top() == m.top())
            m.pop();
        s.pop();
    }
    int top() {
        return s.top();
    }
    int min() {
        return m.top();
    }
private:
    stack<int> s; // 存放所有值的栈
    stack<int> m; // 存放最小值的栈，里面存放的是依次放入的最小值
};