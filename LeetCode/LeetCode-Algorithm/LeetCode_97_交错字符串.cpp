// 给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。

// 示例 1:

// 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// 输出: true
// 示例 2:

// 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// 输出: false

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

/*
递推公式为：

dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i - 1 + j]) || (dp[i][j - 1] && s2[j - 1] == s3[j - 1 + i]);

其中dp[i][j] 表示的是 s2 的前 i 个字符和 s1 的前 j 个字符是否匹配 s3 的前 i+j 个字符
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n1; ++i)
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        for (int j = 1; j <= n2; ++j)
            dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i-1+j]) ||
                           (dp[i][j-1] && s2[j-1] == s3[j-1+i]);
            }
        }
        return dp[n1][n2];
    }
};

/* DFS + hash
这道题也可以使用带优化的DFS来做，我们使用一个哈希集合，用来保存匹配失败的情况，
我们分别用变量i，j，和k来记录字符串s1，s2，和s3匹配到的位置，初始化的时候都传入0。
在递归函数中，首先根据i和j，算出key值，由于我们的哈希集合中只能放一个数字，
而我们要encode两个数字i和j，所以通过用i乘以s3的长度再加上j来得到key，
此时我们看，如果key已经在集合中，直接返回false，因为集合中存的是无法匹配的情况。
然后先来处理corner case的情况，如果i等于s1的长度了，说明s1的字符都匹配完了，
此时s2剩下的字符和s3剩下的字符可以直接进行匹配了，所以我们直接返回两者是否能匹配的bool值。
同理，如果j等于s2的长度了，说明s2的字符都匹配完了，
此时s1剩下的字符和s3剩下的字符可以直接进行匹配了，
所以我们直接返回两者是否能匹配的bool值。
如果s1和s2都有剩余字符，那么当s1的当前字符等于s3的当前字符，那么调用递归函数，
注意i和k都加上1，如果递归函数返回true，则当前函数也返回true；
还有一种情况是，当s2的当前字符等于s3的当前字符，那么调用递归函数，
注意j和k都加上1，如果递归函数返回true，那么当前函数也返回true。
如果匹配失败了，则将key加入集合中，并返回false即可，参见代码如下：
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        unordered_set<int> s; // 集合中存的是无法匹配的情况
        return func(s1, 0, s2, 0, s3, 0, s);
    }
    bool func(string& s1, int i, string& s2, int j, string& s3, int k, unordered_set<int>& s) {
        int key = i * s3.size() + j;
        if (s.count(key)) return false;
        if (i == s1.size()) return s2.substr(j) == s3.substr(k);
        if (j == s2.size()) return s1.substr(i) == s3.substr(k);
        if ((s1[i] == s3[k] && func(s1, i+1, s2, j, s3, k+1, s)) ||
            (s2[j] == s3[k] && func(s1, i, s2, j+1, s3, k+1, s)))
            return true;
        s.insert(key);
        return false;
    }
};