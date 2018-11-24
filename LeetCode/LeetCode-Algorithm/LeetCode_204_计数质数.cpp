// 统计所有小于非负整数 n 的质数的数量。

// 示例:

// 输入: 10
// 输出: 4
// 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。

#include <vector>
#include <cmath>

using namespace std;

// 埃拉托斯特尼筛法Sieve of Eratosthenes，从2开始遍历到根号n，先找到第一个质数2，
// 然后将其所有的倍数全部标记出来，然后到下一个质数3，标记其所有倍数，一次类推，直到根号n，
// 此时数组中未被标记的数字就是质数。需要一个n-1长度的bool型数组来记录每个数字是否被标记，
// 长度为n-1的原因是题目说是小于n的质数个数，并不包括n。 
// 然后用两个for循环来实现埃拉托斯特尼筛法，难度并不是很大
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> num(n-1, true);
        num[0] = false;
        int res{0};
        int limit = sqrt(n);
        for (int i = 2; i <= limit; ++i) {
            if (num[i-1]) {
                for (int j = i*i; j < n; j += i) // i的倍数
                    num[j - 1] = false;
            }
        }
        for (int j = 0; j < n - 1; ++j) {
            if (num[j]) ++res;
        }
        return res;
    }
};