// 给定字符串列表，你需要从它们中找出最长的特殊序列。最长特殊序列定义如下：该序列为某字符串独有的最长子序列（即不能是其他字符串的子序列）。

// 子序列可以通过删去字符串中的某些字符实现，但不能改变剩余字符的相对顺序。空序列为所有字符串的子序列，任何字符串为其自身的子序列。

// 输入将是一个字符串列表，输出是最长特殊序列的长度。如果最长特殊序列不存在，返回 -1 。

 

// 示例：

// 输入: "aba", "cdc", "eae"
// 输出: 3
 

// 提示：

// 所有给定的字符串长度不会超过 10 。
// 给定字符串列表的长度将在 [2, 50 ] 之间。

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

// 暴力搜索
// 遍历所有字符串，对于每个遍历到的字符串，再和所有其他字符串相比较，看是不是某一个字符串的子序列
class Solution1 {
public:
    int findLUSlength(vector<string>& strs) {
        int res{-1};
        int j{0};
        int n = strs.size();
        for (int i{0}; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                if (i == j) continue;
                if (check(strs[i], strs[j])) break; // 检查strs[i]是不是strs[j]的子序列
            }
            if (j == n)
                res = max(res, (int)strs[i].size());
        }
        return res;
    }
    bool check(string subs, string str) {
        int i{0};
        for (char c : str) {
            if (c == subs[i])
                ++i;
            if (i == subs.size()) break;
        }
        return i == subs.size();
    }
};

class Solution2 {
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        unordered_set<string> s{};
        // 按长度排序，从长到短
        sort(strs.begin(), strs.end(), [](string a, string b) {
            if (a.size() == b.size()) return a > b;
            return a.size() > b.size();
        });
        for (int i{0}; i < n; ++i) {
            if (i == n-1 || strs[i] != strs[i+1]) {
                bool found = true;
                // 对于当前字符串，和集合中的所有字符串相比，看是否是某个的子序列
                // 如果都不是，就说明当前的就是最长的非共同子序列
                for (auto a : s) { 
                    int j{0};
                    for (char c : a) {
                        if (c == strs[i][j]) ++j;
                        if (j == strs[i].size()) break;
                    }
                    if (j == strs[i].size()) {
                        found = false;
                        break;
                    }
                }
                if (found)
                    return strs[i].size();
            }
            s.insert(strs[i]); // 集合记录已经遍历过的字符串，利用集合的去重特性
        }
        return -1;
    }
};