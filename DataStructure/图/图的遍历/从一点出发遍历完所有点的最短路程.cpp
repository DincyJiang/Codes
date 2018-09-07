/*
图的遍历
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
给定一张包含N个点、N-1条边的无向连通图，节点从1到N编号，每条边的长度均为1。假设你从1号节点出发并打算遍历所有节点，那么总路程至少是多少？

输入
第一行包含一个整数N，1≤N≤105。

接下来N-1行，每行包含两个整数X和Y，表示X号节点和Y号节点之间有一条边，1≤X，Y≤N。

输出
输出总路程的最小值。


样例输入
4
1 2
1 3
3 4
样例输出
4

Hint
按1->2->1->3->4的路线遍历所有节点，总路程为4。
*/


// (n-1)*2-图最大遍历深度
// 一张包含N个点、N-1条边的无向连通图，就说明了图中没有环
// 图就退化成了一棵树，多叉树，用深度优先遍历求出起始点到每一条路径的叶子结点的最短路径，
// 其中最长的只需要走一次，其他的都需要走两次

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAXN 100010
int g[MAXN][100];
int f[MAXN]; // 记录的是每一个节点有几条边
int isv[MAXN]; // 记录的是该节点是否遍历过
int maxn = 0;

// curp是当前的点，curs是到1到当前点的深度
void dfs(int curp,int curs)
{
    int i;
    // 当前节点走过了
    isv[curp] = 1;
    // 当前节点是否全部走过，默认为是
    bool isallv = true;
    for(i=0;i<f[curp];i++){
        if( ! isv[g[curp][i]]){
            // 当前节点的第 i 个子节点没有被走过，那么可以走
            isallv = false;
            dfs(g[curp][i],curs+1);
        }
    }
    if(isallv){
        //当前节点的所有子节点都被走过，那么不能再走了，计算走到这儿的最大深度
        if(curs>maxn)
            maxn = curs;
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        memset(g,0,sizeof(g));
        memset(f,0,sizeof(f));
        memset(isv,0,sizeof(isv));
        for(int i=0;i<n-1;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            g[a][f[a]++] = b; // 无向图，a可以到b，b也可以到a
            g[b][f[b]++] = a;
        }
        dfs(1,0);
        printf("%d\n",(n-1)*2-maxn);
    }
    return 0;
}