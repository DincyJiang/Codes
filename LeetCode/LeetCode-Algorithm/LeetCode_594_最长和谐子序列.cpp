// 和谐数组是指一个数组里元素的最大值和最小值之间的差别正好是1。

// 现在，给定一个整数数组，你需要在所有可能的子序列中找到最长的和谐子序列的长度。

// 示例 1:

// 输入: [1,3,2,2,5,2,3,7]
// 输出: 5
// 原因: 最长的和谐数组是：[3,2,2,2,3].
// 说明: 输入的数组长度最大不超过20,000.

#include <vector>
#include <map>

using namespace std;

// 找到相差为1的数字的个数
// 利用map的自动排序功能
class Solution1 {
public:
    int findLHS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res{0};
        map<int, int> m{};
        for (int &num : nums)
            ++m[num];
        for (auto ite = next(m.begin()); ite != m.end(); ++ite) {
            auto pre = prev(ite);
            if (ite->first == pre->first + 1) {
                res = max(res, ite->second + pre->second);
            }
        }
        return res;
    }
};

// 直接在map中寻找相差1的数即可
class Solution2 {
public:
    int findLHS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res{0};
        map<int, int> m{};
        for (int &num : nums)
            ++m[num];
        for (auto &a : m) {
            if (m.count(a.first + 1))
                res = max(res, m[a.first] + m[a.first+1]);
        }
        return res;
    }
};