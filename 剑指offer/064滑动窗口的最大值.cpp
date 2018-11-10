// 题目描述
// 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
// 例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
// 那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}；
// 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
// {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， 
// {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。


#include <iostream>
#include <vector>
#include <deque>
using namespace std;


// 思路：暴力搜索
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> max;
        int vec_num = num.size();
        if (num.empty() || size > num.size() || size < 1) return max;
        int m = 0; 
        for (int i = 0; i < vec_num - size + 1; ++i) {
            m = num[i];
            for (int j = i + 1; j < i + size; ++j) {
                if (num[j] > m) {
                    m = num[j];
                }
            }
            max.push_back(m);
        }
        return max;
    }
};

//时间复杂度o（n），空间复杂度为o（n）
/*思路就是采用双端队列，队列中的头节点保存的数据比后面的要大。
    比如当前假如的数据比队尾的数字大，说明当前这个数字最起码在从现在起到后面的过程中可能是最大值
    ，而之前队尾的数字不可能最大了，所以要删除队尾元素。
    此外，还要判断队头的元素是否超过size长度，由于存储的是下标，所以可以计算得到；
    特别说明，我们在双端队列中保存的数字是传入的向量的下标；
*/
class Solution1 {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> res;
        int n = num.size();
        if (n < size || size < 1 || n < 1) return res;
        deque<int> dq;
        // 处理前size个元素
        for (int i = 0; i < size; ++i) {
            while (!dq.empty() && num[i] >= num[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        // 处理之后的元素
        for (int i = size; i < n; ++i) {
            res.push_back(num[dq.front()]);
            while (!dq.empty() && num[i] >= num[dq.back()])
                dq.pop_back();
            // 判断队列首的元素是否超出范围
            if (!dq.empty() && dq.front() <= i - size)
                dq.pop_front();
            dq.push_back(i);
        }
        res.push_back(num[dq.front()]);
        return res;
    }
};