// 给定两个没有重复元素的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2 中的下一个比其大的值。

// nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出-1。

// 示例 1:

// 输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
// 输出: [-1,3,-1]
// 解释:
//     对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 -1。
//     对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
//     对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1。
// 示例 2:

// 输入: nums1 = [2,4], nums2 = [1,2,3,4].
// 输出: [3,-1]
// 解释:
//     对于num1中的数字2，第二个数组中的下一个较大数字是3。
//     对于num1中的数字4，第二个数组中没有下一个更大的数字，因此输出 -1。
// 注意:

// nums1和nums2中所有元素是唯一的。
// nums1和nums2 的数组大小都不超过1000。

#include <vector>
#include <unordered_map>
#include <stack>

using std::stack;
using std::unordered_map;
using std::vector;

// 暴力搜索
class Solution1 {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int n = findNums.size();
        int m = nums.size();
        vector<int> res(n);
        for (int i{0}; i < n; ++i) {
            int j{0};
            int k{0};
            for (; j < m; ++j) {
                if (nums[j] == findNums[i])
                    break;
            }
            for (k = j + 1; k < m; ++k) {
                if (nums[k] > nums[j]) {
                    res[i] = nums[k];
                    break;
                }
            }
            if (k == m)
                res[i] = -1;
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int m = findNums.size();
        int n = nums.size();
        vector<int> res(m, -1);
        unordered_map<int, int> hash{};
        for (int i{0}; i < n; ++i) // 记录nums中每个元素的下表
            hash[nums[i]] = i;
        for (int i{0}; i < m; ++i) {
            int start = hash[findNums[i]]; // 找到findNums中当前数在nums中的对应位置
            for (int j = start + 1; j < n; ++j) {
                if (nums[j] > findNums[i]) {
                    res[i] = nums[j];
                    break;
                }
            }
        }
        return res;
    }
};

class Solution3 {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res{};
        stack<int> s{};
        unordered_map<int, int> hash{}; // 记录的是nums中当前数字右边比它大的数字
        for (int &num : nums) {
            while (!s.empty() && s.top() < num) {
                hash[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        for (int &num : findNums) {
            res.push_back(hash.count(num) ? hash[num] : -1);
        }
        return res;
    }
};