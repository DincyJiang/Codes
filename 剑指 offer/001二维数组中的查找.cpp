//题目描述
//在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
#include<vector>
using namespace std;

//利用二维数组由上到下，由左到右递增的规律，
//那么选取右上角或者左下角的元素a[row][col]与target进行比较，
//当target小于元素a[row][col]时，那么target必定在元素a所在行的左边,
//即col--；
//当target大于元素a[row][col]时，那么target必定在元素a所在列的下边,
//即row++；
class Solution {
public:
	bool Find(int target, vector<vector<int>> array) {
		if (array.size() != 0)
		{
			int row = 0;
			int col = array[0].size() - 1;
			while (row < array.size() && col >= 0)
			{
				if (array[row][col] == target)
					return true;
				else if (array[row][col] > target)
					--col;
				else
					++row;
			}
		}
		return false;
	}
}; 

//把每一行看成有序递增的数组，利用二分查找，通过遍历每一行得到答案，
//时间复杂度是nlogn
class Solution {
public:
	bool Find(int target, vector<vector<int>> array) {
		for (int i = 0; i<array.size(); i++) {
			int low = 0;
			int high = array[i].size() - 1;
			while (low <= high) {
				int mid = (low + high) / 2;
				if (target>array[i][mid])
					low = mid + 1;
				else if (target<array[i][mid])
					high = mid - 1;
				else
					return true;
			}
		}
		return false;
	}
};

class Solution {
public:
	bool Find(int target, vector<vector<int> > array)
    {
        int row = array.size();
        int col = array[0].size();
        for (int i = row - 1, j = 0; i >= 0 && j < col;) {
            if (target == array[i][j]) {
                return true;
            } else if (target < array[i][j]) {
                --i;
                continue;
            } else if (target > array[i][j]) {
                ++j;
                continue;
            }
        }
        return false;
    }
};