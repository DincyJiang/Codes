//题目描述
//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
//例如数组{ 3,4,5,1,2 }为{ 1,2,3,4,5 }的一个旋转，该数组的最小值为1。 
//NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。


#include<vector>
#include<algorithm>
using namespace std;

//思路1：旋转数组递增，经过旋转后开始的几位数字还是递增的，
//最小的数字接在最大的数字后面，利用两个迭代器，一起向后移动，
//如果后一个数字比前一个数字小，那么此时的后一个迭代器指向的就是最小数字。
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int size = rotateArray.size();
		if (size > 0)
		{
			auto beg = rotateArray.begin();//beg指向首元素
			auto next = ++rotateArray.begin();//next指向下一个元素
			while (*beg <= *next && size >= 1)//size是为了控制size
			{
				++beg;
				++next;
				--size;
			}
			return *next;
		}
		return 0;
	}
};

//思路2：将数组重新排序，返回首元素就是最小的数字
#include<vector>  
#include<algorithm>  
using namespace std;
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		sort(rotateArray.begin(), rotateArray.end());
		return rotateArray[0];
	}
};

