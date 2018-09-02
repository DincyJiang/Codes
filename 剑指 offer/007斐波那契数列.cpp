//题目描述
//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
//n <= 39


//思路一：递归Fibonacci(n)=Fibonacci(n-1)+Fibonacci(n-2)
//问题：递归算法的重复计算容易让栈溢出
class Solution {
public:
	int Fibonacci(int n) {
        if(n>=1 && n<=2)
            return 1;
        else if(n>=3 && n<=39)      
            return Fibonacci(n-1)+Fibonacci(n-2); 
        else
            return 0;
    }
};

//思路二：动态规划，
class Solution {
public:
    int Fibonacci(int n) {
        if(0<n && n<=39)
        {
            int f = 0, g = 1;
            while(n--) {
            g += f; //g是上一步骤的g和上一步骤的f之和
            f = g - f;//f就是上一步骤的g
            }
            return f;
        }
        return 0;
    }
};