/*
给定一个整数数组NUMS，发现指数之间的元素的总和我和Ĵ（我 ≤ Ĵ），包括端值。

的更新（I，val）的函数修改NUMS通过在索引更新元件我到VAL。
例：
鉴于nums = [1,3,5]

sumRange（0，2） - > 9
更新（1，2）
sumRange（0，2） - > 8
注意：
该数组只能由更新函数修改。
您可以假定更新的呼叫数量和sumRange功能均匀分配。
*/

#include<vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums) {
        if (nums.size() == 0){
            return;
        }
        int n = nums.size() * 4;
        for (int i = 0; i < n; ++i){
            _value.push_back(0);
        }
        build_segment_tree(_value, nums, 0, 0, nums.size() - 1);
        _right_end = nums.size() - 1;
    }
    
    void update(int i, int val) {
        update_segment_tree(_value, 0, 0, _right_end, i, val);
    }
    
    int sumRange(int i, int j) {
        return sum_range_segment_tree(_value, 0, 0, _right_end, i ,j);
    }

private:
    void build_segment_tree(std::vector<int>& value, std::vector<int>& nums, 
                            int pos, int left, int right){
        if (left == right){
            value[pos] = nums[left];
            return;
        }
        int mid = (left + right) / 2;
        build_segment_tree(value, nums, pos * 2 + 1, left, mid);
        build_segment_tree(value, nums, pos * 2 + 2, mid + 1, right);
        value[pos] = value[pos * 2 + 1] + value[pos * 2 + 2];
    }
    void print_segment_tree(std::vector<int>& value, 
                            int pos, int left, int right, int layer){
        for (int i = 0; i < layer; ++i){
            printf("---");
        }
        printf("[%d %d][%d] : %d\n", left, right, pos, value[pos]);
        if (left == right){
            return;
        }
        int mid = (left + right) / 2;
        print_segment_tree(value, pos * 2 + 1, left, mid, layer + 1);
        print_segment_tree(value, pos * 2 + 2, mid + 1, right, layer +1);
    }

    int sum_range_segment_tree(std::vector<int>& value, 
                            int pos, int left, int right, 
                            int qleft, int qright){
        if (qleft > right || qright < left){
            return 0;
        }
        if (qleft <= left && qright >= right){
            return value[pos];
        }
        int mid = (left + right) / 2;
        return sum_range_segment_tree(value, pos * 2 + 1, left, mid, qleft, qright) +
            sum_range_segment_tree(value, pos * 2 + 2, mid + 1, right, qleft, qright);
    }

    void update_segment_tree(std::vector<int>& value,
                            int pos, int left, int right,
                            int index, int new_value){
        if (left == right && left == index){
            value[pos] = new_value;
            return;
        }
        int mid = (left + right) / 2;
        if (index <= mid){
            update_segment_tree(value, pos * 2 + 1, left, mid, index, new_value);
        } else {
            update_segment_tree(value, pos * 2 + 2, mid + 1, right, index, new_value);
        }
        value[pos] = value[pos * 2 + 1] + value[pos * 2 + 2];
    }

    std::vector<int> _value;
    int _right_end;
};

