//题目描述
//我们可以用2 * 1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2 * 1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

//思路：还是斐波那契数列的问题
class Solution {
public:
	int rectCover(int number) {
                if(number>=1)
        {
            int f = 0, g = 1;
            while(number--) {
                g += f; //g是上一步骤的g和上一步骤的f之和
                f = g - f;//f就是上一步骤的g
            }
            return g;
        }
        return 0;
    }
	}
};