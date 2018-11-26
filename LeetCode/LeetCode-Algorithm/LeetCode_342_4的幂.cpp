// 给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。

// 示例 1:

// 输入: 16
// 输出: true
// 示例 2:

// 输入: 5
// 输出: false
// 进阶：
// 你能不使用循环或者递归来完成本题吗？

#include <cmath>

// 最直接的方法就是不停的除以4，看最终结果是否为1
class Solution1 {
public:
    bool isPowerOfFour(int num) {
        while (num && num % 4 == 0)
            num /= 4;
        return num == 1;
    }
};

// 使用换底公式来做
class Solution2 {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && int(log10(num) / log10(4)) - log10(num) / log10(4) == 0;
    }
};

// num & (num - 1)可以用来判断一个数是否为2的次方数，就是二进制表示下，只有最高位是1，那么由于是2的次方数，不一定是4的次方数
// 4的次方数的最高位的1都是计数位，我们只需与上一个数(0x55555555) <==> 1010101010101010101010101010101，如果得到的数还是其本身，则可以肯定其为4的次方数
class Solution3 {
public:
    bool isPowerOfFour(int num) {
        return num > 0 &&
               !(num & (num - 1)) &&
               (num & 0x55555555) == num;
    }
};

// 在确定其是2的次方数了之后，发现只要是4的次方数，减1之后可以被3整除
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && !(num & (num - 1)) && (num - 1) % 3 == 0;
    }
};