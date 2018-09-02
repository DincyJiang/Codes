//��Ŀ����
//����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
//���������ǰ���������������Ľ���ж������ظ������֡�
//��������ǰ���������{ 1,2,4,7,3,5,6,8 }�������������{ 4,7,2,1,5,3,8,6 }�����ؽ������������ء�

#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		int treeSize = pre.size();
		if (treeSize != 0)
		{
			vector<int> left_pre, right_pre, left_vin, right_vin;
			//�������ڵ㣬���ڵ���ǰ������ĵ�һ����  
			TreeNode* tree = new TreeNode(pre[0]);
			//�ҵ�����������ڵ�����λ��,����ڱ���vin_root��  
			int vin_root = 0;
			for (int i = 0; i < treeSize; i++)
			{
				if (vin[i] == pre[0])
				{
					vin_root = i;
					break;
				}
			}
			//����������������ڵ���ߵĽڵ�λ�ڶ���������ߣ����ڵ��ұߵĽڵ�λ�ڶ��������ұ�,����������㣬�Զ������ڵ���й鲢  
			for (int i = 0; i < vin_root; i++)
			{
				left_vin.push_back(vin[i]);
				left_pre.push_back(pre[i + 1]);//ǰ���һ��Ϊ���ڵ�  
			}
			for (int i = vin_root + 1; i < treeSize; i++)
			{
				right_vin.push_back(vin[i]);
				right_pre.push_back(pre[i]);
			}
			//�ݹ飬����������������������ֱ��Ҷ�ڵ�  
			tree->left = reConstructBinaryTree(left_pre, left_vin);
			tree->right = reConstructBinaryTree(right_pre, right_vin);
			return tree;
		}
		return nullptr;
	}
};

class Solution {
public:
    TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty() || vin.empty()) return nullptr;
		TreeNode *tree = new TreeNode(pre[0]);
		int treeSize = pre.size();
		vector<int> left_pre, left_vin, right_pre, right_vin;
		int current_root = 0;
		for (int i = 0; i < treeSize; ++i) {
			if (vin[i] == pre[0]) {
				current_root = i;
				break;
			}
		}
		for (int i = 0; i < current_root; ++i) {
			left_pre.push_back(pre[i + 1]);
			left_vin.push_back(vin[i]);
		}
		for (int i = current_root + 1; i < treeSize; ++i) {
			right_pre.push_back(pre[i]);
			right_vin.push_back(vin[i]);
		}
		tree->left = reConstructBinaryTree(left_pre, left_vin);
		tree->right = reConstructBinaryTree(right_pre, right_vin);
		return tree;
	}
}
