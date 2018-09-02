/*
在未排序的数组中找到第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
*/

#include <vector>
#include <algorithm>
using namespace std;

// 先排序后找
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

// 自写快排
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        quickSort(nums, 0, size-1);
        return nums[size - k];
    }
private:
    void quickSort(vector<int>& nums, int l, int r) {
        int i = l, j = r, v = nums[l];
        if (l > r) return;
        while (i < j) {
            while (nums[j] >= v && i < j) --j;
            while (nums[i] <= v && i < j) ++i;
            if (i < j) swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[i]);
        quickSort(nums, l, i - 1);
        quickSort(nums, i + 1, r);
    }
};