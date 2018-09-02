#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>

using namespace std;

// 稠密图， 邻接矩阵表示， 无向图
class DenseGraph {
private:
    int n, m; // n是节点个数，m是边的个数
    bool directed; // 是否是有向图，false表示无向图
    vector<vector<bool>> g;
public:
    DenseGraph(int n, bool directed) : n(n), m(0), directed(directed) {
        for (int i = 0; i < n; ++i)
            g.push_back(vector<bool>(n, false));
    }
    ~DenseGraph() = default;
    int V() { 
        return n;
    }
    int E() {
        return m;
    }
    void addEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        if (hasEdge(v, w)) // 如果有这个边了，直接返回
            return;
        g[v][w] = true;
        if (!directed) // 如果是无向图
            g[w][v] = true;
        ++m;
    }
    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        return g[v][w];
    }
    void show() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << g[i][j] << "\t";
            cout << endl;
        }
    }
    // 创造一个迭代器
    class adjIterator {
    private:
        DenseGraph &G;
        int v;
        int index;
    public:
        adjIterator(DenseGraph& graph, int v) : G(graph), v(v), index(-1) {}
        ~adjIterator() = default;
        int begin() {
            index = -1;
            return next();
        }
        int next() {
            for (index += 1; index < G.V(); ++index)
                if (G.g[v][index])
                    return index;
            return -1;
        }
        int end() {
            return index >= G.V();
        }
    };
};

