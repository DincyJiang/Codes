// 给出一个无重叠的 ，按照区间起始端点排序的区间列表。

// 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

// 示例 1:

// 输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
// 输出: [[1,5],[6,9]]
// 示例 2:

// 输入: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// 输出: [[1,2],[3,10],[12,16]]
// 解释: 这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。

#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int n = intervals.size();
        int cur = 0; // 应该插入的位置
        for (int i = 0; i < n; ++i) {
            if (intervals[i].end < newInterval.start) {
                res.push_back(intervals[i]);
                ++cur;
            } else if (intervals[i].start > newInterval.end) {
                res.push_back(intervals[i]);
            } else { // 更新要插入的区间
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
        res.insert(res.begin() + cur, newInterval);
        return res;
    }
};