// 题目描述
// 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

#include <iostream>
using namespace std;

// 公式法
class Solution {
public:
    int Sum_Solution(int n) {
        bool a[n][n+1];
        return sizeof(a)>>1;
    }
};

// 短路规则
class Solution1 {
public:
    int Sum_Solution(int n) {
        int res = n;
        res && (res += Sum_Solution(n - 1)); // 利用逻辑与的短路特性实现递归终止
        return res;
    }
};