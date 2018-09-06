#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int height, width, waterLevel;
    cin >> height >> width >> waterLevel;
    int res = 0;
    vector<vector<int>> vec(height, vector<int>(width, 0));
    vector<vector<int>> mark(height, vector<int>(width, 0));

    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; j++){
            int x;
            scanf("%d",&x);
            vec[height][width] = x;
            if (x > waterLevel) {
                mark[height][width] = 1;
                ++res;
            }
        }
    }
    cout << res << endl;
    return 0;
}