// 链接：https://ac.nowcoder.com/acm/problem/21652
// 来源：牛客网

// 牛牛最近开始学括号匹配拉
// 给你两个括号序列，不保证合法，求有多少种不同的方法可以将两个括号序列合并成一个合法的括号序列
// 合并的时候不能改变各自序列原先的顺序
// 输入描述:
// 输入两行包含两个字符串s1,s2

// 1 ≤  |s1|,|s2| ≤ 2500
// 输出描述:
// 输出一个整数，魔109+7
// 示例1
// 输入
// 复制
// (()  
// ())
// 输出
// 复制
// 19
// 说明

// 示例2
// 输入
// 复制
// ()()()()()()()()()()()()()()()()()()()()
// ()()()()()()()()()()()()()()()()()
// 输出
// 复制
// 487340184
// 示例3
// 输入
// 复制
// (((((
// )))))
// 输出
// 复制
// 42
// 示例4
// 输入
// 复制
// (())())))
// (())()
// 输出
// 复制
// 0

#include <bits/stdc++.h>
using namespace std;

char s1[2505], s2[2505];
int dp[2][2505], pre[2][2505], mod = 1e9+7;

int main()
{
    scanf("%s%s",s1+1,s2+1);
    int len1 = strlen(s1+1), len2 = strlen(s2+1), cur = 0;
    dp[cur][0] = 1;
    for(int i = 0; i <= len1; ++i)
    {
        if(i) cur ^= 1;
        if(i) memset(dp[cur], 0, sizeof(dp[cur]));
        for(int j = 0; j <= len2; ++j)
        {
            if(i == 0 && j == 0) continue;
            if(j) pre[cur][j] = pre[cur][j-1] + (s2[j] == '(' ? 1 : -1);
            else pre[cur][j] = pre[cur^1][j] + (s1[i] == '(' ? 1 : -1);

            if(pre[cur][j] < 0) continue;
            if(i) dp[cur][j] += dp[cur^1][j];
            if(j) dp[cur][j] += dp[cur][j-1];
            dp[cur][j] %= mod;
        }
    }
    if(pre[cur][len2] == 0) printf("%d\n",dp[cur][len2]);
    else printf("0\n");
    return 0;
}
