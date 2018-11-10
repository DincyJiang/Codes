// 题目描述
// 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
// 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
// 输入描述:
// 输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。


/*
思路：
n个元素的全排列=n-1个元素全排列 + 1个元素作为前缀
出口：如果只有一个元素的全排列，说明已经排完，则输出
不断将每个元素放在第一个元素，其余元素进行全排列
*/
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        int n = str.size();
        if (n == 0) return res;
        help(res, str, 0, n);
        sort(res.begin(), res.end());
        return res;
    }
private:
    void help(vector<string>& res, string& str, int index, int& n) {
        if (index == n - 1) {
            res.push_back(str);
            return;
        }
        for (int i = index; i < n; ++i) {
            if (i != index && str[i] == str[index])
                continue; // 跳过重复字符
            swap(str[i], str[index]);
            help(res, str, index + 1, n);
            swap(str[i], str[index]);  // 回溯
        }
    }
};