/*

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int T, N, M, L, S, X, P;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> N >> M >> L >> S;
        for (int i = 0; i < N; ++i) {
            cin >> X >> P;
            vector<string> tag;
            for (int j = 0; j < P; ++j) {
                string s;
                cin >> s;
                tag.push_back(s);
            }
        }
    }
    return 0;
}