//题目描述
//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

//思路一：
// a.如果两种跳法，1阶或者2阶，那么假定第一次跳的是一阶，那么剩下的是n-1个台阶，跳法是f(n-1);
// b.假定第一次跳的是2阶，那么剩下的是n-2个台阶，跳法是f(n-2)
// c.由a，b假设可以得出总跳法为: f(n) = f(n-1) + f(n-2) 
// d.然后通过实际的情况可以得出：只有一阶的时候 f(1) = 1 ,只有两阶的时候可以有 f(2) = 2
// e.可以发现最终得出的是一个斐波那契数列：
class Solution {
public:
    int jumpFloor(int number) {
        if (number <= 0) 
            return -1;
        else if (number == 1) 
            return 1;
        else if (number ==2) 
            return 2;
        else
            return  jumpFloor(number-1)+jumpFloor(number-2);
    }
};

//思路二：动态规划，
class Solution {
public:
    int jumpFloor(int n) {
        if(n>=1)
        {
            int f = 0, g = 1;
            while(n--) {
            g += f; //g是上一步骤的g和上一步骤的f之和
            f = g - f;//f就是上一步骤的g
            }
            return g;
        }
        return 0;
    }
};