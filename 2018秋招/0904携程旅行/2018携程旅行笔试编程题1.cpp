/*
输入一个long类型的数值，求该数值的二进制表示中的1的个数
*/
// 剑指offer——11题
#include <iostream>
using namespace std;

int  NumberOf1(long n) {
    int count=0;
    while(n) {
        ++count;
        n &= (n-1);
    }
    return count;
}

int main() {
    long a;
    cin >> a;
    int res = NumberOf1(a);
    
    cout << res << endl;
    return 0;
}

