//��Ŀ����
//��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
//����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء� 
//��������{ 3,4,5,1,2 }Ϊ{ 1,2,3,4,5 }��һ����ת�����������СֵΪ1�� 
//NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��


#include<vector>
#include<algorithm>
using namespace std;

//˼·1����ת���������������ת��ʼ�ļ�λ���ֻ��ǵ����ģ�
//��С�����ֽ����������ֺ��棬����������������һ������ƶ���
//�����һ�����ֱ�ǰһ������С����ô��ʱ�ĺ�һ��������ָ��ľ�����С���֡�
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int size = rotateArray.size();
		if (size > 0)
		{
			auto beg = rotateArray.begin();//begָ����Ԫ��
			auto next = ++rotateArray.begin();//nextָ����һ��Ԫ��
			while (*beg <= *next && size >= 1)//size��Ϊ�˿���size
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

//˼·2���������������򣬷�����Ԫ�ؾ�����С������
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

