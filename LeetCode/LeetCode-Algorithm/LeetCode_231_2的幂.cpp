// 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

// 示例 1:

// 输入: 1
// 输出: true
// 解释: 20 = 1
// 示例 2:

// 输入: 16
// 输出: true
// 解释: 24 = 16
// 示例 3:

// 输入: 218
// 输出: false

// 除法，一直除以2直到1
class Solution1 {
public:
    bool isPowerOfTwo(int n) {
        while (n) {
            if (n == 1) return true;
            if (n % 2 != 0) return false;
            n /= 2;
        }
        return false;;
    }
};

// 每次判断最低位是否为1，然后向右移位，最后统计1的个数即可判断是否是2的次方数
class Solution2 {
public:
    bool isPowerOfTwo(int n) {
        int num_of_1{0};
        while (n) {
            num_of_1 += (n & 1);
            n >>= 1;
        }
        return num_of_1 == 1;
    }
};

// 最高位为1，其它都为0，那么如果减1的话，则最高位会降一位，其余为0的位现在都为变为1，那么我们把两数相与，就会得到0
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && (!(n & (n - 1)));
    }
};