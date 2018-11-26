// 给定一个整数，写一个函数来判断它是否是 3 的幂次方。

// 示例 1:

// 输入: 27
// 输出: true
// 示例 2:

// 输入: 0
// 输出: false
// 示例 3:

// 输入: 9
// 输出: true
// 示例 4:

// 输入: 45
// 输出: false
// 进阶：
// 你能不使用循环或者递归来完成本题吗？

#include <cmath>

// 最直接的方法就是不停地除以3，看最后的迭代商是否为1，要注意考虑输入是负数和0的情况
class Solution1 {
public:
    bool isPowerOfThree(int n) {
        while (n && n % 3 == 0)
            n /= 3;
        return n == 1;
    }
};

// 有一个投机取巧的方法，由于输入是int，正数范围是0-231，在此范围中允许的最大的3的次方数为319=1162261467，那么我们只要看这个数能否被n整除即可
class Solution2 {
public:
    bool isPowerOfThree(int n) {
        return (n > 0 && 1162261467 % n == 0);
    }
};

// 利用对数的换底公式来做，高中学过的换底公式为logab = logcb / logca，那么如果n是3的倍数，则log3n一定是整数，我们利用换底公式可以写为log3n = log10n / log103
class Solution {
public:
    bool isPowerOfThree(int n) {
        return (n > 0 && int(log10(n) / log10(3)) - log10(n) / log10(3) == 0);
    }
};
