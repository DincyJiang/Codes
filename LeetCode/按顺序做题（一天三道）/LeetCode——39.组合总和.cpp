// 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

// candidates 中的数字可以无限制重复被选取。

// 说明：

// 所有数字（包括 target）都是正整数。
// 解集不能包含重复的组合。 
// 示例 1:

// 输入: candidates = [2,3,6,7], target = 7,
// 所求解集为:
// [
//   [7],
//   [2,2,3]
// ]
// 示例 2:

// 输入: candidates = [2,3,5], target = 8,
// 所求解集为:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]

#include <vector>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        DFS(candidates, target, 0, {}, res);
        return res;
    }
    void DFS(vector<int>& candidates, int target, int start, vector<int> temp, vector<vector<int>>& res) {
        if (target < 0) {
            return;
        } else if (target == 0) {
            res.push_back(temp);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            temp.push_back(candidates[i]);
            DFS(candidates, target - candidates[i], i, temp, res);
            temp.pop_back();
        }
    }
};

/*
我们也可以用迭代的解法来做，建立一个三维数组dp，这里dp[i]表示目标数为i的所有解法集合。
这里的i就从1遍历到target即可，对于每个i，我们都新建一个二维数组cur，然后遍历candidates数组，
如果遍历到的数字大于i，说明当前及之后的数字都无法组成i，直接break掉。
否则如果相等，那么把当前数字自己组成一个数组，并且加到cur中。
否则就遍历dp[i - candidates[j] - 1] 中的所有数组，如果当前数字大于数组的首元素，则跳过，
因为我们的结果要求是要有序的。否则就将当前数字加入数组的开头，并且将数组放入cur之中即可，参见代码如下：
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp;
        sort(candidates.begin(), candidates.end());
        int size = candidates.size();
        for (int i = 1; i <= target; ++i) {
            vector<vector<int>> cur;
            for (int j = 0; j < size; ++j) {
                if (candidates[j] > i) 
                    break;
                else if (candidates[j] == i) {
                    cur.push_back({candidates[j]});
                    continue;
                }
                for (auto a : dp[i - candidates[j] - 1]) {
                    if (candidates[j] > a[0]) continue;
                    a.insert(a.begin(), candidates[j]);
                    cur.push_back(a);
                }
            }
            dp.push_back(cur);
        }
        return dp[target - 1];
    }
};

