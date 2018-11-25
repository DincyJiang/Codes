// 给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。

// 示例:

// 输入: 38
// 输出: 2 
// 解释: 各位相加的过程为：3 + 8 = 11, 1 + 1 = 2。 由于 2 是一位数，所以返回 2。
// 进阶:
// 你可以不使用循环或者递归，且在 O(1) 时间复杂度内解决这个问题吗？

// 循环
class Solution1 {
public:
    int addDigits(int num) {
        while (num / 10 > 0) {
            int sum{0};
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};

// 每9个一循环，所有大于9的数的树根都是对9取余，那么对于等于9的数对9取余就是0了，为了得到其本身，而且同样也要对大于9的数适用，我们就用(n-1)%9+1这个表达式来包括所有的情况
class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};