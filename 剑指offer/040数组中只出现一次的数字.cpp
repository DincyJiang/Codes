// 题目描述
// 一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。请写程序找出这两个只出现一次的数字。

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;


// 思路：
// 首先：位运算中异或的性质：两个相同数字异或=0，一个数和0异或还是它本身。
// 当只有一个数出现一次时，我们把数组中所有的数，依次异或运算，
// 最后剩下的就是落单的数，因为成对儿出现的都抵消了。
// 依照这个思路，我们来看两个数（我们假设是AB）出现一次的数组。
// 我们首先还是先异或，剩下的数字肯定是A、B异或的结果，这个结果的二进制中的1，表现的是A和B的不同的位。
// 我们就取第一个1所在的位数，假设是第3位，接着把原数组分成两组，分组标准是第3位是否为1。
// 如此，相同的数肯定在一个组，因为相同数字所有位都相同，而不同的数，肯定不在一组。
// 然后把这两个组按照最开始的思路，依次异或，剩余的两个结果就是这两个只出现一次的数字。
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int n = data.size();
        int temp = data[0];
        for (int i = 1; i < n; ++i)
            temp = temp ^ data[i];  // temp是最终剩余的两个不同数字的异或
        // 下面的过程是分开这两个数字
        if (temp == 0) return;
        int index = 0;
        while ((temp & 1) == 0) {
            temp = temp >> 1;
            ++index; // 计算temp中有几个1，也是第一个1所在的位数
        }
        *num1 = *num2 = 0;
        for (int i = 0; i < n; ++i) {
            if (IsBit(data[i], index)) // 判断data[i]的第index位是不是1
                *num1 ^= data[i];
            else
                *num2 ^= data[i];
        }
    }
private:
    bool IsBit(int num, int index) {
        num = num >> index;
        return num & 1;
    }
};

// 用map，统计所有字符出现次数
class Solution1 {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int n = data.size();
        map<int, int> m;
        for (int i = 0; i < n; ++i)
            ++m[data[i]];
        vector<int> num;
        for (int i = 0; i < n; ++i)
            if (m[data[i]] == 1)
                num.push_back(i);
        num1 = &data[num[0]];
        num2 = &data[num[1]];
    }
};

// 用集合，出现过的就删掉，没出现过就插入
class Solution2 {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        set<int> s;
        int n = data.size();
        for (int i = 0; i < n; ++i) {
            if (s.find(data[i]) != s.end())
                s.erase(data[i]);
            else
                s.insert(data[i]);
        }
        vector<int> num;
        for (int i : s)
            num.push_back(i);
        *num1 = num[0];
        *num2 = num[1];
    }
};