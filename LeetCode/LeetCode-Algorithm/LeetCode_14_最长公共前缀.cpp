// 编写一个函数来查找字符串数组中的最长公共前缀。

// 如果不存在公共前缀，返回空字符串 ""。

// 示例 1:

// 输入: ["flower","flow","flight"]
// 输出: "fl"
// 示例 2:

// 输入: ["dog","racecar","car"]
// 输出: ""
// 解释: 输入不存在公共前缀。

#include <string>
#include <vector>

using namespace std;

// 暴力查找
class Solution1 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string res{};
        for (int j{0}, sz_0 = strs[0].size(); j < sz_0; ++j) {
            char c = strs[0][j];
            for (int i{1}, sz = strs.size(); i < sz; ++i) {
                if (j >= strs[i].size() || strs[i][j] != c)
                    return res;
            }
            res += c;
        }
        return res;
    }
};

// 先排序，如果有共同前缀的话，一定会出现在首尾两端的字符串中，所以我们只需要找首尾字母串的共同前缀即可
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        sort(strs.begin(), strs.end());
        int i{0};
        int len = min(strs[0].size(), strs.back().size());
        while (i < len && strs[0][i] == strs.back()[i]) ++i;
        return strs[0].substr(0, i);
    }
};