// 题目描述
// 牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
// 同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
// 例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
// Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


// 思路：一个单词一个单词往结果里填
class Solution {
public:
    string ReverseSentence(string str) {
        int n = str.size();
        if (n == 0) return "";
        string res;
        string s; // 连续的一个单词
        for (int i = 0; i < n; ++i) {
            if (str[i] == ' ') {
                res = ' ' + s + res;
                s = ""; // 一个连续的单词结束了
            } else
                s += str[i];
        }
        if (!s.empty()) // 最后一个连续的单词
            res = s + res;
        return res;
    }
};