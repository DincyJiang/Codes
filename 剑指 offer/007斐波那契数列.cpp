//��Ŀ����
//��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n�
//n <= 39


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

//˼·������̬�滮��
class Solution {
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