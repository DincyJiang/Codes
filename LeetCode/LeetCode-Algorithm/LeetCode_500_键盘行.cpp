// 给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。

 

// American keyboard

 

// 示例：

// 输入: ["Hello", "Alaska", "Dad", "Peace"]
// 输出: ["Alaska", "Dad"]
 

// 注意：

// 你可以重复使用键盘上同一字符。
// 你可以假设输入的字符串将只包含字母。

#include <vector>
#include <unordered_set>
#include <string>

using std::vector;
using std::string;
using std::unordered_set;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res{};
        unordered_set<char> row1{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        unordered_set<char> row2{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        unordered_set<char> row3{'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        for (string &word : words) {
            int _1{0}; // 每一行的标志
            int _2{0};
            int _3{0};
            for (char c : word) {
                if (c < 'a') // 大写字母变小写
                    c += 32;
                if (row1.count(c))
                    _1 = 1;
                if (row2.count(c))
                    _2 = 1;
                if (row3.count(c))
                    _3 = 1;
                if (_1 + _2 + _3 > 1) // 出现超过1行
                    break;
            }
            if (_1 + _2 + _3 == 1)
                res.push_back(word);
        }
        return res;
    }
};