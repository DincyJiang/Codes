// 给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。

// 示例 1:

// 输入: [1,12,-5,-6,50,3], k = 4
// 输出: 12.75
// 解释: 最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
 

// 注意:

// 1 <= k <= n <= 30,000。
// 所给数据范围 [-10,000，10,000]。

#include <vector>
#include <numeric>

using namespace std;

class Solution1 {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums{nums};
        for (int i{1}; i < n; ++i) { // 累加数组
            sums[i] = sums[i-1] + nums[i];
        }
        double mx = sums[k-1];
        for (int i = k; i < n; ++i) {
            mx = max(mx, (double)(sums[i] - sums[i-k]));
        }
        return mx/k;
    }
};

// 滑动窗口，维持k个数字
class Solution2 {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = accumulate(nums.begin(), nums.begin() + k, 0);
        double res = sum;
        int n = nums.size();
        for (int i = k; i < n; ++i) {
            sum += nums[i] - nums[i-k];
            res = max(res, sum);
        }
        return res/k;
    }
};