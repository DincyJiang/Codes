/*
LeetCode 93 复原IP地址
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(string s) {
    if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0')) return false;
    int res = atoi(s.c_str());
    return res <= 255 && res >= 0;
}

void restore(string s, int k, string out, vector<string> &res) {
    if (k == 0) {
        if (s.empty()) res.push_back(out);
    }
    else {
        for (int i = 1; i <= 3; ++i) {
            if (s.size() >= i && isValid(s.substr(0, i))) {
                if (k == 1) restore(s.substr(i), k - 1, out + s.substr(0, i), res);
                else restore(s.substr(i), k - 1, out + s.substr(0, i) + ".", res);
            }
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    restore(s, 4, "", res);
    return res;
}

int main(){
    string ip;
    cin >> ip;

    vector<string> res = restoreIpAddresses(ip);
    cout << res.size() << endl;

    return 0;
}