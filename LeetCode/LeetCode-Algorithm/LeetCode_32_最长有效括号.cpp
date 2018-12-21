// 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

// 示例 1:

// 输入: "(()"
// 输出: 2
// 解释: 最长有效括号子串为 "()"
// 示例 2:

// 输入: ")()())"
// 输出: 4
// 解释: 最长有效括号子串为 "()()"

#include <string>
#include <stack>
#include <vector>

using namespace std;

// 用栈，下标入栈
class Solution1 {
public:
    int longestValidParentheses(string s) {
        int res{0};
        int start{0}; // 记录合法括号串的起始位置
        stack<int> stack{};
        for (int i{0}, len = s.size(); i < len; ++i) {
            if (s[i] == '(') {
                stack.push(i);
            } else if (s[i] == ')') {
                if (stack.empty()) {
                    start = i + 1;
                } else {
                    stack.pop();
                    res = stack.empty() ? max(res, i - start + 1) : max(res, i - stack.top());
                }
            }
        }
        return res;
    }
};

// 动态规划
// DP[i]：以s[i-1]为结尾的longest valid parentheses substring的长度。
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int maxLen{0};
        vector<int> dp(n+1, 0);
        for (int i{1}; i <= n; ++i) {
            int j = i - 2 - dp[i-1]; // 找i前一个字符的最长括号串DP[i]的前一个字符
            if (s[i-1] == '(' || j < 0 || s[j] == ')')
                dp[i] = 0;
            else { 
                dp[i] = dp[i - 1] + 2 + dp[j];
                maxLen = max(maxLen, dp[i]);
            }
        }
        return maxLen;
    }
};