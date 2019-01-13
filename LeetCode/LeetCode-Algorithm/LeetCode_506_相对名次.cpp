// 给出 N 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌。前三名运动员将会被分别授予 “金牌”，“银牌” 和“ 铜牌”（"Gold Medal", "Silver Medal", "Bronze Medal"）。

// (注：分数越高的选手，排名越靠前。)

// 示例 1:

// 输入: [5, 4, 3, 2, 1]
// 输出: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
// 解释: 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌” ("Gold Medal", "Silver Medal" and "Bronze Medal").
// 余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。
// 提示:

// N 是一个正整数并且不会超过 10000。
// 所有运动员的成绩都不相同。

#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

// 用堆，然后从堆中一个一个取
class Solution1 {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        int count{1}; // 排名
        vector<string> res(n);
        priority_queue<pair<int, int>> heap{}; // 值， 下标
        for (int i{0}; i < n; ++i) {
            heap.push({nums[i], i});
        }
        for (int i{0}; i < n; ++i) {
            int index = heap.top().second;
            heap.pop();
            if (count == 1)
                res[index] = "Gold Medal";
            else if (count == 2)
                res[index] = "Silver Medal";
            else if (count == 3)
                res[index] = "Bronze Medal";
            else
                res[index] = to_string(count);
            ++count;
        }
        return res;
    }
};

// 用map,利用map的自动排序功能，从小到大排序
class Solution2 {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        int count{1};
        vector<string> res(n);
        map<int, int> m;
        for (int i{0}; i < n; ++i) {
            m[nums[i]] = i;
        }
        for (auto ite = m.rbegin(); ite != m.rend(); ++ite) { // 逆序遍历
            if (count == 1)
                res[ite->second] = "Gold Medal";
            else if (count == 2)
                res[ite->second] = "Silver Medal";
            else if (count == 3)
                res[ite->second] = "Bronze Medal";
            else
                res[ite->second] = to_string(count);
            ++count;
        }
        return res;
    }
};

// 利用普通数组,排序的时候比较的不是坐标，而是该坐标位置上的数字
class Solution3 {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        vector<int> index(n);
        vector<string> res(n);
        for (int i{0}; i < n; ++i) {
            index[i] = i;
        }
        // 根据nums中的对应数字对index数组进行排序
        sort(index.begin(), index.end(), [&](int a, int b){return nums[a] > nums[b];});
        for (int i{0}; i < n; ++i) {
            if (i == 0)
                res[index[i]] = "Gold Medal";
            else if (i == 1)
                res[index[i]] = "Silver Medal";
            else if (i == 2)
                res[index[i]] = "Bronze Medal";
            else
                res[index[i]] = to_string(i + 1);
        }
        return res;
    }
};