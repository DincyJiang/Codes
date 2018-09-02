// 题目描述
// 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
// 为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
// ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。

#include<iostream>
using namespace std;


//思路一：遍历，数出每个数中包含的1的个数,时间复杂度太高，O(nlogn)
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n<=0) return 0;
        int result;
        int temp;
        for(int i=1;i<=n;++i){
            temp=i;
            while(temp){
                if(temp%10==1) ++result;;           
                temp/=10;
            }
        }
        return result;
    }
};

//思路二：参考网址：http://www.cnblogs.com/cyjb/p/digitOccurrenceInRegion.html
// 当计算右数第 i 位包含的 X 的个数时：
// 取第 i 位左边（高位）的数字，乘以 10i−1，得到基础值 a。
// 取第 i 位数字，计算修正值：
// 如果大于 X，则结果为 a+10i−1。
// 如果小于 X，则结果为 a。
// 如果等 X，则取第 i 位右边（低位）数字，设为 b，最后结果为 a+b+1。
// 相应的代码非常简单，效率也非常高，时间复杂度只有 O(log10n)。

// 当 X = 0 时，规律与上面给出的规律不同，需要另行考虑。
// 最主要的区别是，最高位中永远是不会包含 0 的，因此，从个位累加到左起第二位就要结束，
// 需要将上面代码中 for 循环的判断条件改为 k / 10 != 0。
// 其次是，第 i 位的基础值不是高位数字乘以 10i−1，而是乘以 10i−1−1。以 1 至 102 为例，
// 千位中实际包含 3 个 0，但这三个 0 是来自于个位 2 计算得到的修正值，而非来自于基础值。
// 千位的基础值是 0，因为不存在数字 01, 02, 03, ..., 09，即数字前是没有前导 0 的。
// 解决办法就是将上面代码中第 6 行改为 cnt += (k / 10 - 1) * i。
class Solution1 {
public:
    int count(int n, int x) {
        int cnt = 0, k;
        for (int i = 1;k = n / i;i *= 10) {
            // 高位的数字。
            int high = k / 10;
            if (x == 0) {
                if (high) {
                    high--;
                } else {
                    break;
                }
            }
            cnt += high * i;
            // 当前位的数字。
            int cur = k % 10;
            if (cur > x) {
                cnt += i;
            } else if (cur == x) {
                // n - k * i 为低位的数字。
                cnt += n - k * i + 1;
            }
        }
        return cnt;
    }
    int NumberOf1Between1AndN_Solution(int n)
    {
        int result=count(n,1);
        return result;
    }
};

//思路三：公式，想不出来
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n<=0) return 0;
        int result = 0;
        for (long long m = 1; m <= n; m *= 10) {
            result += (n / m + 8) / 10 * m + (n / m % 10 == 1) * (n % m + 1);
        }
        return result;
    }
};