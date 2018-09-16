/*
局长的食物
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 131072KB；其他语言 655360KB
题目描述：
局长有N种食物，每种食物有Ai份。

每天局长会吃一份食物，或者买一份食物（即每天只能进行吃或买其中的一种动作），这样过了M天

现在局长想知道M天后第p种食物的份数排名（从大到小，相同算并列，例如3 3 2，则排名为1 1 3）

N,M,P<=100,Ai<=1000

输入
第一行N M P

第二行N个数Ai

接下来M行，每行A i或者B i分别表示买一份食物i，吃一份食物i

输出
一个答案


样例输入
3 4 2
5 3 1
B 1
A 2
A 2
A 3
样例输出
1
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int N, M, P;
    cin >> N >> M >> P;
    vector<int> A(N+1, 0);
    for (int i = 1; i <= N; ++i)
        cin >> A[i];
    for (int i = 0; i < M; ++i) {
        char c;
        int t;
        cin >> c >> t;
        if (c == 'A')
            ++A[t];
        else if (c == 'B')
            --A[t];
    }
    int P_value = A[P];
    int res = 1;
    sort(A.begin(), A.end());
    set<int> has_show;
    for (int i = N; i >= 1; --i) {
        if (A[i] == P_value)
            break;
        else if (A[i] > P_value) { // 比P_value大的值
            if (has_show.find(A[i]) != has_show.end()) // 如果已经出现过
                continue;
            else {
                // 如果没有出现过，就添加到集合中
                has_show.insert(A[i]);
                ++res;
            }
        }
    }

    cout << res << endl;
    return 0;
}

/*
tmp = input().split()
N, M, P = int(tmp[0]), int(tmp[1]), int(tmp[2])


tmp = input().split()
foods = [int(i) for i in tmp]
# N, M, P = int(tmp[0]), int(tmp[1]), int(tmp[2])
for i in range(M):
    tmp = input().split()
    if tmp[0] == 'B':
        foods[int(tmp[1])-1] -= 1
    else:
        foods[int(tmp[1])-1] += 1

# print(foods)
back_foods = sorted(foods)[::-1]

# print(foods[P-1])
print(back_foods.index(foods[P-1])+1)
*/