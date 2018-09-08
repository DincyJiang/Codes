/*
给定字符串中只有大写字符
连续递增超过四个的子字符串变成：子字符串头 + ‘-’ + 子字符串尾
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string change(string s) {
    s += 'A'; // 补一个结尾字符
    int n = s.size();
    string res;
    string temp; // 递增子串
    temp += s[0];
    for (int i = 1; i < n; ++i) {
        if (s[i] - s[i-1] == 1) {
            temp += s[i];
        } else {
            if (temp.size() < 4)
                res += temp;
            else
                res = res + temp[0] + '-' + temp[temp.size() - 1];
            temp = s[i];
        }
    }
    return res;
}

int main(){
    int T;
    cin >> T;
    vector<string> data(T, "");
    for(int i = 0; i < T; i++){
        string s;
        cin >> s;
        data[i] = change(s);
    }

    for(int i = 0; i < T; i++)
        cout << data[i] << endl;

    return 0;
}