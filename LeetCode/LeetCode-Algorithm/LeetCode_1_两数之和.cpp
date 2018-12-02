// 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的 两个 整数。

// 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

// 示例:

// 给定 nums = [2, 7, 11, 15], target = 9

// 因为 nums[0] + nums[1] = 2 + 7 = 9
// 所以返回 [0, 1]

#include <vector>
#include <unordered_map>

using namespace std;

// 双重循环，暴力搜索
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sz = nums.size();
        for (int i{0}; i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                if (nums[i] + nums[j] == target)
                    return vector<int>{i, j};
            }
        }        
        return {};
    }
};

// 哈希表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash{};
        int sz = nums.size();
        for (int i{0}; i < sz; ++i) {
            if (hash.count(target - nums[i])) {
                return vector<int>{i, hash[target - nums[i]]};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};