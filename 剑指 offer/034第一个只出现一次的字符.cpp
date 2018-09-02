// 题目描述
// 在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
// 并返回它的位置, 如果没有则返回 -1（需要区分大小写）。

#include <iostream>
#include <string>
#include <map>
using namespace std;


//思路：哈希
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int len = str.length();
        map<char, int> map;
        for (int i = 0; i < len; ++i) {
            ++map[str[i]];
        }
        for (int i = 0; i < len; ++i) {
            if (map[str[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    string str = "psdpsdllsajo";
    int i = s.FirstNotRepeatingChar(str);
    cout << i << endl;
    return 0;
}