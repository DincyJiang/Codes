// 题目描述
// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
// 所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

#include <vector>
using namespace std;

// 类似冒泡排序，前偶后奇就交换
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int n = array.size();
        for (int i = 0; i < n; ++i)
            for (int j = n - 1; j > 0; --j)
                if (array[j]%2 == 1 && array[j-1]%2 == 0)
                    swap(array[j], array[j-1]);
    }
};

//思路一：再造两个数组，将元素组中的奇数和偶数分别取出放入新数组
class Solution1 {
public:
    void reOrderArray(vector<int> &array) {
        int n = array.size();
        vector<int> odd;
        vector<int> even;
        for (int i = 0; i < n; ++i) {
            if (array[i]%2 == 1)
                odd.push_back(array[i]);
            else
                even.push_back(array[i]);
        }
        for (int i : even)
            odd.push_back(i);
        array = odd;
    }
};

class Solution2 {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> temp;
        for (auto ite = array.begin(); ite != array.end();) {
            if ((*ite % 2) == 0) {
                temp.push_back(*ite);
                array.erase(ite);
            } else {
                ++ite;
            }
        }
        for (auto ite = temp.begin(); ite != temp.end(); ++ite) {
            array.push_back(*ite);
        }
    }
};