/*
幸运ID
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 131072KB；其他语言 655360KB
题目描述：
小C有一张票，这张票的ID是长度为6的字符串，每个字符都是数字，他想让这个ID变成他的辛运ID，所以他就开始更改ID，每一次操作，他可以选择任意一个数字并且替换它。

如果这个ID的前三位数字之和等于后三位数字之和，那么这个ID就是辛运的。你帮小C求一下，最少需要操作几次，能使ID变成辛运ID

输入
输入只有一行，是一个长度为6的字符串。

输出
输出这个最小操作次数

样例输入
000000
样例输出
0

Hint
输入样例2
000018

输出样例2
1

样例解释：将前三位任意一个改为9即可满足条件，操作数为1
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int help(vector<int>& nums1, vector<int>& nums2, int sum1, int sum2) {
    int diff = sum2 - sum1;
    if (diff - nums1[0] <= 9)
        return 1;
    else if (diff - nums1[0] - nums1[1] <= 18)
        return 2;
    else
        return 3;
}

int min_count(string s) {
    vector<int> nums1(3, 0);
    for (int i = 0; i < 3; ++i) {
        stringstream ss;
        ss << s[i];
        ss >> nums1[i];
    }
    sort(nums1.begin(), nums1.end());

    vector<int> nums2(3, 0);
    for (int i = 3; i < 6; ++i) {
        stringstream ss;
        ss << s[i];
        ss >> nums2[i-3];
    }
    sort(nums2.begin(), nums2.end());

    int sum1 = nums1[0] + nums1[1] + nums1[2];
    int sum2 = nums2[0] + nums2[1] + nums2[2];

cout << "sum1  " << sum1 << endl;
cout << "sum2  " << sum2 << endl;

    if (sum1 < sum2) {
        return help(nums1, nums2, sum1, sum2);
    } else if (sum1 > sum2) {
        return help(nums1, nums2, sum2, sum1);
    } else
        return 0;
}

int main() {
    string s = "660099";
    // cin >> s;
    cout << min_count(s);
    return 0;
}

/*
id = input()

first, second = sum(int(i) for i in id[:3]), sum(int(i) for i in id[3:])


diff = second-first
if diff == 0:
    print(0)
else:
    nums = [int(i) for i in id]

    res = 0
    if diff > 0:
        tmp = [9-i for i in nums[:3]] + [i for i in nums[3:]]
        while diff > 0:
            res += 1
            diff -= max(tmp)
            tmp[tmp.index(max(tmp))] = 0
        print(res)
    else:
        tmp = [9-i for i in nums[3:]] + [i for i in nums[:3]]
        while diff < 0:
            res += 1
            diff += max(tmp)
            tmp[tmp.index(max(tmp))] = 0
        print(res)
        */