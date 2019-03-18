// 给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。

// 示例:
// 输入: S = "a1b2"
// 输出: ["a1b2", "a1B2", "A1b2", "A1B2"]

// 输入: S = "3z4"
// 输出: ["3z4", "3Z4"]

// 输入: S = "12345"
// 输出: ["12345"]
// 注意：

// S 的长度不超过12。
// S 仅由数字和字母组成。

#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution1 {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res{""};
        for (char c : S) {
            int len = res.size();
            if (c >= '0' && c <= '9') { // 如果是数字直接加在每一个字符串后面
                for (string &str : res) {
                    str.push_back(c);
                }
            } else {
                for (int i{0}; i < len; ++i) {
                    res.push_back(res[i]);
                    res[i].push_back(tolower(c));
                    res[len+i].push_back(toupper(c));
                }
            }
        }
        return res;
    }
};

// 只需要先统计出S中字母的个数cnt，然后遍历 [0, 2^cnt) 中的每个数字，
// 对于每个数字，再遍历S中的每个字符，如果是字母，那么如果当前位是1，则加入小写字母，反之加入大写字母；
// 如果是数字，则直接加入即可。我们用j指向位，每次处理完一位后j自增1，表示对下一位进行处理
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res{};
        int count{0}; // 字母的个数
        for (char c : S) {
            if (c > '9') ++count;
        }
        for (int i{0}; i < (1 << count); ++i) { // 1 << count是 2^count
            int j{0};
            string word{""};
            for (char c : S) {
                if (c > '9') { // 如果是字母
                    if (((i >> j++) & 1) == 1) {
                        word.push_back(tolower(c));
                    } else {
                        word.push_back(toupper(c));
                    }
                } else { // 如果是数字
                    word.push_back(c);
                }
            }
            res.push_back(word);
        }
        return res;
    }
};