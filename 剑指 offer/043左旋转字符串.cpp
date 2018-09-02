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
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if (data.size() < 2) return;
        int size = data.size();
        int temp = data[0];
        for (int i = 1; i < size; ++i) {
            temp = temp ^ data[i];
        }
        if (temp == 0) return;
        int index = 0;
        while ((temp & 1) == 0) {
            temp = temp >> 1;
            ++index;
        }
        *num1 = *num2 = 0;
        for (int i = 0; i < size; ++i) {
            if (IsBit(data[i], index)) {
                *num1 ^= data[i];
            } else {
                *num2 ^= data[i];
            }
        }
	}
    bool IsBit(int num,int index) {
        num = num >> index;
        return num & 1;
    }
};