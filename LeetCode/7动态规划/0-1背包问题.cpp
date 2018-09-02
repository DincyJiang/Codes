/*
背包容量为C， 有n种不同的物品，编号为0,1,2...n-1
每一件物品的重量为w[i]，价值为v[i]
现在向这个背包中放物品，使得放入的总价值最大
*/

/*
思路：
暴力解法：每一件物品都可以选择放或不放  O(2^n*n)
贪心解法：优先放入平均价值最高的， 不行
动态规划是正解
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;


// 时间复杂度 O(n*C)
// 空间复杂度 O(n*C)
class Solution {
public:
    int knapsack01(const vector<int>& w, const vector<int>& v, int C) {
        assert(w.size() == v.size() && C >= 0);
        int n = w.size();
        if (n == 0 || C == 0) return 0;
        vector<vector<int>> memo(n, vector<int>(C+1, -1));
        for (int j = 0; j <=C; ++j)
            memo[0][j] = (j >= w[0] ? v[0] : 0);
        
        for (int i = 1; i < n; ++i)
            for (int j = 0; j <= C; ++j) {
                // 考虑0..i的物品，且容量为j的物品
                // 两种比较：1：不考虑i这个物品，memo[i-1][j]
                memo[i][j] = memo[i-1][j];
                // 确保i这个物品能放进容量j中
                if (j >= w[i])
                    memo[i][j] = max(memo[i][j], v[i] + memo[i-1][j-w[i]]);
            }
        return memo[n-1][C];
    }
};

// 优化：只用两行来保存
// 时间复杂度 O(n*C)
// 空间复杂度 O(2*C) = O(C)
class Solution {
public:
    int knapsack01(const vector<int>& w, const vector<int>& v, int C) {
        assert(w.size() == v.size() && C >= 0);
        int n = w.size();
        if (n == 0 || C == 0) return 0;
        vector<vector<int>> memo(2, vector<int>(C+1, -1));
        for (int j = 0; j <=C; ++j)
            memo[0][j] = (j >= w[0] ? v[0] : 0);
        
        for (int i = 1; i < n; ++i)
            for (int j = 0; j <= C; ++j) {
                // 考虑0..i的物品，且容量为j的物品
                // 两种比较：1：不考虑i这个物品，memo[i-1][j]
                memo[i%2][j] = memo[(i-1)%2][j];
                // 确保i这个物品能放进容量j中
                if (j >= w[i])
                    memo[i%2][j] = max(memo[i%2][j], v[i] + memo[(i-1)%2][j-w[i]]);
            }
        return memo[(n-1)%2][C];
    }
};


// 优化：只用一行来保存
// 时间复杂度 O(n*C)
// 空间复杂度 O(2*C) = O(C)
class Solution {
public:
    int knapsack01(const vector<int>& w, const vector<int>& v, int C) {
        assert(w.size() == v.size() && C >= 0);
        int n = w.size();
        if (n == 0 || C == 0) return 0;
        vector<int> memo(C+1, -1);

        for (int j = 0; j <=C; ++j)
            memo[j] = (j >= w[0] ? v[0] : 0);
        
        for (int i = 1; i < n; ++i)
            for (int j = C; j >= w[i]; --j) 
                memo[j] = max(memo[j], v[i] + memo[j-w[i]]);
        return memo[C];
    }
};