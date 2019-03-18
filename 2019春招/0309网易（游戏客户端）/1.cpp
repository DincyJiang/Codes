#include <iostream>
#include <string>

using namespace std;

int main() {
    int T{}; // 测试点数量
    cin >> T;
    for (int i{0}; i < T; ++i) {
        int x{}; // 字符宽度
        int y{}; // 最大行宽
        cin >> x >> y;
        string s{}; // 文本
        cin >> s;
        int res{0}; // 结果行数
        int num = y / x; // 每一行可以放置的字符数
        int count = 0;
        int n = s.size();
        bool bre = false;
        for (int i{0}; i < n; ++i) {
            char c = s[i];
            if ((c > 'a' && c < 'z') || (c > 'A' && c < 'Z')) {
                count++;
                if (count == num) {
                    count = 0;
                    ++res;
                }
            } else if (c == ',' || c == '.' || c == '!' || c == '?') {
                if (num == 1 || i == 0 || s[i-1] == '\n') {
                    cout << "impossible" << endl;
                    bre = true;
                    break;
                }
                // if (count == 0) count = 2;
            } else if (c == '\n') {
                count = 0;
                ++res;
            }
        }
        if (!bre) 
            cout << res << endl;
    }

    return 0;
}
