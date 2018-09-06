/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

输入: [2,4,1], k = 2
输出: 2
解释: 在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
示例 2:

输入: [3,2,6,5,0,3], k = 2
输出: 7
解释: 在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利
*/

#include <vector>
using namespace std;

// 这道题实际上是之前那道 Best Time to Buy and Sell Stock III 买股票的最佳时间之三的一般情况的推广，
// 还是需要用动态规划Dynamic programming来解决，具体思路如下：
// 这里我们需要两个递推公式来分别更新两个变量local和global，我们其实可以求至少k次交易的最大利润。
// 我们定义local[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易在最后一天卖出的最大利润，此为局部最优。
// 然后我们定义global[i][j]为在到达第i天时最多可进行j次交易的最大利润，此为全局最优。它们的递推式为：
// local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff)
// global[i][j] = max(local[i][j], global[i - 1][j])，
// 其中局部最优值是比较前一天并少交易一次的全局最优加上大于0的差值，和前一天的局部最优加上差值后相比，
// 两者之中取较大值，而全局最优比较局部最优和前一天的全局最优。
// 但这道题还有个坑，就是如果k的值远大于prices的天数，比如k是好几百万，而prices的天数就为若干天的话，
// 上面的DP解法就非常的没有效率，应该直接用Best Time to Buy and Sell Stock II 买股票的最佳时间之二的方法来求解，
// 所以实际上这道题是之前的二和三的综合体，代码如下：
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        if (n == 0) return 0;
        if (k >= n) return solveMaxProfit(prices); // 如果给定的交易次数比天数还多，就直接贪心
        vector<int> g(k+1, 0);
        vector<int> l(k+1, 0);
        for (int i = 0; i < n - 1; ++i) {
            int diff = prices[i+1] - prices[i];
            for (int j = k; j >= 1; --j) {
                l[j] = max(g[j-1] + max(diff, 0), l[j] + diff);
                g[j] = max(g[j], l[j]);
            }
        }
        return g[k];
    }
private:
    int solveMaxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < n; ++i)
            if (prices[i] > prices[i-1])
                res += prices[i] - prices[i-1];
        return res;
    }
    int n;
};