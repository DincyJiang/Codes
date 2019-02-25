// 给定一个正整数，检查他是否为交替位二进制数：换句话说，就是他的二进制数相邻的两个位数永不相等。

// 示例 1:

// 输入: 5
// 输出: True
// 解释:
// 5的二进制数是: 101
// 示例 2:

// 输入: 7
// 输出: False
// 解释:
// 7的二进制数是: 111
// 示例 3:

// 输入: 11
// 输出: False
// 解释:
// 11的二进制数是: 1011
//  示例 4:

// 输入: 10
// 输出: True
// 解释:
// 10的二进制数是: 1010

// 从最低位开始，一位一位遍历
class Solution1 {
public:
    bool hasAlternatingBits(int n) {
        int bit{-1}; // 前一位
        while (n > 0) {
            if (n & 1 == 1) { // 最后一位是1
                if (bit == 1) return false;
                bit = 1;
            } else { // 最后一位是0
                if (bit == 0) return false;
                bit = 0;
            }
            n >>= 1;
        }
        return true;
    }
};

class Solution2 {
public:
    bool hasAlternatingBits(int n) {
        int d = n & 1; 
        while ((n & 1) == d) {
            d ^= 1; // 异或1来将d在0和1之间交换
            n >>= 1;
        }
        return n == 0;
    }
};

// 错位相加，组成全1的二进制数
// 检测全1二进制数的小技巧：与上一个加1后的数，结果应该是0
class Solution3 {
public:
    bool hasAlternatingBits(int n) {
        return ((n + (n >> 1) + 1) & (n + (n >> 1))) == 0;
    }
};

// 先将n右移两位，再和原来的n异或，得到的新n就是除了最高位，其余都是0的数
// 再与自身减1的数相与，结果应该是0
class Solution4 {
public:
    bool hasAlternatingBits(int n) {
        return ((n ^= n/4) & (n - 1)) == 0;
    }
};