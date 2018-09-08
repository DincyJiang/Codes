/*

*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int compute(int X, int Y, string Z) {

    return 0;
}

int main() {
    int T;
    cin >> T;
    vector<int> res(T, 0);
    for (int i = 0; i < T; ++i) {
        int X, Y;
        string Z;
        cin >> X >> Y >> Z;
        res[i] = compute(X, Y, Z);
    }

    for (int i : res)
        cout << i;
        
    return 0;
}