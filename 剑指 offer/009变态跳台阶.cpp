//��Ŀ����
//һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������

//˼·һ����������F(n)=2*F(n-1),F(1)=1
//ʹ�õݹ�Ľ����ռ���ڴ�̫��
class Solution {
public:
    int jumpFloorII(int number) {
        if(number==1)
            return 1;
        else if(number>1)
        {
            return 2*jumpFloorII(number--);
        }
        return 0;
    }
};

//˼·����ʹ��ѭ��
class Solution {
public:
    int jumpFloorII(int number) {
        if(number==0)
            return number;
        int total=1;
        for(int i=1;i<number;i++)
            total*=2;
        return total;
    }
};

//��̬�ⷨ��2^(number-1)����λ����������һλ���൱�ڳ���2����1����number-1λ
class Solution {
public:
    int jumpFloorII(int number) {
        return  1<<--number;
    }
};

class Solution {
public:
    int jumpFloorII(int number) {
        int result = 1;
        while (--number) {
            result *= 2;
        }
        return result;
    }
};