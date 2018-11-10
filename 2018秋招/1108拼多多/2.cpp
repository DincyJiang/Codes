// 比较版本号
// 时间限制：C/C++语言 1000MS；其他语言 3000MS
// 内存限制：C/C++语言 65536KB；其他语言 589824KB
// 题目描述：
// 给定两个版本字符串version1和version2，比较两个版本的大小， 如果version1 > version2， 则返回1； 如果version1 < version2， 则返回-1； 如果version1 = version2， 则返回0。 version非空，只包含数字和字符 '.'

// 输入
// 共2行输入，第一行为version1，第二行为version2。

// 输出
// 共1行输出，包含一个整数，表示比较结果。


// 样例输入
// 0.1
// 1.1
// 样例输出
// -1

// Hint
// 再给一组数据
// 输入：
// 1.0.1
// 1
// 输出：
// 1

// LeetCode 165
#include <iostream>
#include <sstream>
using namespace std;

int func (string version1, string version2) {
	int n1 = version1.size();
    int n2 = version2.size();
    int i{0}, j{0};
    while (i < n1 || j < n2) {
        int d1 = 0, d2 = 0;
        // 一位一位累加
        while (i < n1 && version1[i] != '.') {
            d1 = d1 * 10 + version1[i++] - '0';
        }
        while (j < n2 && version2[j] != '.') {
            d2 = d2 * 10 + version2[j++] - '0';
        }
        if (d1 > d2) return 1;
        else if (d1 < d2) return -1;
        ++i;
        ++j;
    }
    return 0;
}
    
int main() {
    string version1;
    string version2;
    
    cin >> version1 >> version2;
    
    cout << func(version1, version2) << endl;
    
    return 0;
}
