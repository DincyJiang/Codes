// 给出一个字符串数组words组成的一本英语词典。从中找出最长的一个单词，该单词是由words词典中其他单词逐步添加一个字母组成。若其中有多个可行的答案，则返回答案中字典序最小的单词。

// 若无答案，则返回空字符串。

// 示例 1:

// 输入: 
// words = ["w","wo","wor","worl", "world"]
// 输出: "world"
// 解释: 
// 单词"world"可由"w", "wo", "wor", 和 "worl"添加一个字母组成。
// 示例 2:

// 输入: 
// words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
// 输出: "apple"
// 解释: 
// "apply"和"apple"都能由词典中的单词组成。但是"apple"得字典序小于"apply"。
// 注意:

// 所有输入的字符串都只包含小写字母。
// words数组长度范围为[1,1000]。
// words[i]的长度范围为[1,30]。

#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

// 首先按照字典序从小到大排序
// 遍历单词，有两种情况可以将单词加入集合中
// 第一种：第一个单词
// 第二种：当前单词去掉最后一个字母在集合中也能找到
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end()); // 按字典序从小到大排序
        string res{};
        unordered_set<string> set{};
        for (string word : words) {
            if (word.size() == 1 || set.count(word.substr(0, word.size()-1))) {
                if (word.size() > res.size()) res = word;
                set.insert(word);
            }
        }
        return res;
    }
};