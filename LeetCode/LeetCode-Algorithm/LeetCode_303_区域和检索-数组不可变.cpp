// 给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。

// 示例：

// 给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()

// sumRange(0, 2) -> 1
// sumRange(2, 5) -> -1
// sumRange(0, 5) -> -3
// 说明:

// 你可以假设数组不可变。
// 会多次调用 sumRange 方法。

#include <vector>

using namespace std;

// 建立累计直方图
class NumArray1 {
public:
    NumArray1(vector<int> nums) : sums{nums} {
        int n = nums.size();
        for (int i = 1; i < n; ++i)
            sums[i] += sums[i-1];
    }
    
    int sumRange(int i, int j) {
        return i == 0 ? sums[j] : sums[j] - sums[i - 1];
    }
private:
    vector<int> sums;
};

// 通过增加一位长度，来避免在sumRange中检测i是否为0
class NumArray {
public:
    NumArray(vector<int> nums) : sums{nums} {
        int n = nums.size();
        for (int i = 1; i < n; ++i)
            sums[i] += sums[i-1];
        sums.insert(sums.begin(), 0);
    }
    
    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
private:
    vector<int> sums;
};