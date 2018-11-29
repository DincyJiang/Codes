// 在无限的整数序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...中找到第 n 个数字。

// 注意:
// n 是正数且在32为整形范围内 ( n < 231)。

// 示例 1:

// 输入:
// 3

// 输出:
// 3
// 示例 2:

// 输入:
// 11

// 输出:
// 0

// 说明:
// 第11个数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是0，它是10的一部分。

#include <string>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long long len{1}; // 当前循环区间数字的位数
        long long cnt{9}; // 当前当前循环区间数字总个数
        long long start{1}; // 当前循环区间的第一个数字
        while (n > len * cnt) {
            n -= len * cnt;
            ++len;
            cnt *= 10;
            start *= 10;
        }
        start += (n - 1) / len; // 当n落到某一个确定的区间里了，那么(n-1)/len就是目标数字在该区间里的坐标，加上start就是得到了目标数字
        string t = to_string(start);
        return t[(n - 1) % len] - '0';
    }
};