#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printNums(const vector<int>& nums) {
    for (auto &num : nums)
        cout << num << ' ';
    cout << endl;
}

void bubble_sort(vector<int>& nums) {
    int n = nums.size();
    for (int i = n - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] > nums[j+1]) {
                swap(nums[j], nums[j+1]);
            }
        }
    }
}

void select_sort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[min_index]) {
                min_index = j;
            }
        }
        swap(nums[i], nums[min_index]);
    }
}

void insert_sort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
        int cur = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > cur) {
            nums[j+1] = nums[j];
            --j;
        }
        nums[j+1] = cur;
    }
}

void merge_sort(vector<int>& nums) {

}

void quick_sort(vector<int>& nums, int l, int r) {
    int i = l, j = r, pivot = nums[l];
    if (l > r) return;
    while (i < j) {
        while (nums[j] >= pivot && i < j) --j;
        while (nums[i] <= pivot && i < j) ++i;
        if (i < j)
            swap(nums[i], nums[j]);
    }
    swap(nums[l], nums[i]);
    quick_sort(nums, l, i-1);
    quick_sort(nums, i+1, r);
}

void quick_sort(vector<int>& nums) {
    int n = nums.size();
    quick_sort(nums, 0, n - 1);
}

int main() {
    vector<int> nums = {1,9,2,8,3,7,4,6,5};
    printNums(nums);

    // bubble_sort(nums);
    // printNums(nums);

    // select_sort(nums);
    // printNums(nums);

    // insert_sort(nums);
    // printNums(nums);

    quick_sort(nums);
    printNums(nums);


    return 0;
}