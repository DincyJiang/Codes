#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// 计算模式P的部分匹配值，保存在next数组中 
void makeNext(const string& P, vector<int>& next) {
    int m = P.size();
	next[0] = 0; // 首字符的对称值肯定为0  
    // 计算每一个位置的对称值   k记录所有前缀的对称值 
	for (int q = 1, k = 0; q < m; ++q) {
		// k总是用来记录上一个前缀的最大对称值  
		while (k > 0 && P[q] != P[k])
			k = next[k - 1]; //k将循环递减，值得注意的是next[k]<k总是成立  
		if (P[q] == P[k])
			k++; //增加k的唯一方法  
		next[q] = k; //获取最终值  
	}
}

void KMP(const string& T, const string& P, vector<int>& next) {
    int n = T.size();
    int m = P.size();
    makeNext(P, next);
    for (int i = 0, q = 0; i < n; ++i) {
        while (q > 0 && P[q] != T[i])
            q = next[q - 1];
        if (P[q] == T[i])
            ++q;
        if (q == m) {
            cout << "模式文本的偏移为： " << i - m + 1 << endl;
            q = next[q - 1]; // 寻找下一个匹配
        }
    }
}

int main() {
    string T = "xyzababcaxxxababca";  //文本
    string P = "ababca";              //待搜索字符串
    cout <<"文本字符串："<< T << endl;
	cout <<"模式字符串："<< P << endl;
    vector<int> next(P.size(), 0);    //保存待搜索字符串的部分匹配表（所有前缀函数的对称值）
    KMP(T, P, next);
	cout << "模式字符串的前缀函数表："<< endl;
	for (int i = 0; i < P.size(); i++)
		cout<< next[i];
	cout << endl;
	return 0;
}