// 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

// 示例 1:

// 输入: "abcabcbb"
// 输出: 3 
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 示例 2:

// 输入: "bbbbb"
// 输出: 1
// 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 示例 3:

// 输入: "pwwkew"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 哈希表
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        int res{0};
        int left{0};
        int sz = s.size();
        unordered_map<char, int> hash{};
        for (int i{0}; i < sz; ++i) {
            if (hash[s[i]] == 0 || hash[s[i]] < left)
                res = max(res, i - left + 1);
            else
                left = hash[s[i]];
            hash[s[i]] = i + 1;
        }
        return res;
    }
};

// 滑动窗口
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int sz = s.size();
        int hash[256]{0};
        int l{0}, r{-1};  // s[l...r]为滑动窗口
        int res{0};
        while (l < sz) {
            if (r+1 < sz && hash[s[r+1]] == 0)
                hash[s[++r]]++;
            else
                hash[s[l++]]--;
            res = max(res, r-l+1);
        }
        return res;
    }
};

// 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);
        int res{0};
        int left{-1};
        int sz = s.size();
        for (int i{0}; i < sz; ++i) {
            if (hash[s[i]] > left) left = hash[s[i]];
            hash[s[i]] = i;
            res = max(res, i - left);
        }   
        return res;
    }
};