// 给定一个文档 (Unix-style) 的完全路径，请进行路径简化。

// 例如，
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"

// 边界情况:

// 你是否考虑了 路径 = "/../" 的情况？
// 在这种情况下，你需返回 "/" 。
// 此外，路径中也可能包含多个斜杠 '/' ，如 "/home//foo/" 。
// 在这种情况下，你可忽略多余的斜杠，返回 "/home/foo" 。

#include <string>
#include <sstream>
#include <vector>
using namespace std;

// C++中也有专门处理字符串的机制，我们可以使用stringstream来分隔字符串，然后对每一段分别处理
class Solution {
public:
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
};