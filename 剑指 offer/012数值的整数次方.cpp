// 题目描述
// 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

#include <algorithm>

/*剑指书中细节：
*1.当底数为0且指数<0时
*会出现对0求倒数的情况，需进行错误处理，设置一个全局变量；
*2.判断底数是否等于0
*由于base为double型，不能直接用==判断
*3.优化求幂函数
*当n为偶数，a^n =（a^n/2）*（a^n/2）
*当n为奇数，a^n = a^[(n-1)/2] * a^[(n-1)/2] * a
*时间复杂度O(logn)
*/

//思路：考虑次方数小于0，等于0，大于0
// 累乘，时间复杂度为O(n)
class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent == 0 && base != 0) return 1;
        int number = abs(exponent);
        double result = 1;
        while (number--) {
            result *= base;
        }
        return exponent > 0 ? result : 1 / result;
    }
};

// 递归，时间复杂度O(logn)
class Solution1 {
public:
    double Power(double base, int exponent) {
        if (exponent == 0) return 1; // 首先判断指数，任何书的0次方都是1，0的0次方也是1
        if (base == 0) return 0;
        if (exponent == 1) return base;
        if (exponent == -1) return 1/base;
        return Power(base, exponent/2) *
               Power(base, exponent/2) *
               Power(base, exponent%2);
    }
};