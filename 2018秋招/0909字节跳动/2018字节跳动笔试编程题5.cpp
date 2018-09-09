/*
计算抖音红人个数
用户数N，有M个关注关系对
（A， B）表示A关注B
关注关系有传递性
如果一个用户被所有N个用户直接或者间接关注，就认为他是红人
求所有红人总数
*/

// 思路：把指向当前用户的所有用户都放进一个数组中，用map记录
//      遍历map，把指向的指向都加进数组
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

void getGuanzhuCore(map<int, vector<int>> & guanzhu, map<int, set<int>> & beiguanzhu, vector<int> & lujing, int user)
{
    for (int i = 0; i < guanzhu[user].size(); ++i)
    {
        for (int j = 0; j < lujing.size(); ++j)
        {
            beiguanzhu[guanzhu[user][i]].insert(lujing[j]);
        }
        //没有在路径中的元素，继续查找
        if (find(lujing.begin(), lujing.end(), guanzhu[user][i]) == lujing.end())
        {
            lujing.push_back(guanzhu[user][i]);
            getGuanzhuCore(guanzhu, beiguanzhu, lujing, guanzhu[user][i]);
            lujing.pop_back();
        }
    }
 
}
 
void getAllGuanzhu(map<int, vector<int>> & guanzhu, map<int, set<int>> & beiguanzhu)
{
    vector<int> guanzhulujing;
    for (auto it = guanzhu.begin(); it != guanzhu.end(); ++it)
    {
        guanzhulujing.clear();
        guanzhulujing.push_back(it->first);
        getGuanzhuCore(guanzhu, beiguanzhu, guanzhulujing, it->first);
    }
}
 
int main()
{
    int n = 0, m = 0;
    while (cin >> n >> m)
    {
        map<int, vector<int>> guanzhu;
        map<int, set<int>> beiguanzhu;
        for (int i = 0; i < m; ++i)
        {
            int u1 = 0, u2 = 0;
            cin >> u1 >> u2;
            guanzhu[u1].push_back(u2);
        }
        getAllGuanzhu(guanzhu, beiguanzhu);
        int cnt = 0;
        for (auto it = beiguanzhu.begin(); it != beiguanzhu.end(); ++it)
        {
            it->second.erase(it->first);//先删掉自己的关注
            if (it->second.size() >= n - 1)
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
