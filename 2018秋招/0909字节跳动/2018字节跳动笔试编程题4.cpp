/*
LeetCode 393 UTF-8 编码验证
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool validUtf8(vector<int>& data) {
    int cnt = 0;
    for (int d : data) {
        if (cnt == 0) {
            if ((d >> 5) == 0b110) cnt = 1;
            else if ((d >> 4) == 0b1110) cnt = 2;
            else if ((d >> 3) == 0b11110) cnt = 3;
            else if (d >> 7) return false;
        } else {
            if ((d >> 6) != 0b10) return false;
            --cnt;
        }
    }
    return cnt == 0;
}

int main(){
    int N;
    cin >> N;
    vector<int> vec(N, 0);
    for (int i = 0; i < N; ++i)
        cin >> vec[i];
    
    cout << (validUtf8(vec) ? 1 : 0) << endl;
    return 0;
}