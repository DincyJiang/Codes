// 给定两个字符串 A 和 B, 寻找重复叠加字符串A的最小次数，使得字符串B成为叠加后的字符串A的子串，如果不存在则返回 -1。

// 举个例子，A = "abcd"，B = "cdabcdab"。

// 答案为 3， 因为 A 重复叠加三遍后为 “abcdabcdabcd”，此时 B 是其子串；A 重复叠加两遍后为"abcdabcd"，B 并不是其子串。

// 注意:

//  A 与 B 字符串的长度在1和10000区间范围内。

#include <string>

using namespace std;

class Solution1 {
public:
    int repeatedStringMatch(string A, string B) {
        int n1 = A.size();
        int n2 = B.size();
        int count{1}; // s中字符串A的个数
        string s{A};
        while (s.size() < n2) {
            s += A;
            ++count;
        }
        if (s.find(B) != string::npos) return count;
        s += A; // 如果不是子串，就在加一个A
        return (s.find(B) != string::npos) ? count + 1 : -1; // 如果还不是子串，就返回-1
    }
};

// 算出最多需要的A字符串个数，就是B.size()/A.size() + 2
class Solution2 {
public:
    int repeatedStringMatch(string A, string B) {
        int n1 = A.size();
        int n2 = B.size();
        string s{A};
        for (int i{1}; i <= n2/n1+2; ++i) {
            if (s.find(B) != string::npos) return i;
            s += A;
        }
        return -1;
    }
};

// 不用find函数，逐个字符比较
class Solution3 {
public:
    int repeatedStringMatch(string A, string B) {
        int n1 = A.size();
        int n2 = B.size();
        for (int i{0}; i < n1; ++i) {
            int j{0};
            while (j < n2 && A[(i+j) % n1] == B[j]) ++j;
            if (j == n2) return (i+j-1)/n1+1;
        }
        return -1;
    }
};