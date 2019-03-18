#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n{};
    cin >> n;
    vector<int> vec(n, 0);
    for (int i{0}; i < n; ++i) {
        cin >> vec[i];
    }
    vector<int> res(n, 0);
    for (int i{0}; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (vec[j] > vec[i]) {
                res[i] = j + 1;
                break;
            }
            if (j == n-1 && vec[j] <= vec[i]) {
                res[i] = 0;
                break;
            }
        }
    }
    res[n-1] = 0;

    for (int &num : res) {
        cout << num << endl;
    }

    return 0;
}