/*
给定一个字符串，找出不含有重复字符的最长子串的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 无重复字符的最长子串是 "abc"，其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 无重复字符的最长子串是 "b"，其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 无重复字符的最长子串是 "wke"，其长度为 3。
     请注意，答案必须是一个子串，"pwke" 是一个子序列 而不是子串。
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int freq[256] = {0};
        int l = 0, r = -1;  // nums[l...r]为滑动窗口
        int res = 0;
        while (l < size) {
            if (r+1 < size && freq[s[r+1]] == 0)
                freq[s[++r]]++;
            else
                freq[s[l++]]--;
            res = max(res, r-l+1);
        }
        return res;
    }
};

class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(256, -1);
        int res = 0, left = -1;
        for (int i = 0; i < s.size(); ++i) {
            left = max(left, m[s[i]]);
            m[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
    }
};