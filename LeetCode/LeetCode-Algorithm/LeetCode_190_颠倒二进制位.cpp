// 颠倒给定的 32 位无符号整数的二进制位。

// 示例:

// 输入: 43261596
// 输出: 964176192
// 解释: 43261596 的二进制表示形式为 00000010100101000001111010011100 ，
//      返回 964176192，其二进制表示形式为 00111001011110000010100101000000 。
// 进阶:
// 如果多次调用这个函数，你将如何优化你的算法？

#include <cstdint>

// 只需要把要翻转的数从右向左一位位的取出来，如果取出来的是1，我们将结果res左移一位并且加上1；如果取出来的是0，我们将结果res左移一位，然后将n右移一位即可
class Solution1 {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res{0};
        for (int i = 0; i < 32; ++i) {
            if ((n & 1) == 1)
                res = (res << 1) + 1;
            else
                res = res << 1;
            n >>= 1;
        }
        return res;
    }
};

// 简化上面的代码，去掉if...else...结构，可以结果res左移一位，然后再判断n的最低位是否为1，是的话那么结果res加上1，然后将n右移一位即可
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res{0};
        for (int i = 0; i < 32; ++i) {
            res <<= 1;
            if ((n & 1) == 1) ++res;
            n >>= 1;
        }
        return res;
    }
};