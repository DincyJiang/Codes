//��Ŀ����
//��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n�
//n <= 39

#include <vector>
using namespace std;

//˼·һ���ݹ�Fibonacci(n)=Fibonacci(n-1)+Fibonacci(n-2)
//���⣺�ݹ��㷨���ظ�����������ջ���
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

//˼·�������仯����
class Solution1 {
public:
    int Fibonacci(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};

// ��̬�滮
class Solution2{
public:
    int Fibonacci(int n) {
        if(0<n && n<=39)
        {
            int f = 0, g = 1;
            while(n--) {
            g += f; //g����һ�����g����һ�����f֮��
            f = g - f;//f������һ�����g
            }
            return f;
        }
        return 0;
    }
};