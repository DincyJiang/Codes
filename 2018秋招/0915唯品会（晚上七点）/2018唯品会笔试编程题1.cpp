/*
leetcode 378
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int> q;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            q.emplace(matrix[i][j]);
            if (q.size() > k) q.pop();
        }
    }
    return q.top();
}
int main() {
    int k, n;
    cin >> k >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];
    }
    cout << kthSmallest(matrix, k) << endl;

    return 0;
}