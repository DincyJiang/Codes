// 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

// 例如，给出 n = 3，生成结果为：

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

#include <vector>
#include <string>

using namespace std;

// 递归
class Solution1 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res{};
        generate(n, n, string{}, res);
        return res;
    }
    void generate(int left, int right, string s, vector<string>& res) {
        if (left > right) return;
        if (left == 0 && right == 0) res.push_back(s);
        else {
            if (left > 0) generate(left - 1, right, s + '(', res);
            if (right > 0) generate(left, right - 1, s + ')', res);
        }
    }
};

// 调整顺序，递归
class Solution2 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res{};
        generate({}, n, n, res);
        return res;
    }
    void generate(string s, int left, int right, vector<string>& result){
        if(left == 0 && right == 0){
            result.push_back(s);
            return;
        }
        if(left > 0) {
            generate(s+"(", left-1, right, result);
        }
        if(left < right) {
            generate(s+")", left, right-1, result);
        }
    }
};
