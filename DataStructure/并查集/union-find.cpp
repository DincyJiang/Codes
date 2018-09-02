#include <iostream>
#include <cassert>
using namespace std;

namespace UF1{
// 实现方式：数组，查找快，Quick Find，缺点：union操作慢
class UnionFind {
public:
    UnionFind(int n) : count(n) {
        id = new int[n];
        for (int i = 0; i < n; ++i) {
            id[i] = i;
        }
    }
    ~UnionFind() {
        delete [] id;
    }
    int find(int p) {
        assert(p >= 0 && p < count);
        return id[p];
    }
    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }
    void unionElements(int p, int q) {
        int pID = find(p);
        int qID = find(q);
        if (pID == qID)
            return;
        for (int i = 0; i < count; ++i) {
            if (id[i] == pID)
                id[i] = qID;
        }
    }
private:
    int *id;
    int count;
};
}

namespace UF2{
// 实现方式：将每一个元素看作一个节点
class UnionFind {
public:
    UnionFind(int n) : count(n) {
        parent = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    ~UnionFind() {
        delete [] parent;
    }
    // 找到的是p节点的根
    int find(int p) {
        assert(p >= 0 && p < count);
        while(p != parent[p])
            p = parent[p];
        return p;
    }
    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }
    void unionElements(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot)
            return;
        // 只单纯的把p节点的根指向q节点的根
        parent[pRoot] = qRoot;
    }
private:
    int *parent;
    int count;
};
}

namespace UF3{
// 优化：用每棵树中的节点个数
class UnionFind {
public:
    UnionFind(int n) : count(n) {
        parent = new int[n];
        sz = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            sz[i] = 1;
        }
    }
    ~UnionFind() {
        delete [] parent;
        delete [] sz;
    }
    // 找到的是根
    int find(int p) {
        assert(p >= 0 && p < count);
        while(p != parent[p])
            p = parent[p];
        return p;
    }
    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }
    void unionElements(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot)
            return;
        // 比较哪个节点的集合元素少，把元素少的并到元素多的
        if (sz[pRoot] < sz[qRoot]) {
            parent[pRoot] = qRoot;
            sz[qRoot] += sz[pRoot];
        } else {
            parent[qRoot] = pRoot;
            sz[pRoot] += sz[qRoot];
        }
    }
private:
    int *parent;
    int *sz; //sz[i]表示以i为根的集合中元素个数
    int count;
};
}

namespace UF4{
// 基于rank的优化， rank[i]表示的是以i为根的集合所表示的树的层数
class UnionFind {
public:
    UnionFind(int n) : count(n) {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    ~UnionFind() {
        delete [] parent;
        delete [] rank;
    }
    // 找到的是根
    int find(int p) {
        assert(p >= 0 && p < count);
        while(p != parent[p])
            p = parent[p];
        return p;
    }
    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }
    void unionElements(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot)
            return;
        if (rank[pRoot] < rank[qRoot]) {
            parent[pRoot] = qRoot;
        } else if (rank[pRoot] > rank[pRoot]){
            parent[qRoot] = qRoot;
        } else {
            // 当两棵树一样高时，随便用一个指向另一个
            parent[pRoot] = qRoot;
            rank[qRoot] += 1;
        }
    }
private:
    int *parent;
    int *rank; // rank[i]表示的是以i为根的集合所表示的树的层数
    int count;
};
}

namespace UF5{
// 优化方案：路径压缩
class UnionFind {
public:
    UnionFind(int n) : count(n) {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    ~UnionFind() {
        delete [] parent;
        delete [] rank;
    }
    // 找到的是根
    int find(int p) {
        assert(p >= 0 && p < count);
        // while(p != parent[p])
        //     parent[p] = parent[parent[p]]; // 路径压缩
        //     p = parent[p];
        // return p;
        if (p != parent[p])
            parent[p] = find(parent[p]); // 递归压缩，最终压缩效果是：每棵树只有两层
        return parent[p];
    }
    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }
    void unionElements(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot)
            return;
        if (rank[pRoot] < rank[qRoot]) {
            parent[pRoot] = qRoot;
        } else if (rank[pRoot] > rank[pRoot]){
            parent[qRoot] = qRoot;
        } else {
            // 当两棵树一样高时，随便用一个指向另一个
            parent[pRoot] = qRoot;
            rank[qRoot] += 1;
        }
    }
private:
    int *parent;
    int *rank; // rank[i]表示的是以i为根的集合所表示的树的层数
    int count;
};
}
