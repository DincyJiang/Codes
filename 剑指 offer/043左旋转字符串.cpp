// 题目描述
// 汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
// 对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
// 例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


// 思路：分两部分旋转，再整体旋转
class Solution {
public:
    string LeftRotateString(string str, int n) {
        int size = str.size();
        if (size == 0) return ""; // 传入空字符串
        n %= size; // 防止n超过字符串长度
        rotate(str, 0, n - 1);
        rotate(str, n, size - 1);
        rotate(str, 0, size - 1);
        return str;
    }
private:
    void rotate(string& str, int i, int j) { // 全旋转
        while (i < j) {
            char c = str[i];
            str[i] = str[j];
            str[j] = c;
            ++i;
            --j;
        }
    }
};