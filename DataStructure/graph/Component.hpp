#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>
#include <cassert>
#include "DenseGraph.hpp"
#include "SparseGraph.hpp"
using namespace std;

// 深度优先遍历求连通分量
template<typename Graph>
class Component {
public:
    Component(Graph& graph) : G(graph) {
        visited = new bool[G.V()];
        id = new int[G.V()];
        ccount = 0;
        for (int i = 0; i < G.V(); ++i)
            visited[i] = false;
            id[i] = -1;

        for (int i = 0; i < G.V(); ++i)
            if (!visited[i]) {
                dfs(i);
                ++ccount;
            }
    }
    ~Component() {
        delete [] visited;
        delete [] id;
    }
    // 返回连通分量数
    int count() {
        return ccount;
    }
    // 判断两个节点是否相连
    bool isConnected(int v, int w) {
        return id[v] == id[w];
    }
private:
    void dfs(int v) {
        visited[v] = true;
        id[v] = ccount;

        typename Graph::adjIterator adj(G, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if (!visited[i])
                dfs(i);
        }
    }
private:
    Graph &G;
    bool *visited;
    int ccount; // 连通分量个数
    int *id; // 相邻的节点有相同的id值
};





#endif 