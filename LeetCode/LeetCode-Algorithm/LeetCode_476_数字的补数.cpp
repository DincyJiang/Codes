// 给定一个正整数，输出它的补数。补数是对该数的二进制表示取反。

// 注意:

// 给定的整数保证在32位带符号整数的范围内。
// 你可以假定二进制数不包含前导零位。
// 示例 1:

// 输入: 5
// 输出: 2
// 解释: 5的二进制表示为101（没有前导零位），其补数为010。所以你需要输出2。
// 示例 2:

// 输入: 1
// 输出: 0
// 解释: 1的二进制表示为1（没有前导零位），其补数为0。所以你需要输出0。

// 从高到低遍历，遇到第一个1之后开始按位异或
class Solution1 {
public:
    int findComplement(int num) {
        bool start = false;
        for (int i{31}; i >= 0; --i) {
            if (num & (1 << i)) // 遇到第一个1之后start就一直是true
                start = true;
            if (start) 
                num ^= (1 << i);
        }
        return num;
    }
};

class Solution2 {
public:
    int findComplement(int num) {
        int mask = __INT32_MAX__;
        while (mask & num) // mask是num的前导0反转的结果
            mask <<= 1;
        return ~mask & ~num;
    }
};