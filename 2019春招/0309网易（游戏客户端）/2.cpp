#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int T{}; // 测试点数量
    cin >> T;
    vector<int> res(T, 0); // 结果数组
    for (int i{0}; i < T; ++i) {
        int N{}; // 特殊规则数量
        cin >> N;
        map<char, set<char>> m{}; // 字母映射表
        for (int j{0}; j < N; ++j) {
            char x{};
            char y{};
            cin >> x >> y;
            m[y].insert(x);
        }
        int M{}; // M个键失灵
        set<char> chars{}; // 失灵字母表
        for (int k{0}; k < M; ++k) {
            char c{};
            cin >> c;
            chars.insert(c);
        }
        map<char, int> m2{}; // 字母键值表
        for (char c{'a'}; c < 'z'; ++c) {
            m2[c] = 1;
        }

        // 更新m2
        for (char c : chars) {
            set<char> set2 = m[c]; // 可以加上shift变换成c的集合


            
        }

        string s{}; // 稿件内容
        cin >> s;

        // 计算结果
        for (char &c : s) {
            res[i] += m2[c];
        }
    }

    // 输出结果
    for (int i{0}; i < T; ++i) {
        cout << res[i] << endl;
    }

    return 0;
}