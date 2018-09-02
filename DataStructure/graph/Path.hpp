#ifndef PATH_H
#define PATH_H

#include <iostream>
#include <cassert>
#include "DenseGraph.hpp"
#include "SparseGraph.hpp"
using namespace std;

// 深度优先遍历求两个节点之间的一条路径
template<typename Graph>
class Path {
public:
    // 在图graph中从点s开始到任一节点的路径
    Path(Graph& graph, int s) : G(graph), s(s) {
        V = G.V();
        assert(s >= 0 && s < V);

        visited = new bool[V];
        from = new int[V];
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
            from[i] = -1;
        }
        dfs(s);
    }
    ~Path() {
        delete [] visited;
        delete [] from;
    }
    // 从源点s到目的节点w是否有路径
    bool hasPath(int w) {
        assert(w >= 0 && w < V);
        return visited[w];
    }
    // 从源点s到目的节点w的路径, 从from数组倒推
    void path(int w, vector<int>& vec) {
        stack<int> s;
        int p = w;
        while (p != -1) {
            s.push(p);
            p = from[p];
        }
        vec.clear();
        while (!s.empty()) {
            vec.push_back(s.top());
            s.pop();
        }
    }
    void showPath() {
        vector<int> vec;
        path(w, vec);
        for (int i = 0; i < vec.size(); ++i) {
            cout << vec[i];
            if (i == vec.size() - 1)
                cout << endl;
            else
                cout << "->";
        }
    }
private:
    void dfs(int v) {
        visited[v] = true;

        typename Graph::adjIterator adj(G, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if (!visited[i]) {
                from[i] = v;
                dfs(i);
            }
        }
    }
private:
    Graph &G;
    int V; // 传入的图的节点个数
    bool *visited;
    int s; // 源节点
    int *from; // 当前节点是从哪个节点遍历过来的
};

#endif 