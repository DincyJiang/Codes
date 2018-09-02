/*
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例:

输入: 4
输出: [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。

*/

/*

*/
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
#include <cassert>
using namespace std;

namespace sss {
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        col = vector<bool>(n, false);
        dia1 = vector<bool>(2*n-1, false);
        dia2 = vector<bool>(2*n-1, false);
        vector<int> row;
        putQueen(n, 0, row);
        return res;
    }
private:
    // 尝试在一个n皇后问题中，摆放第index行的皇后位置
    void putQueen(int n, int index, vector<int>& row) {
        if (index == n) {
            res.push_back(generateBoard(n, row));
            return;
        }
        for (int i = 0; i < n; ++i)
            // 尝试将第index行的皇后摆放在第i列
            if (!col[i] && !dia1[index+i] && !dia2[index-i+n-1]) {
                row.push_back(i);
                col[i] = true;
                dia1[index+i] = true;
                dia2[index-i+n-1] = true;
                putQueen(n, index + 1, row);
                col[i] = false;
                dia1[index+i] = false;
                dia2[index-i+n-1] = false;
                row.pop_back();
            }
        return;
    }
    vector<string> generateBoard(int n, vector<int>& row) {
        assert(row.size() == n);
        vector<string> board(n, string(n, '.'));
        for (int i = 0; i < n; ++i)
            board[i][row[i]] = 'Q';
        return board;
    }
private:
    vector<vector<string>> res;
    vector<bool> col, dia1, dia2; // 列， 对角线，对角线
};
}

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result; //存储最终结果的数组
        vector<vector<int> > mark;   //标记棋盘是否可以放置皇后的二维数组
        vector<string> location;  //存储某个摆放结果，当完成一次递归找到结果后，将location push进入result
        //初始化，mark中全是0，location中是n个'.'
        for(int i=0;i<n;++i){
            mark.push_back(vector<int> ());
            for(int j=0;j<n;++j){
                mark[i].push_back(0);
            }
            location.push_back("");
            location[i].append(n,'.');
        }
        generate(0,n,location,result,mark);
        return result;
    }
    //k代表完成了几个皇后的位置（正在放置第k行皇后）
    void generate(int k,int n,vector<string>& location,  
                vector<vector<string> >& result,vector<vector<int> >& mark){
        if(k==n){
            result.push_back(location);
            return;
        }
        for(int i=0;i<n;++i){   //循环某一行的每一列
            if(mark[k][i]==0){  //mark数组中的值是0说明这个地方可以放置皇后
                vector<vector<int> > tmp_mark=mark;  //把当前的棋盘存下来
                location[k][i]='Q';
                put_down_the_queue(k,i,mark); //修改棋盘mark
                generate(k+1,n,location,result,mark);
                mark=tmp_mark;  //回溯时恢复上一步的棋盘
                location[k][i]='.';
            }
        }
    }
private:
    void put_down_the_queue(int x,int y,vector<vector<int> >& mark){
    static const int dx[]={-1,1,0,0,-1,-1,1,1}; //方向数组
    static const int dy[]={0,0,-1,1,-1,1,-1,1}; //方向数组
    mark[x][y]=1;
    for(int i=1;i<mark.size();++i){
        for(int j=0;j<8;++j){
            int new_x=x+i*dx[j];
            int new_y=y+i*dy[j];
            if(new_x>=0 && new_x<mark.size() && new_y>=0 && new_y<mark.size()){
                mark[new_x][new_y]=1;
            }
        }
    }
}
};

int main(){
    vector<vector<string> > result;
    Solution solve;
    result=solve.solveNQueens(4);
    int d=1;
    for(auto i : result){
        cout<<"第"<< d <<":"<<endl;
        for(auto j : i){
            cout<<j<<endl;
        }
        ++d;
    }
    return 0;
}

