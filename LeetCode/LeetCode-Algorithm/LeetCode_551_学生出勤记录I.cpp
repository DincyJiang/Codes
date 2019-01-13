// 给定一个字符串来代表一个学生的出勤记录，这个记录仅包含以下三个字符：

// 'A' : Absent，缺勤
// 'L' : Late，迟到
// 'P' : Present，到场
// 如果一个学生的出勤记录中不超过一个'A'(缺勤)并且不超过两个连续的'L'(迟到),那么这个学生会被奖赏。

// 你需要根据这个学生的出勤记录判断他是否会被奖赏。

// 示例 1:

// 输入: "PPALLP"
// 输出: True
// 示例 2:

// 输入: "PPALLL"
// 输出: False

#include <string>

using namespace std;

class Solution1 {
public:
    bool checkRecord(string s) {
        int num_of_A{};
        int num_of_LL{};
        for (char &c : s) {
            if (c == 'A') {
                if (++num_of_A > 1) return false;
                num_of_LL = 0;
            } else if (c == 'L') {
                if (++num_of_LL > 2) return false;
            } else {
                num_of_LL = 0;
            }
        }
        return true;
    }
};

class Solution2 {
public:
    bool checkRecord(string s) {
        return (s.find("A") == string::npos ||     // 找不到字母“A”
                s.find("A") == s.rfind("A")) &&    // 正着找和反着找，字母“A”在同一个位置
                s.find("LLL") == string::npos;     // 找不到字母“LLL”
    }
};