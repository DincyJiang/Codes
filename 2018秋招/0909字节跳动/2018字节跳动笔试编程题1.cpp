/*
LeetCode 3 最大不重复子串
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> m(256, -1);
    int res = 0, left = -1;
    for (int i = 0; i < s.size(); ++i) {
        left = max(left, m[s[i]]);
        m[s[i]] = i;
        res = max(res, i - left);
    }
    return res;
}

int main() {
	string str;
    cin >> str;
	cout << lengthOfLongestSubstring(str) << endl;
	return 0;
}