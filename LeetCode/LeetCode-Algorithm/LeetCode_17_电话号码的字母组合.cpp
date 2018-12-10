// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

// 2 : abc
// 3 : def
// 4 : ghi
// 5 : jkl
// 6 : mno 
// 7 : pqrs
// 8 : tuv 
// 9 : wxyz

// 示例:

// 输入："23"
// 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// 说明:
// 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

#include <string>
#include <vector>

using namespace std;

// 递归
class Solution1 {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res{};
        // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
        vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        DFS(digits, dict, 0, "", res);
        return res;
    }
    // level : 当前out字符串的长度
    void DFS(const string& digits, const vector<string>& dict, int level, string out, vector<string>& res) {
        if (level == digits.size()) {
            res.push_back(out);
            return;
        }
        string str = dict[digits[level] - '0'];
        for (int i = 0; i < str.size(); ++i) {
            DFS(digits, dict, level + 1, out + str[i], res);
        }
    }
};

// 迭代
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res{""};
        vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (int i{0}, sz = digits.size(); i < sz; ++i) {
            vector<string> t{};
            string str = dict[digits[i] - '0'];
            for (int j{0}; j < str.size(); ++j) { // t是在res的基础上每个字符串后面加一个字母
                for (string &s : res) t.push_back(s + str[j]);
            }
            res = t;
        }
        return res;
    }
};