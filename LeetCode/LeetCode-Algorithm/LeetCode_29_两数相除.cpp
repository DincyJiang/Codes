// 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

// 返回被除数 dividend 除以除数 divisor 得到的商。

// 示例 1:

// 输入: dividend = 10, divisor = 3
// 输出: 3
// 示例 2:

// 输入: dividend = 7, divisor = -3
// 输出: -2
// 说明:

// 被除数和除数均为 32 位有符号整数。
// 除数不为 0。
// 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。

#include <algorithm>

using namespace std;

// 位操作，如果被除数大于或等于除数，则进行如下循环：
// 定义变量t等于除数，定义计数p，当t的两倍小于等于被除数时，进行如下循环，t扩大一倍，p扩大一倍，然后更新res和m
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long m = abs(static_cast<long long>(dividend));
        long long n = abs(static_cast<long long>(divisor));
        long long res{0};
        if (m < n) return 0;
        while (m >= n) {
            long long t = n;
            long long p = 1;
            while (m > (t << 1)) {
                t <<= 1;
                p <<= 1;
            }
            res += p;
            m -= t;
        }
        if ((dividend < 0) ^ (divisor < 0)) res = -res;
        return res > INT32_MAX ? INT32_MAX : res;
    }
};