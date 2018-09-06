/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

输入: [3,3,5,0,0,3,1,4]
输出: 6
解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
示例 2:

输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。   
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
示例 3:

输入: [7,6,4,3,1] 
输出: 0 
解释: 在这个情况下, 没有交易完成, 所以最大利润为 0。
*/

#include <vector>
using namespace std;

// 动态规划
// 我们需要两个递推公式来分别更新两个变量local和global，
// 我们其实可以求至少k次交易的最大利润，找到通解后可以设定 k = 2，即为本题的解答。
// 我们定义local[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易在最后一天卖出的最大利润，此为局部最优。
// 然后我们定义global[i][j]为在到达第i天时最多可进行j次交易的最大利润，此为全局最优。
// 它们的递推式为：
// local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff)
// global[i][j] = max(local[i][j], global[i - 1][j])
// 其中局部最优值是比较前一天并少交易一次的全局最优加上大于0的差值，和前一天的局部最优加上差值中取较大值，
// 而全局最优比较局部最优和前一天的全局最优。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<int>> global(n, vector<int>(3, 0));
        vector<vector<int>> local(n, vector<int>(3, 0));
        for (int i = 1; i < n; ++i) {
            int diff = prices[i] - prices[i-1];
            for (int j = 1; j <= 2; ++j) {
                local[i][j] = max(global[i-1][j-1] + max(diff, 0), local[i-1][j] + diff);
                global[i][j] = max(local[i][j], global[i-1][j]);
            }
        }
        return global[n-1][2];
    }
};

// 下面这种解法用一维数组来代替二维数组，可以极大的节省了空间，
// 由于覆盖的顺序关系，我们需要j从2到1，这样可以取到正确的g[j-1]值，而非已经被覆盖过的值，参见代码如下：
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<int> global(3, 0);
        vector<int> local(3, 0);
        for (int i = 0; i < n - 1; ++i) {
            int diff = prices[i+1] - prices[i];
            for (int j = 2; j >= 1; --j) {
                local[j] = max(global[j-1] + max(diff, 0), local[j] + diff);
                global[j] = max(local[j], global[j]);
            }
        }
        return global[2];
    }
};
