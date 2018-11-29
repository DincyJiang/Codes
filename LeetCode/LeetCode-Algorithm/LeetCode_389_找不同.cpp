// 给定两个字符串 s 和 t，它们只包含小写字母。

// 字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。

// 请找出在 t 中被添加的字母。

 

// 示例:

// 输入：
// s = "abcd"
// t = "abcde"

// 输出：
// e

// 解释：
// 'e' 是那个被添加的字母。

#include <string>
#include <unordered_map>

using namespace std;

// 哈希表
class Solution1 {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> hash{};
        for (auto &c : s) ++hash[c];
        for (auto &c : t) {
            if (--hash[c] < 0) return c;
        }
        return {};
    }
};

// 位操作，异或，相同的字符都抵消了，剩下的是最后加的字符
class Solution2 {
public:
    char findTheDifference(string s, string t) {
        char res{};
        for (auto &c : s) res ^= c;
        for (auto &c : t) res ^= c;
        return res;
    }
};

// 
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res{};
        for (auto &c : s) res -= c;
        for (auto &c : t) res += c;
        return res;
    }
};