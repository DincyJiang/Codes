// 题目描述
// 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
// 假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
// 序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
// （注意：这两个序列的长度是相等的）

//思路：压栈和出栈操作可能是交替进行的
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int m = pushV.size(), n = popV.size();
        if (m == 0 || n == 0 || m != n)
            return false;
        stack<int> s;
        int id = 0;
        // 遍历弹出序列
        for (int i = 0; i < m; ++i) {
            while (s.empty() || s.top() != popV[i]) {
                s.push(pushV[id++]);
                if (id > m)
                    return false;
            }
            s.pop(); // 如果栈顶元素和弹出序列遍历到的元素相同，就弹出栈
        }
        return s.empty();
    }
};

// 模拟堆栈操作：将原数列依次压栈，栈顶元素与所给出栈队列相比，如果相同则出栈，
// 如果不同则继续压栈，直到原数列中所有数字压栈完毕。
// 检测栈中是否为空，若空，说明出栈队列可由原数列进行栈操作得到。
// 否则，说明出栈队列不能由原数列进行栈操作得到
class Solution1 {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int m = pushV.size(), n = popV.size();
        if (m == 0 || n == 0 || m != n)
            return false;
        stack<int> s;
        for (int i = 0, j = 0; i < m;) {
            s.push(pushV[i++]);
            while (j < m && s.top() == popV[j]) {
                s.pop();
                ++j;
            }
        }
        return s.empty();
    }
};