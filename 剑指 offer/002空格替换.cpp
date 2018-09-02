//题目：
//请实现一个函数，将一个字符串中的空格替换成“ % 20”。
//例如，当字符串为We Are Happy.则经过替换之后的字符串为We % 20Are % 20Happy。

//思路：在原字符串上进行替换，从前向后记录空格数目，从后向前替换
class Solution {
public:
	void replaceSpace(char *str, int length) {
		int count = 0;
		for (int i = 0; i < length; i++)//计算空格数目count
		{
			if (str[i] == ' ')
				count++;
		}
		for (int i = length - 1; i >= 0; i--)
		{
			if (str[i] != ' ')
				str[i + 2 * count] = str[i];//如果当前的字符不是空格，就将当前的字符向后移2 * count个位置，
			else {            //如果当前的字符是空格，那么就进行替换，同时把空格数减一
				count--;                    
				str[i + 2 * count] = '%';
				str[i + 2 * count + 1] = '2';
				str[i + 2 * count + 2] = '0';
			}
		}
	}
};