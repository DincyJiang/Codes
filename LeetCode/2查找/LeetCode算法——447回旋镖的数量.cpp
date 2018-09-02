/*
给定平面上 n 对不同的点，“回旋镖” 是由点表示的元组 (i, j, k) ，
其中 i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺序）。

找到所有回旋镖的数量。你可以假设 n 最大为 500，所有点的坐标在闭区间 [-10000, 10000] 中。

示例:

输入:
[[0,0],[1,0],[2,0]]

输出:
2

解释:
两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
*/

#include <vector>
#include <unordered_map>
using namespace std;

// 
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        for (auto i = points.begin(); i != points.end(); ++i) {
            // 每一个点都创建一个unordered_map，以距离为键，以相同距离次数为值
            unordered_map<int, int> record;
            for (auto j = points.begin(); j != points.end(); ++j) {
                if (i != j)
                    record[dis(*i, *j)] ++;
            }
            for (auto ite = record.begin(); ite != record.end(); ++ite) {
                if (ite->second >= 2)
                    res += (ite->second) * (ite->second - 1);
            }
        }
        return res;
    }
private:
    // 计算距离不用开根号，防止浮点数问题，就使用整型
    int dis(pair<int, int>& pa, pair<int, int>& pb) {
        return (pa.first - pb.first) * (pa.first - pb.first) +
               (pa.second - pb.second) * (pa.second - pb.second);
    }
};