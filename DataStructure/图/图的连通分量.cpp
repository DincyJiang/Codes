/*
输入
第一行输入一个整数T表示数据组数，1≤T≤10。

每组数据格式为：

第一行包含两个整数N和M，1≤N≤1000，0≤M≤N(N-1)/2；

接下来M行，每行包含两个整数X和Y，表示第X个点和第Y个点之间有一条边，1≤X，Y≤N。

输入形式举例：
1
5 7
1 3
1 5
2 3
2 5
3 4
4 5
3 5
*/
#include <iostream>
#include <vector>

using namespace std;

class graph {
public:
    graph(vector<vector<int>>& G, int V) : G(G), V(V){
        visited = vector<bool>(V, false);
        id = vector<int>(V, -1);
        component_num = 0;
    }
    ~graph() = default;

    int component() {
        for (int i = 0; i < V; ++i)
            if (!visited[i]) {
                dfs(i);
                ++component_num;
            }
        return component_num;
    }
private:
    // 判断两个节点是否连通
    bool isConnected(int v, int w) {
        return id[v] == id[w];
    }

    // 
    void dfs(int v) {
        visited[v] = true;
        id[v] = component_num;
        for (int i = 0; i < V; ++i)
            if (!visited[i])
                dfs(i);
    }
private:
    vector<vector<int>> G; // 邻接表表示的图
    int V; // 图节点的个数
    vector<bool> visited;
    int component_num; //连通分量的数量
    vector<int> id; // 连通的节点具有相同的id值

};

void dfs(const vector<vector<int>>& G, vector<bool>& visited, int v) {
    visited[v] = true;
    for (auto i : G[v])
        if (!visited[G[v][i]])
            dfs(G, visited, i);
}

// V 是节点个数
int component(const vector<vector<int>>& G, int V) {
    vector<bool> visited(V, false);
    int count = 0;
    for (int i = 0; i < V; ++i) { // 遍历所有顶点，i表示当前顶点
        if (!visited[G[i][0]]) {
            dfs(G, visited, G[i][1]);
            ++count;
        }
    }
    return count;
}
int main() {
    int T;
    cin >> T;
    int N, M, X, Y;
    vector<int> comp; // 每一张图的连通分量
    for (int i = 0; i < T; ++i) {
        cin >> N >> M;
        vector<vector<int>> g(N, vector<int>()); // 邻接表表示
        for (int j = 0; j < M; ++j) {
            cin >> X >> Y;
            g[X].push_back(Y);
            g[Y].push_back(X);
        }

        comp.push_back(component(g, N));
    }
    cout << endl;

    for (int i : comp)
        cout << i << endl;

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mp[100][100];
int visit[100];
void dfs(int x,int n)
{
   int i;
   visit[x]=1;
   for(i=1;i<=n;i++)
   {
       if(!visit[i]&&mp[x][i])
       {
          dfs(i,n);
       }
   }
}
int main()
{
    int T,n,m,u,v,i,count;
    scanf("%d",&T);
    while(T--)
    {  count=0;
       scanf("%d%d",&n,&m);
       memset(mp,0,sizeof(mp));
       memset(visit,0,sizeof(visit));
       for(i=0;i<=m-1;i++)
       {
           scanf("%d%d",&u,&v);
           mp[u][v]=mp[v][u]=1;
       }
       for(i=1;i<=n;i++)
       {
           if(!visit[i])
           {
              dfs(i,n);
              count++;//每有一个新的未被标记的点就有了一个新的分支
           }
       }
       printf("%d\n",count);
    }
    return 0;
