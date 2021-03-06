// 给定一个字符串 s 和一些长度相同的单词 words。在 s 中找出可以恰好串联 words 中所有单词的子串的起始位置。

// 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。

// 示例 1:

// 输入:
//   s = "barfoothefoobarman",
//   words = ["foo","bar"]
// 输出: [0,9]
// 解释: 从索引 0 和 9 开始的子串分别是 "barfoor" 和 "foobar" 。
// 输出的顺序不重要, [9,0] 也是有效答案。
// 示例 2:

// 输入:
//   s = "wordgoodstudentgoodword",
//   words = ["word","student"]
// 输出: []

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// 用到两个哈希表，第一个哈希表先把所有的单词存进去，
// 然后从开头开始一个个遍历，停止条件为当剩余字符个数小于单词集里所有字符的长度。
// 这时候我们需要定义第二个哈希表，然后每次找出给定单词长度的子串，看其是否在第一个哈希表里，如果没有，则break，
// 如果有，则加入第二个哈希表，但相同的词只能出现一次，如果多了，也break。
// 如果正好匹配完给定单词集里所有的单词，则把i存入结果中
class Solution1 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res{};
        if (s.empty() || words.empty()) return res;
        int n = words.size();
        int m = words[0].size();
        unordered_map<string, int> hash1{};
        for (auto &word : words) ++hash1[word];
        for (int i{0}, sz = s.size(); i <= sz - n*m; ++i) {
            unordered_map<string, int> hash2{};
            int j{0};
            for (; j < n; ++j) {
                string t = s.substr(i + j * m, m);
                if (hash1.find(t) == hash1.end()) break;
                ++hash2[t];
                if (hash2[t] > hash1[t]) break;
            }
            if (j == n) res.push_back(i);
        }
        return res;
    }
};

// O(n)时间复杂度
// 这种方法不再是一个字符一个字符的遍历，而是一个词一个词的遍历，
// 比如根据题目中的例子，字符串s的长度n为18，words数组中有两个单词(cnt=2)，每个单词的长度len均为3，
// 那么遍历的顺序为0，3，6，8，12，15，然后偏移一个字符1，4，7，9，13，16，
// 然后再偏移一个字符2，5，8，10，14，17，这样就可以把所有情况都遍历到，
// 我们还是先用一个哈希表m1来记录words里的所有词，然后我们从0开始遍历，
// 用left来记录左边界的位置，count表示当前已经匹配的单词的个数。
// 然后我们一个单词一个单词的遍历，如果当前遍历的到的单词t在m1中存在，那么我们将其加入另一个哈希表m2中，
// 如果在m2中个数小于等于m1中的个数，那么我们count自增1，如果大于了，那么需要做一些处理，
// 比如下面这种情况, s = barfoofoo, words = {bar, foo, abc}, 
// 我们给words中新加了一个abc，目的是为了遍历到barfoo不会停止，
// 那么当遍历到第二foo的时候, m2[foo]=2, 而此时m1[foo]=1，
// 这时候已经不连续了，所以我们要移动左边界left的位置，我们先把第一个词t1=bar取出来，然后将m2[t1]自减1，
// 如果此时m2[t1]<m1[t1]了，说明一个匹配没了，那么对应的count也要自减1，然后左边界加上个len，这样就可以了。
// 如果某个时刻count和cnt相等了，说明我们成功匹配了一个位置，那么将当前左边界left存入结果res中，
// 此时去掉最左边的一个词，同时count自减1，左边界右移len，继续匹配。
// 如果我们匹配到一个不在m1中的词，那么说明跟前面已经断开了，我们重置m2，count为0，左边界left移到j+len，参见代码如下：
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return {};
        vector<int> res{};
        int n = s.size();
        int cnt = words.size();
        int len = words[0].size();
        unordered_map<string, int> hash1{};
        for (string &word : words) ++hash1[word];
        for (int i{0}; i < len; ++i) {
            int left = i;
            int count{0};
            unordered_map<string, int> hash2{};
            for (int j = i; j <= n - len; j += len) {
                string t = s.substr(j, len);
                if (hash1.count(t)) {
                    ++hash2[t];
                    if (hash2[t] <= hash1[t]) {
                        ++count;
                    } else {
                        while (hash2[t] > hash1[t]) {
                            string t1 = s.substr(left, len);
                            --hash2[t1];
                            if (hash2[t1] < hash1[t1]) --count;
                            left += len;
                        }
                    }
                    if (count == cnt) {
                        res.push_back(left);
                        --hash2[s.substr(left, len)];
                        --count;
                        left += len;
                    }
                } else {
                    hash2.clear();
                    count = 0;
                    left = j + len;
                }
            }
        }
        return res;
    }
};