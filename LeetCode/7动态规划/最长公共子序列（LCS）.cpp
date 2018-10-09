// 一个字符串的子序列，是指从该字符串中去掉任意多个字符后剩下的字符在不改变顺序的情况下组成的新字符串。
// 最长公共子序列，是指多个字符串可具有的长度最大的公共的子序列。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string LCS(const string& s1, const string& s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
    vector<vector<int> > mark(m+1, vector<int>(n+1, 0)); // 方向数组
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                mark[i][j] = 1; // 方向为：左上
            } else if (dp[i-1][j] > dp[i][j-1]) {
                dp[i][j] = dp[i-1][j];
                mark[i][j] = 2; // 方向为：上
            } else {
                dp[i][j] = dp[i][j-1];
                mark[i][j] = 3; // 方向为：左
            }
        }
    }
    string res;
    while (m > 0 && n > 0) { // 倒序把结果存入
        if (mark[m][n] == 1) {
            res.insert(res.begin(), s1[m-1]);
            --m;
            --n;
        } else if (mark[m][n] == 2) {
            --m;
        } else if (mark[m][n] == 3) {
            --n;
        }
    }
    return res;
}
int main() {
    string res = LCS("ABCD", "AEBD");
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << ' ';
    cout << endl;
    return 0;
}


// 思路1：递归方法求最长公共子序列的长度
// 用递归的方法优点是编程简单，容易理解。
// 缺点是效率不高，有大量的重复执行递归调用，而且只能求出最大公共子序列的长度，
// 求不出具体的最大公共子序列。

// string a = "ABCBDAB";
// string b = "BDCABA";
// int LCS(int i, int j)
// {
//     if(i >= a.size() || j >= b.size())
//         return 0;
//     if(a[i]==b[j])
//         return 1+LCS(i+1,j+1);
//     else
//         return LCS(i+1,j) > LCS(i,j+1)? LCS(i+1,j):LCS(i,j+1);
// }

