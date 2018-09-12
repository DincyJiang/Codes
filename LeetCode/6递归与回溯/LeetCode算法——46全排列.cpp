/*
给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        res.clear();
        if (nums.size() == 0) return res;
        used = vector<bool>(nums.size(), false);
        vector<int> p;
        generatePermutation(nums, 0, p);
        return res;
    }

private:
    // p中保存了一个有index个元素的排列
    // 向这个排列的末尾添加第index + 1个元素，获得一个有index + 1个元素的排列
    void generatePermutation(const vector<int>& nums, int index, vector<int>& p) {
        if (index == nums.size()) {
            res.push_back(p);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                // 如果nums[i]不在p中，将nums[i]添加在p中
                p.push_back(nums[i]);
                used[i] = true;
                generatePermutation(nums, index + 1, p);
                for (auto i : p)
                    cout << i << ' ';
                cout << endl;
                // 将状态回溯
                p.pop_back();
                used[i] = false;
            }
        }
    }
private:
    vector<vector<int> > res;
    vector<bool> used;
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector<vector<int> > res = s.permute(nums);
    cout << "=================================" << endl;
    for (auto i : res) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

class Solution1 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0) return res;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        help(nums, res, temp, used, 0);
        return res;
    }
private:
    // index表示当前正在处理的元素
    void help(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp, vector<bool>& used, int index) {
        int n = nums.size();
        if (index == n) {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                temp.push_back(nums[i]);
                used[i] = true;
                help(nums, res, temp, used, index+1);
                temp.pop_back();
                used[i] = false;
            }
        }
    }
};