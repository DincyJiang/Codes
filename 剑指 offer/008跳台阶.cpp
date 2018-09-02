//��Ŀ����
//һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж�����������

//˼·һ��
// a.�������������1�׻���2�ף���ô�ٶ���һ��������һ�ף���ôʣ�µ���n-1��̨�ף�������f(n-1);
// b.�ٶ���һ��������2�ף���ôʣ�µ���n-2��̨�ף�������f(n-2)
// c.��a��b������Եó�������Ϊ: f(n) = f(n-1) + f(n-2) 
// d.Ȼ��ͨ��ʵ�ʵ�������Եó���ֻ��һ�׵�ʱ�� f(1) = 1 ,ֻ�����׵�ʱ������� f(2) = 2
// e.���Է������յó�����һ��쳲��������У�
class Solution {
public:
    int jumpFloor(int number) {
        if (number <= 0) 
            return -1;
        else if (number == 1) 
            return 1;
        else if (number ==2) 
            return 2;
        else
            return  jumpFloor(number-1)+jumpFloor(number-2);
    }
};

//˼·������̬�滮��
class Solution {
public:
    int jumpFloor(int n) {
        if(n>=1)
        {
            int f = 0, g = 1;
            while(n--) {
            g += f; //g����һ�����g����һ�����f֮��
            f = g - f;//f������һ�����g
            }
            return g;
        }
        return 0;
    }
};