// 题目描述
// 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

#include <iostream>
using namespace std;


// 思路：
class Solution {
public:
    int Add(int num1, int num2) {
        while (num2 != 0) {
            // 两个数异或：相当于每一位相加，而不考虑进位
            int s1 = num1 ^ num2;
            // 两个数相与，并左移一位：相当于求得进位
            int s2 = (num1 & num2) << 1;
            // 将上述两步结果相加
            num1 = s1;
            num2 = s2;
        }
        return num1;
    }
};