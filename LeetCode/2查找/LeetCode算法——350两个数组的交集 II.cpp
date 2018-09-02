/*
给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2,2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [4,9]
说明：

   输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
   我们可以不考虑输出结果的顺序。
*/

#include <vector>
#include <map>
using namespace std;

// map
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> record;
        for (auto i = nums1.begin(); i != nums1.end(); ++i) {
            record[*i]++;
        }
        vector<int> res;
        for (auto i = nums2.begin(); i != nums2.end(); ++i) {
            if (record[*i] > 0) {
                res.push_back(*i);
                record[*i]--;
            }
        }
        return res;
    }
};
