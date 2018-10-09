/*
给定两个字符串，求出它们之间最长的相同子字符串的长度。
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int LCS_Length(const string& s1, const string& s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
    int res = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i-1] != s2[j-1])
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i-1][j-1] + 1;
            res = max(res, dp[i][j]);
        }
    }
    return res;
}

int main() {
    cout << LCS_Length("ABACDE", "ACDECC") << endl;
    return 0;
}