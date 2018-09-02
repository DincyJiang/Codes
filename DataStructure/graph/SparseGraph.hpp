#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>

using namespace std;


// 稀疏图， 邻接表表示， 无向图
class SparseGraph {
private:
    int n, m; // n是节点个数，m是边的个数
    bool directed; // 是否是有向图，false表示无向图
    vector<vector<int>> g;
public:
    SparseGraph(int n, bool directed) : n(n), m(0), directed(directed) {
        for (int i = 0; i < n; ++i)
            g.push_back(vector<int>());
    }
    ~SparseGraph() = default;
    int V() { 
        return n;
    }
    int E() {
        return m;
    }
    void addEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        g[v].push_back(w);
        // 如果v和w不是同一个点， 是无向图
        if (v != w && !directed)
            g[w].push_back(v);
        ++m;
    }
    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        for (int i = 0; i < g[v].size(); ++i)
            return true;
        return false;
    }
    void show() {
        for (int i = 0; i < n; ++i) {
            cout << "vertex" << i << ":\t";
            for (int j = 0; j < g[i].size(); ++j)
                cout << g[i][j] << "\t";
            cout << endl;
        }
    }
    // 创造一个迭代器
    class adjIterator {
    private:
        SparseGraph &G;
        int v;
        int index;
    public:
        adjIterator(SparseGraph& graph, int v) : G(graph), v(v), index(0) {}
        ~adjIterator() = default;
        int begin() {
            index = 0;
            // 如果顶点v有邻接表，返回表中第一个
            if (G.g[v].size())
                return G.g[v][0];
            return -1;
        }
        int next() {
            ++index;
            if (index < G.g[v].size())
                return G.g[v][index];
            return -1;
        }
        int end() {
            return index >= G.g[v].size();
        }
    };
};