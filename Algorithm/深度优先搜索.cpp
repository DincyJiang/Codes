/*
深度优先搜索（Depth First Search）DFS

深度优先遍历图的方法是，从图中某顶点v出发：
（1）访问顶点v；
（2）依次从v的未被访问的邻接点出发，对图进行深度优先遍历；直至图中和v有路径相通的顶点都被访问；
（3）若此时图中尚有顶点未被访问，则从一个未被访问的顶点出发，重新进行深度优先遍历，直到图中所有顶点均被访问过为止。　

深度优先搜索用栈（stack）来实现，整个过程可以想象成一个倒立的树形：
1、把根节点压入栈中。
2、每次从栈中弹出一个元素，搜索所有在它下一级的元素，把这些元素压入栈中。并把这个元素记为它下一级元素的前驱。
3、找到所要找的元素时结束程序。
4、如果遍历整个树还没有找到，结束程序。
*/


#include <iostream>
#include <stack>
using namespace std;

#define MaxNode 20
#define MAX 2000
#define StartNode 1

int map[MaxNode+1][MaxNode+1];

void dfs_stack(int start, int n){
    int visited[MaxNode],s_top;
    for(int i = 0;i <= MaxNode; i++){
        visited[i] = 0;
    }
    visited[start] = 1;
    stack <int> s;
    cout<<start<<" ";
    for(int i = 1; i <= n; i++){
        if(map[i][start] == 1 && !visited[i] ){
            visited[i] =  1;
            s.push(i);
        }
    }
    
    while(!s.empty()){
        s_top =  s.top();
        visited[s_top] = 1;
        cout<<s_top<<" ";
        s.pop();
        for(int i = 1; i <= n; i++){
            if(map[i][s_top] == 1 && !visited[i] ){
                visited[i] = 1;
                s.push(i);
            }
        }
    }
    
}

int main() {
    int num_edge=10,num_node=11;
    int x,y;
    //cout<<"Input number of nodes and edges >"<<endl;
    //cin>>num_node>>num_edge;
    for(int i =0;i<num_node;i++){
        for(int j=0;j<num_node;j++){
            map[i][j] = 0;
        }
    }
    for(int i = 1; i <= num_edge; i++){
        cin>>x>>y;
        map[x][y] = map[y][x] = 1;
    }
    
    dfs_stack(StartNode, num_node);

    return 0;
}