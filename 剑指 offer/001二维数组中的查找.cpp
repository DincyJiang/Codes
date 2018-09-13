//��Ŀ����
//��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
//�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
#include<vector>
using namespace std;

//���ö�ά�������ϵ��£������ҵ����Ĺ��ɣ�
//��ôѡȡ���Ͻǻ������½ǵ�Ԫ��a[row][col]��target���бȽϣ�
//��targetС��Ԫ��a[row][col]ʱ����ôtarget�ض���Ԫ��a�����е����,
//��col--��
//��target����Ԫ��a[row][col]ʱ����ôtarget�ض���Ԫ��a�����е��±�,
//��row++��
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int m = array.size(); // ����
        int n = array[0].size(); // ����
        if (m ==0 || n == 0) return false;
        int row = 0, col = n - 1; // �����Ͻǿ�ʼ���±�
        while (row < m && col >= 0) {
            int temp = array[row][col];
            if (temp == target)
                return true;
            else if (temp > target)
                --col; // ����
            else
                ++row; // ����
        }
        return false;
    }
};

//��ÿһ�п���������������飬���ö��ֲ��ң�ͨ������ÿһ�еõ��𰸣�
//ʱ�临�Ӷ���nlogn
class Solution1 {
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

class Solution2 {
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