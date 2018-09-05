/*
给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每次交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。

示例 1:

输入: prices = [1, 3, 2, 8, 4, 9], fee = 2
输出: 8
解释: 能够达到的最大利润:  
在此处买入 prices[0] = 1
在此处卖出 prices[3] = 8
在此处买入 prices[4] = 4
在此处卖出 prices[5] = 9
总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
注意:

0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// 贪心选择的关键是找到一个最大后是不是能够卖掉stock，重新开始寻找买入机会。
// 比如序列1 3 2 8，如果发现2小于3就完成交易买1卖3，
// 此时由于fee=2，（3-1-fee）+(8-2-fee)<(8-1-fee)，所以说明卖早了，
// 令max是当前最大price，当（max-price[i]>=fee）时可以在max处卖出，
// 且不会存在卖早的情况，再从i开始重新寻找买入机会。
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0;
        int profit = 0;
        int curProfit = 0; // 这一次卖出的利润
        int cur_min = prices[0];
        int cur_max = prices[0];
        for (int i = 1; i < n; ++i) {
            cur_min = min(cur_min, prices[i]);
            cur_max = max(cur_max, prices[i]);
            curProfit = max(curProfit, prices[i] - cur_min - fee);
            if ((cur_max - prices[i]) >= fee) { // 这时候在最顶峰卖就不会亏
                profit += curProfit;
                curProfit = 0;
                cur_min = prices[i];
                cur_max = prices[i];
            }
        }
        return profit + curProfit;
    }
};


// 动态规划解法， 状态转移方程不太好理解
// 用两个一维数组就可以了，sold[i]表示第i天卖掉股票此时的最大利润，
// hold[i]表示第i天保留手里的股票此时的最大利润。
// 那么我们来分析递推公式，在第i天，如果我们要卖掉手中的股票，
// 那么此时我们的总利润应该是前一天手里有股票的利润(不然没股票卖毛啊)，
// 加上此时的卖出价格，减去交易费得到的利润总值，跟前一天卖出的利润相比，
// 取其中较大值，如果前一天卖出的利润较大，那么我们就前一天卖了，不留到今天了。
// 然后来看如果第i天不卖的利润，就是昨天股票卖了的利润然后今天再买入股票，
// 得减去今天的价格，得到的值和昨天股票保留时的利润相比，取其中的较大值，
// 如果昨天保留股票的利润大，那么我们就继续保留到今天，所以递推时可以得到：
// sold[i] = max(sold[i - 1], hold[i - 1] + prices[i] - fee);
// hold[i] = max(hold[i - 1], sold[i - 1] - prices[i]);
class Solution1 {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> sold(prices.size(), 0), hold = sold;
        hold[0] = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            sold[i] = max(sold[i - 1], hold[i - 1] + prices[i] - fee);
            hold[i] = max(hold[i - 1], sold[i - 1] - prices[i]);
        }
        return sold.back();
    }
};

// 我们发现不管是卖出还是保留，第i天到利润只跟第i-1天有关系，
// 所以我们可以优化空间，用两个变量来表示当前的卖出和保留的利润，
// 更新方法和上面的基本相同，就是开始要保存sold的值，不然sold先更新后，
// 再更新hold时就没能使用更新前的值了

class Solution2 {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sold = 0, hold = -prices[0];
        for (int price : prices) {
            int t = sold;
            sold = max(sold, hold + price - fee);
            hold = max(hold, t - price);
        }
        return sold;
    }
};