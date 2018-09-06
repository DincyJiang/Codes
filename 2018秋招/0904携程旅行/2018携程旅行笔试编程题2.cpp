/*
有一批订单记录，数据有订单号，入店时间，离店时间；
输入一个时间A，需要在这批记录中找到符合入离店时间范围内的所有记录
单词查询时间复杂度控制在O(logN)

注意：订单号升序输出
*/
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

/*
最直接的方法：时间复杂度是O(N)
使用线段树，将查找时间降到O(logN)
*/
int main(){
    int num;
    int A;
    cin >> num >> A;
    vector<vector<int> > record(num, vector<int>(3));
    vector<int> res;
    for(int i = 0; i < num; i++){
        for(int j = 0; j < 3; j++){
            int x;
            scanf("%d",&x);
            record[i][j] = x;
        }
    }

    for(int i = 0; i < num; i++){
        if (record[i][1] <= A && record[i][2] >= A)
            res.push_back(record[i][0]);
    }

    if (res.empty()) {
        cout << "null" << endl;
        return 0;
    }

    int size = res.size();
    for(int i = 0; i < size; i++){
        cout << res[i] << endl;
    }

    return 0;
}
