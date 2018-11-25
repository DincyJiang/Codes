// 给定一个整数数组，判断是否存在重复元素。

// 如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

// 示例 1:

// 输入: [1,2,3,1]
// 输出: true
// 示例 2:

// 输入: [1,2,3,4]
// 输出: false
// 示例 3:

// 输入: [1,1,1,3,3,4,3,2,4,2]
// 输出: true

#include <vector>
#include <unordered_map>

using namespace std;

// 用哈希表
class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> u_m;
        for (auto &num : nums) {
            if (u_m.find(num) != u_m.end()) return true;
            u_m[num]++;
        }
        return false;
    }
};

// 先将数组排个序，然后再比较相邻两个数字是否相等
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]) return true;
        }
        return false;
    }
};