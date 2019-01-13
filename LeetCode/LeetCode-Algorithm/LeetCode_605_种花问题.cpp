// 假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。

// 给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。

// 示例 1:

// 输入: flowerbed = [1,0,0,0,1], n = 1
// 输出: True
// 示例 2:

// 输入: flowerbed = [1,0,0,0,1], n = 2
// 输出: False
// 注意:

// 数组内已种好的花不会违反种植规则。
// 输入的数组长度范围为 [1, 20000]。
// n 是非负整数，且不会超过输入数组的大小。

#include <vector>

using namespace std;

// 首尾如果是0，分别在两头添加0
// 计算连续0的个数
class Solution1 {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.empty()) return false;
        if (flowerbed[0] == 0) flowerbed.insert(flowerbed.begin(), 0);
        if (flowerbed.back() == 0) flowerbed.push_back(0);
        int len = flowerbed.size();
        int count{0}; // 连续0的个数
        int sum{0}; // 可摆放的花的总数
        for (int i{0}; i <= len; ++i) {
            if (i < len && flowerbed[i] == 0)
                ++count;
            else {
                sum += (count - 1) / 2;
                count = 0;
            }
        }
        return sum >= n;
    }
};

// 直接在原数组上修改
class Solution2 {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        for (int i{0}; i < len; ++i) {
            if (n == 0) return true;
            if (flowerbed[i] == 0) {
                int next = (i == len-1 ? 0 : flowerbed[i+1]);
                int pre = (i == 0 ? 0 : flowerbed[i-1]);
                if (next + pre == 0) { // 前一个和后一个都是0
                    flowerbed[i] = 1;
                    --n;
                }
            }
        }
        return n <= 0;
    }
};