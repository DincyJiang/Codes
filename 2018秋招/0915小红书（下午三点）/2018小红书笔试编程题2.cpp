/*
求表达式的末尾有几个连续的0
f(n) = 1! * 2! * 3! * ... * n!
*/

#include <iostream>
using namespace std;

// 两个数相乘尾数0的个数其实就是依赖于2和5因子的个数。
// 又因为每两个连续数字就会有一个因子2，个数非常充足，
// 所以此时只需要关心5因子的个数就行了
int cal(int n) {
	if(n<5) 
        return 0;
	else
		return n/5 + cal(n/5);
}

int main() {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res += cal(i);
    }
    cout << res << endl;

    return 0;
}