// 题目描述
// 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。

//思路：两个栈，借助一个辅助栈min，将每次压入的元素与min栈顶的元素比较，比栈顶元素小就压栈

#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;



class Solution {
public:
    void push(int value) {
        a.push(value);
        if(smin.empty())
            smin.push(value);
        if(smin.top()>value)
            smin.push(value);
    }
    void pop() {
        if(a.top()==smin.top())
            smin.pop();
        a.pop();
    }
    int top() {
        return a.top();
    }
    int min() {
        return smin.top();
    }
private:
    stack<int> a;
    stack<int> smin;
};

class Solution {
public:
    void push(int value) {
        s1.push(value);
        if (s2.empty() || s2.top() > value) {
            s2.push(value);
        }
    }
    void pop() {
        if (s1.top() == s2.top()) {
            s2.pop();
        }
        s1.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s2.top();
    }
private:
    stack<int> s1;
    stack<int> s2;
};