//��Ŀ��
//��ʵ��һ����������һ���ַ����еĿո��滻�ɡ� % 20����
//���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe % 20Are % 20Happy��

//˼·����ԭ�ַ����Ͻ����滻����ǰ����¼�ո���Ŀ���Ӻ���ǰ�滻
class Solution {
public:
	void replaceSpace(char *str, int length) {
		int count = 0;
		for (int i = 0; i < length; i++)//����ո���Ŀcount
		{
			if (str[i] == ' ')
				count++;
		}
		for (int i = length - 1; i >= 0; i--)
		{
			if (str[i] != ' ')
				str[i + 2 * count] = str[i];//�����ǰ���ַ����ǿո񣬾ͽ���ǰ���ַ������2 * count��λ�ã�
			else {            //�����ǰ���ַ��ǿո���ô�ͽ����滻��ͬʱ�ѿո�����һ
				count--;                    
				str[i + 2 * count] = '%';
				str[i + 2 * count + 1] = '2';
				str[i + 2 * count + 2] = '0';
			}
		}
	}
};