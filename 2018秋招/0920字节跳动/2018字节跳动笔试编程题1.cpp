/*
LeetCode 71
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

string simplifyPath(string path) {
    string res, t;
    stringstream ss(path);
    vector<string> v;
    while (getline(ss, t, '/')) {
        if (t == "" || t == ".") continue;
        if (t == ".." && !v.empty()) v.pop_back();
        else if (t != "..") v.push_back(t);
    }
    for (string s : v) res += "/" + s;
    return res.empty() ? "/" : res;
}

int main () {
    string s;
    cin >> s;
    string res = simplifyPath(s);
    cout << res << endl;
    return 0;
}
    
