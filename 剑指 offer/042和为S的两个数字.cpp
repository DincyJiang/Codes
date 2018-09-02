// 题目描述
// 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
// 如果有多对数字的和等于S，输出两个数的乘积最小的。

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// 思路：双指针，从两头向中间走
class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len = str.length();
        if (len == 0) return str;
        n %= len;
        rotate(str, 0, n - 1);
        rotate(str, n, len - 1);
        rotate(str, 0, len - 1);
        return str;
    }
    void rotate(string& str, int i, int j) {
        while (i < j ) {
            char c = str[i];
            str[i] = str[j];
            str[j] = c;
            ++i;
            --j;
        }
    }
};