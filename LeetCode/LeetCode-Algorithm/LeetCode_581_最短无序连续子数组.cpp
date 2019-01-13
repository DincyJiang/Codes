// 给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。

// 你找到的子数组应是最短的，请输出它的长度。

// 示例 1:

// 输入: [2, 6, 4, 8, 10, 9, 15]
// 输出: 5
// 解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
// 说明 :

// 输入的数组长度范围在 [1, 10,000]。
// 输入的数组可能包含重复元素 ，所以升序的意思是<=。

#include <vector>
#include <algorithm>

using namespace std;

// 确定无序数组的起始位置和结束位置
class Solution1 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int res{0};
        int start{-1};
        int n = nums.size();
        for (int i{1}; i < n; ++i) {
            if (nums[i] < nums[i-1]) {
                int j = i;
                while (j > 0 && nums[j] < nums[j-1]) {
                    swap(nums[j], nums[j-1]);
                    --j;
                }
                if (start == -1 || start > j) start = j; // 更新起始位置
                res = i - start + 1;
            }
        }
        return res;
    }
};

// 辅助数组，一摸一样的数组
class Solution2 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int i{0};
        int j = n-1;
        vector<int> vec{nums};
        sort(vec.begin(), vec.end());
        while (i < n && nums[i] == vec[i]) ++i;
        while (j > i && nums[j] == vec[j]) --j;
        return j - i + 1;
    }
};

// 对辅助数组方法的优化
// start是不断往前走的，end是不断往后走的
class Solution3 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start{-1};
        int end{-2};
        int mn = nums[n-1];
        int mx = nums[0];
        for (int i{1}; i < n; ++i) {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[n-1-i]);
            if (mx > nums[i]) end = i;
            if (mn < nums[n-1-i]) start = n-1-i;
        }
        return end - start + 1;
    }
};