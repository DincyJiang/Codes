/*
完全多部图
时间限制：C/C++语言 2000MS；其他语言 4000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
给定一张包含N个点、M条边的无向图，每条边连接两个不同的点，且任意两点间最多只有一条边。对于这样的简单无向图，如果能将所有点划分成若干个集合，使得任意两个同一集合内的点之间没有边相连，任意两个不同集合内的点之间有边相连，则称该图为完全多部图。现在你需要判断给定的图是否为完全多部图。

输入
第一行输入一个整数T表示数据组数，1≤T≤10。

每组数据格式为：

第一行包含两个整数N和M，1≤N≤1000，0≤M≤N(N-1)/2；

接下来M行，每行包含两个整数X和Y，表示第X个点和第Y个点之间有一条边，1≤X，Y≤N。

输出
每组输出占一行，如果给定的图为完全多部图，输出Yes，否则输出No。


样例输入
2
5 7
1 3
1 5
2 3
2 5
3 4
4 5
3 5
4 3
1 2
2 3
3 4
样例输出
Yes
No


*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


#include <iostream>
#include <vector>

using namespace std;

void dfs(int i, const vector<vector<int>>& g, vector<bool>& visited) {
    visited[i] = true;
    for (int j = 0; j < g[i].size(); ++j)
        if (!visited[i])
            dfs(i, g, visited);
}
         
bool judge(const vector<vector<int>>& g, vector<bool>& visited) {
    int n = g.size();
    int res = 0;
    for (int i = 0; i < n; ++i) {
    	if (!visited[i]) {
        	dfs(i, g, visited);
            ++res;
        }
    }
    return res > 1 ? true : false;
}

int main () {
    int T;
    cin >> T;
    int N, M, X, Y;
    for (int i = 0; i < T; ++i) {
        cin >> N >> M;
        vector<vector<int>> g(N, vector<int>()); // 邻接表表示
        for (int j = 0; j < M; ++j) {
            cin >> X >> Y;
            g[X].push_back(Y);
            g[Y].push_back(X);
        }
        vector<bool> visited(N, false);
        cout << ((judge(g, visited)) ? "Yes" : "No") << endl;
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int findunlink(vector<int>& table,int n) {
    for(int i=0;i<table.size();i++)
        if(table[i]!=i+1) {
            return i+1;
        }
    return table.size()+1;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        vector<int> s(m),t(m);
        vector<set<int> > groups;
        for(int i=0;i<m;i++)
            cin>>s[i]>>t[i];
        bool res = true;
        for(int i=1;i<=n;i++) {
            vector<int> link;
            int unlink = 0;
            for(int j=0;j<m;j++) {
                if(t[j]==i)
                    link.push_back(s[j]);
                if(s[j]>i)
                    break;
            }
            if(link.size()==i-1) {//all n-1 is link,new set 
                set<int> a;
                a.insert(i);
                groups.push_back(a);
            }
            else if(link.size()<i-1) {
                unlink = findunlink(link,i);
                set<int>* group;
                for(int u=0;u<groups.size();u++) {
                    if(groups[u].count(unlink)>0) {
                        group=&groups[u];
                        break;
                    }
                }
                for(int j=1;j<i;j++) {
                    if(find(link.begin(),link.end(),j)==link.end()&&(*group).count(j)==0) {
                        cout<<"No"<<endl;
                        i=n+1;
                        res=false;
                        break;
                    }
                    else if(find(link.begin(),link.end(),j)!=link.end()&&(*group).count(j)>0) {
                        cout<<"No"<<endl;
                        i=n+1;
                        res=false;
                        break;
                    }
                }
                if(res)
                    (*group).insert(i);
            }
        }
        if(res)
            cout<<"Yes"<<endl;
    }
    return 0;
}