/*
描述

给定一个仅由小写字母组成的字符串。现在请找出一个位置，删掉那个字母之后，字符串变成回文。请放心总会有一个合法的解。如果给定的字符串已经是一个回文串，那么输出-1。


输入描述

第一行包含T，测试数据的组数。后面跟有T行，每行包含一个字符串。


输出描述

如果可以删去一个字母使它变成回文串，则输出任意一个满足条件的删去字母的位置（下标从0开始）。例如：

bcc

我们可以删掉位置0的b字符。


样例输入 1 

3
aaab
baa
aaa
样例输出 1

3
0
-1
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 错误答案
int help(const string& s) {
  int left = 0;
  int right = s.size() - 1;
  while (left < right) {
    if (s[left] != s[right]) {
      if (s[left+1] == s[right])
        return left;
      else if (s[left] == s[right-1])
        return right;
    } else {
      ++left;
      --right;
    }
  }
  return left;
}

int main () {
  int T;
  cin >> T;
  vector<int> res;
  while (T--) {
    string s;
    cin >> s;
    res.push_back(help(s));
  }
  
  for (auto& i : res)
    cout << i << endl;
  
  return 0;
}