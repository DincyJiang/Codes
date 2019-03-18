#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s{};
    cin >> s;
    int n = s.size();
    string res{};
    int low = 0;
    int high = n-1;
    if (n % 2 == 0) {// 偶数个
        while (low < high) {
            res.push_back(s[high]);
            res.push_back(s[low]);
            --high;
            ++low;
        }
    } else if (n % 2 != 0) { // 奇数个
        while (low < high) {
            res.push_back(s[low]);
            res.push_back(s[high]);
            --high;
            ++low;
        }
        res.push_back(s[high]);
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}