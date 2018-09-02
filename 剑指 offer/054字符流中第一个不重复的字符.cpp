// 题目描述
// 请实现一个函数用来找出字符流中第一个只出现一次的字符。
// 例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
// 当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


// 思路：哈希表
class Solution {
public:
  //Insert one char from stringstream
    void Insert(char ch) {
         s += ch;
        ++hash[ch];
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (hash[s[i]] == 1) {
                return s[i];
            }
        }
        return '#';
    }
private:
    string s;
    int hash[256];
};