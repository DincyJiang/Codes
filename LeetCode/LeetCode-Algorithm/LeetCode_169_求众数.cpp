// 给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

// 你可以假设数组是非空的，并且给定的数组总是存在众数。

// 示例 1:

// 输入: [3,2,3]
// 输出: 3
// 示例 2:

// 输入: [2,2,1,1,1,2,2]
// 输出: 2

#include <vector>
#include <unordered_map>

using namespace std;

// 使用hash表，unordered_map底层是哈希表
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> u_m;
        for (auto &num : nums)
            ++u_m[num];
        int n = nums.size();
        for (auto &i : u_m) {
            if (i.second > n / 2)
                return i.first;
        }
        return 0;
    }
};

// 摩尔投票法，先将第一个数字假设为众数，然后把计数器设为1，比较下一个数和此数是否相等，若相等则计数器加一，反之减一。然后看此时计数器的值，若为零，则将下一个值设为候选众数。
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res{0};
        int count{0};
        for (auto &num : nums) {
            if (count == 0) {
                res = num;
                count = 1;
            } else 
                (num == res) ? ++count : --count;
        }
        return res;
    }
};