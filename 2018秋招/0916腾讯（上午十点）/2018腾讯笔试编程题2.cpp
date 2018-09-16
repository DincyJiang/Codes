/*

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> g;

// 所有点的入度
vector<int> indegree(vector<vector<int>>& g) {

}

// 所有点的出度
vector<int> outdegree(vector<vector<int>>& g) {

}

int main() {
    int n, m;
    cin >> n >> m;
    int X, Y;
    vector<vector<int>> g(n+1, vector<int>()); // 邻接表表示
    for (int j = 0; j < m; ++j) {
        cin >> X >> Y;
        g[X].push_back(Y);
    }

    vector<int> out = outdegree(g);
    vector<int> in = indegree(g);


    return 0;
}