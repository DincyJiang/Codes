// 统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。

// 请注意，你可以假定字符串里不包括任何不可打印的字符。

// 示例:

// 输入: "Hello, my name is John"
// 输出: 5

#include <string>
#include <sstream>

using namespace std;

class Solution1 {
public:
    int countSegments(string s) {
        int res{0};
        bool isNewWord = true; // 记录一个连续的单词
        for (char& c : s) {
            if (c == ' ') {
                isNewWord = true;
                continue;
            }
            else {
                if (isNewWord) ++res;
                isNewWord = false;
            }
        }   
        return res;
    }
};

class Solution2 {
public:
    int countSegments(string s) {
        int res{0};
        stringstream ss(s);
        string t{};
        while (getline(ss, t, ' ')) {
            if (t.empty()) continue;
            ++res;
        }
        return res;
    }
};