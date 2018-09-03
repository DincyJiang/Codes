/*
给定两个字符串 s 和 t，判断它们是否是同构的。

如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。

所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

示例 1:

输入: s = "egg", t = "add"
输出: true
示例 2:

输入: s = "foo", t = "bar"
输出: false
示例 3:

输入: s = "paper", t = "title"
输出: true
说明:
你可以假设 s 和 t 具有相同的长度.
*/

#include <string>
#include <map>
using namespace std;

/*
这道题让我们求同构字符串，就是说原字符串中的每个字符可由另外一个字符替代，可以被其本身替代，
相同的字符一定要被同一个字符替代，且一个字符不能被多个字符替代，即不能出现一对多的映射。
根据一对一映射的特点，我们需要用两个哈希表分别来记录原字符串和目标字符串中字符出现情况，
由于ASCII码只有256个字符，所以我们可以用一个256大小的数组来代替哈希表，并初始化为0，
我们遍历原字符串，分别从源字符串和目标字符串取出一个字符，然后分别在两个哈希表中查找其值，
若不相等，则返回false，若相等，将其值更新为i + 1，因为默认的值是0，所以我们更新值为i + 1，
这样当 i=0 时，则映射为1，如果不加1的话，那么就无法区分是否更新了
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};

class Solution1 {
public:
    bool isIsomorphic(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if (n1 != n2) return false;
        map<char, int> m_s;
        map<char, int> m_t;
        for (int i = 0; i < n1; ++i) {
            if (m_s[s[i]] != m_t[t[i]])
                return false;
            // 要保证两个map中对应位置的值完全相同，要把位置信息记录下来
            m_s[s[i]] = i+1;
            m_t[t[i]] = i+1;
        }
        return true;
    }
};