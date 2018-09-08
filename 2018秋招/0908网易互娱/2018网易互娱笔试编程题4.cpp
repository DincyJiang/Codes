/*

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 两个矩阵乘积
vector<int> judge_two(const vector<int>& A, const vector<int>& B) {
    vector<int> res;

    return res;
}

string judge(int N, const vector<vector<int>>& vec) {
    
    return "yes";
}

int main() {
    int T;
    cin >> T; // T组数据
    vector<string> res(T, "");
    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;
        vector<vector<int>> vec(N, vector<int>(2, 0));
        for (int i = 0; i < N; ++i) {
            int x, y;
            cin >> x >> y;
            vec[i][0] = x;
            vec[i][1] = y;
        }
        res[i] = judge(N, vec);
    }

    for (string s : res)
        cout << s << endl;

    return 0;
}