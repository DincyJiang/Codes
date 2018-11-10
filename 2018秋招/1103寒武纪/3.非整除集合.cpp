/*
描述

给定一个由正整数组成的集合S，找出一个最大的子集合S·，使得S·中任意两个数字的和都不能被K整除。例如S=「10，10，12，19，22，24，25」，K=4。S·的可能取值为「10，19，25」或者「19，22，25」等，S·最多只能取3个数。


输入描述

输入为两行，第一行两个数字，分别表示集合S的元素数量N和K。第二行为N个数字，分别是S的各个元素值。

1<N<1e5
1<K<100
1<S[i]<1e9

输出描述

输出为一个数字，集合S·的最大长度。


样例输入 1 

4 3
1 7 2 4
样例输出 1

3
*/

#include <iostream>
#include <vector>

using namespace std;

// 如果a和b的总和可以被k整除，那么a％k + b％k = k

// AC
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> vec(K); // 哈希
  for (int i = 0; i < N; ++i) {
    int num;
    cin >> num;
    vec[num%K]++;
  }
  
  int res = min(1, vec[0]);
  for (int i = 1; i < (K/2 + 1); ++i) {
    if (i != K-i)
      res += max(vec[i], vec[K-i]);
  }
  
  if (K%2 == 0 && vec[K/2] != 0)
    ++res;
  
  cout << res;
  
  return 0;
}