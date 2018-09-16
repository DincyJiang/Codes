/*
第一行：总人数
第二行：总请求数
下面的是各个请求，这两个人不能在一个班

输入：
5
5
1 2
1 3
1 4
1 5
2 3
输出：
0

输入：
5
4
1 2
1 3
1 4
1 5
输出：
1
*/

#include <iostream>
#include <set>
using namespace std;

// 最多两个集合，超过两个集合就返回错误
int main() {
    int sum; // 总人数
    cin >> sum;
    int count; // 请求数
    cin >> count;
    // 设置两个集合
    set<int> s1;
    set<int> s2;

    for (int i = 0; i < count; ++i) {
        int m ,n;
        cin >> m >> n;
        if ((s1.find(m) != s1.end() && s1.find(n) != s1.end()) ||
            (s2.find(m) != s2.end() && s2.find(n) != s2.end())) {
            cout << 0 << endl;
            return 0;
        }
        if (s1.find(m) != s1.end())
            s2.insert(n);
        else
            s1.insert(n);
        if (s1.find(n) != s1.end())
            s2.insert(m);
        else
            s1.insert(m);
    }
    cout << 1 << endl;
    return 0;
}