// 给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。

// 字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

// 说明：

// 字母异位词指字母相同，但排列不同的字符串。
// 不考虑答案输出的顺序。
// 示例 1:

// 输入:
// s: "cbaebabacd" p: "abc"

// 输出:
// [0, 6]

// 解释:
// 起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
// 起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
//  示例 2:

// 输入:
// s: "abab" p: "ab"

// 输出:
// [0, 1, 2]

// 解释:
// 起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
// 起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
// 起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。

#include <vector>
#include <string>

using std::vector;
using std::string;

// 两个哈希表，一个记录p中所有字母出现的次数，另一个记录s中对应p的长度的一串字符串
class Solution1 {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.empty()) return {};
        vector<int> res{};
        vector<int> hash1(256, 0);
        vector<int> hash2(256, 0);
        
        int n = p.size();
        for (int i = 0; i < n; ++i) {
            ++hash1[s[i]];
            ++hash2[p[i]];
        }
        if (hash1 == hash2) 
            res.push_back(0);
        int m = s.size();
        for (int i = n; i < m; ++i) {
            ++hash1[s[i]]; // 加上新的
            --hash1[s[i-n]];// 去掉最左边的
            if (hash1 == hash2) 
                res.push_back(i - n + 1);
        }
        return res;
    }
};