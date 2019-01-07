// 两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。

// 给出两个整数 x 和 y，计算它们之间的汉明距离。

// 注意：
// 0 ≤ x, y < 231.

// 示例:

// 输入: x = 1, y = 4

// 输出: 2

// 解释:
// 1   (0 0 0 1)
// 4   (0 1 0 0)
//        ↑   ↑

// 上面的箭头指出了对应二进制位不同的位置。

class Solution1 {
public:
    int hammingDistance(int x, int y) {
        int res{0};
        int n = x ^ y;
        while (n) { // 计算1的个数
            ++res;
            n &= n-1;
        }
        return res;
    }
};

// 递归
// (x ^ y) % 2 相当于 检查最低位是否相同
// hammingDistance(x / 2, y / 2) 相当于 将x和y分别向右移动一位
class Solution2 {
public:
    int hammingDistance(int x, int y) {
        if ((x ^ y) == 0) // 递归终止的条件是 两个数完全相等
            return 0;
        return (x ^ y) % 2 + hammingDistance(x / 2, y / 2);
    }
};