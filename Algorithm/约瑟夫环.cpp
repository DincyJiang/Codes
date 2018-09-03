/*
约瑟夫问题
约瑟夫问题（有时也称为约瑟夫斯置换，是一个出现在计算机科学和数学中的问题。在计算机编程的算法中，类似问题又称为约瑟夫环。又称“丢手绢问题”.）

一般形式
N个人围成一圈，从第一个开始报数，第M个将淘汰，退出圈外，重复上述过程n-1次，最后剩下一个，最后留下来的人获胜。求出最后获胜者的编号。 
例如N=6，M=4，被杀掉的顺序是：4，2，1，3，6，5 
获胜者便是5。
*/

#include <iostream>

using namespace std;

// sum指的是总人数，value指的是每次最大报到的数值，n是第n次，
// 该函数每次可以求出第n次扔海里的人的编号，( ysfdg指的是约瑟夫递归 ) 。
int ysfdg ( int sum, int value, int n) {
    if ( n == 1 )
        return ( sum + value - 1 ) % sum;
    else
        return ( ysfdg ( sum-1, value, n-1 ) + value ) % sum;
}

/*
约塞夫环的动态规划解法
描述:从0到n-1编号，从1到m报数，每次报m的出局，求最后一个出局者
建模：设dp[i]表示长度为i，从1到m报数子问题的解
分析：对于长为i个进行编号，0..1...i-1，则第一个出局者为(m-1)%i,对剩余i-1个重新编号，
m%i -->0   (m+1)%i --> 1  (m+i-2)%i --> i-2,
则出局者当前编号为dp[i-1]，映射回i时的编号为(m+dp[i-1])%i,
由此可知dp[i] = (dp[i-1]+m)%i; 
dp: dp[i] = (dp[i-1]+m)%i;
m:报数长度
n:总人数
return:n个人从0..n-1编号的编号
*/
int ysf(int m, int n) {
	int result = 0; //dp[1] = 0
	for(int i = 2; i <= n; i++) {
		result = (result + m) % i;
	}
	return result;
}

int main() {
    cout << ysfdg(7, 4, 6) << endl;
    cout << ysf(4, 7) + 1 << endl;
    return 0;
}