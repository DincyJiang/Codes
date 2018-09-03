/*
编写一个算法来判断一个数是不是“快乐数”。

一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，
也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。

示例: 

输入: 19
输出: true
解释: 
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/

#include <set>
using namespace std;

// 我们可以用set来记录所有出现过的数字，然后每出现一个新数字，在set中查找看是否存在，
// 若不存在则加入表中，若存在则跳出循环，并且判断此数是否为1，若为1返回true，不为1返回false
class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while (n != 1) {
            int t = 0; // 平方和
            while (n) {
                t += (n % 10) * (n % 10);
                n /= 10;
            }
            n = t;
            if (s.find(n) != s.end()) break; // 如果集合中出现过这个和
            else s.insert(n);
        }
        return n == 1;
    }
};

// 关于非快乐数有个特点，循环的数字中必定会有4
class Solution1 {
public:
    bool isHappy(int n) {
        while (n != 1 && n != 4) {
            int t = 0;
            while (n) {
                t += (n % 10) * (n % 10);
                n /= 10;
            }
            n = t;
        }
        return n == 1;
    }
};