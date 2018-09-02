// 题目描述
// 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。


//思路：考虑次方数小于0，等于0，大于0
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

class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent == 0) return 1;
        if (base == 0) return 0;
        if (exponent == 1) return base;
        if (exponent == -1) return 1 / base;
        return Power(base, exponent / 2) * Power(base, exponent / 2) * Power(base, exponent % 2);
    }
};