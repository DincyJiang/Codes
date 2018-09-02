//题目描述
//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

//思路一：经过计算F(n)=2*F(n-1),F(1)=1
//使用递归的结果是占用内存太大
class Solution {
public:
    int jumpFloorII(int number) {
        if(number==1)
            return 1;
        else if(number>1)
        {
            return 2*jumpFloorII(number--);
        }
        return 0;
    }
};

//思路二：使用循环
class Solution {
public:
    int jumpFloorII(int number) {
        if(number==0)
            return number;
        int total=1;
        for(int i=1;i<number;i++)
            total*=2;
        return total;
    }
};

//变态解法：2^(number-1)，移位操作，左移一位就相当于乘以2，将1左移number-1位
class Solution {
public:
    int jumpFloorII(int number) {
        return  1<<--number;
    }
};

class Solution {
public:
    int jumpFloorII(int number) {
        int result = 1;
        while (--number) {
            result *= 2;
        }
        return result;
    }
};