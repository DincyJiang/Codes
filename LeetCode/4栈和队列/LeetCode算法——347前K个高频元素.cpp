/*
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]
说明：

你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
*/

#include <cassert>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        assert(k > 0);

        // 统计每个元素出现的频率，第一个int是元素，第二个int是频率
        unordered_map<int, int> freq;
        int size = nums.size();
        for (int i = 0; i < size; ++i) 
            freq[nums[i]]++;
        
        assert(k <= freq.size());

        // 扫描freq，维护当前出现频率最高的k个元素
        // 优先级队列中，按照频率排序，所以数据对象是（频率，元素）
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        for (auto iter = freq.begin(); iter != freq.end(); ++iter) {
            if (pq.size() == k) {
                if (iter->second > pq.top().first) {
                    pq.pop();
                    pq.push(make_pair(iter->second, iter->first));
                }
            } else {
                // 如果优先队列还没有到k个
                pq.push(make_pair(iter->second, iter->first));
            }
        }
        
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};