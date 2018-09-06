/*
图的遍历
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
给定一张包含N个点、N-1条边的无向连通图，节点从1到N编号，每条边的长度均为1。假设你从1号节点出发并打算遍历所有节点，那么总路程至少是多少？

输入
第一行包含一个整数N，1≤N≤105。

接下来N-1行，每行包含两个整数X和Y，表示X号节点和Y号节点之间有一条边，1≤X，Y≤N。

输出
输出总路程的最小值。


样例输入
4
1 2
1 3
3 4
样例输出
4

Hint
按1->2->1->3->4的路线遍历所有节点，总路程为4。
*/

#include <iostream>  
#include <string>  
#include <sstream>  
using namespace std;  
// ====================== 宏定义 ==============================================  
#define SITE_NUM 4                       // 站点最多数目  
// ==========================================================================  
// ========================= 全局变量 ===========================================  
int distance[SITE_NUM][SITE_NUM];              // 到各个站点之间的距离  
int min_distance = 65535;                              // 从某个站点出发的最短遍历的距离  
int min_trace[SITE_NUM];                       // 最短遍历的路线  
 
class Site  
{  
private:  
    int site_flag;                        // 站点标识符，用来区别各个站点  
    bool site[SITE_NUM];                  // 已经访问过的站点  

public:  
    Site(){}  
    Site(int flag)  
    {  
        site_flag = flag;  
        for (int i = 0; i < SITE_NUM; i++)  
            site[i] = false;  
        site[flag] = true;  
    }  
    int get_site_flag()  
    {    
        return site_flag;    
    }  
    bool visited_site(int next_site)  
    {  
        cout << "())()" << next_site << endl;  
        if (!site[next_site])  
        {  
            site[next_site] = true;  
            return false;  
        }  
        return true;  
    }  
    bool visited_all_site()  
    {  
        for (int i = 0; i < SITE_NUM; i++)  
            if (site[i]==false)  
                return false;  
        return true;  
    }  
    void set_true(int s)  
    {  
        site[s] = true;  
    }  
    void print()  
    {  
        for (int i = 0; i < SITE_NUM; i++)  
            cout << site_flag << " &&&" << site[i] << endl;  
    }  
};  
/************************************************************************************** 
 ************************* 蚁群算法 ************************************************** 
 **********************  用于最短路径遍历 ******************************************** 
 *************************************************************************************/  
class Ant  
{  
protected:    
    bool all_finish_flag;  
  int  start_site;                              // 初始站点  
  bool allowed[SITE_NUM];                                        // 禁忌表, 判断当前的顶点是否可以访问（true可以，false不可以）  
  int  cur_tour_trace[SITE_NUM];                                    // 当前路线  
  int  cur_tour_index;                                    // 当前路径的索引  
  Site  all_site[SITE_NUM];                               // 各个站点的数组  
public:  
    Ant()  
    {  
        int i;  
        for ( i= 0; i < SITE_NUM; i++)  
            all_site[i] = Site(i);  
        cur_tour_index = 0;  
        for (i = 0; i < SITE_NUM; i++)  
            allowed[i] = true;  
    }  
    // 给出初始站点  
    void start(string start_site_flag)  
    {  
        char temp;  
        istringstream sin(start_site_flag);  
        sin >> temp;  
        sin >> start_site;  
        start_site--;                   // 数组下标与用户界面输入相吻合  
        allowed[start_site] = false;  
        all_finish_flag = false;  
    }  
    // 寻找最小路径  
    void find_min_path()  
    {  
        int i;  
        //cur_site            = start_site;  
        cur_tour_trace[cur_tour_index] = start_site;  
        allowed[start_site] = false;  
        for ( i = 0;i < SITE_NUM; i++)  
            all_site[i].set_true(start_site);  
        cout << start_site << " " << " ajdfk " << endl;  
        all_site[0].print();  
        while ( !move_next_city(start_site) )  
            ;  
    }  
    // 蚂蚁转移到下一个城市  
    inline bool move_next_city(int cur_site)  
    {  
        cout << start_site << " " << cur_site << " " <<cur_tour_index<< "**** " << endl;  
        int i;  
        bool finish_flag;  
        for ( i = 0;i < SITE_NUM; i++)  
        {  
            if (allowed[i]==false)  
                continue;  
            cout << cur_site;                                                                                                                                                               
            if (all_site[cur_site].visited_site(i)==true)  
                continue;  
            allowed[i] = false;  
            cur_tour_trace[++cur_tour_index] = i;  
            finish_flag = move_next_city(i);  
        }  
        if (i>=SITE_NUM)  
          finish_flag = finish();  
        else  
        {  
            move_next_city(cur_site);  
            cout << start_site << " " << cur_site << " " <<cur_tour_index<< "++++" << i<< endl;  
        }  
        if (all_finish_flag==true)  
            return true;  
        cur_tour_index--;  
        return finish_flag;  
    }  
    bool finish(void);  
      
};  
bool Ant::finish(void)  
{  
        int dist = 0;  
        int i;  
        bool finish_flag = false;  
        if (cur_tour_index != SITE_NUM)  
            return false;  
        for (i = 0; i < SITE_NUM-1; i++)  
        {  
            dist += ::distance[cur_tour_trace[i]][cur_tour_trace[i+1]];   
            cout << dist <<" " << cur_tour_trace[i] << " " << cur_tour_trace[i+1] << " *****+++" <<endl;  
        }  
        cout << start_site << " " <<cur_tour_index<< "--------" << endl;  
        system("pause");  
        if (dist < min_distance)  
        {  
            min_distance = dist;  
            for (i = 0; i < SITE_NUM; i++)  
                min_trace[i] = cur_tour_trace[i];  
        }  
        cout << start_site << " " <<cur_tour_index<< "1111" << endl;  
        for (i = 0; i < SITE_NUM ;i++)  
            allowed[i] =true;  
        allowed[start_site] = false;  
        //cur_site = start_site;      
        for (i = 0; i < SITE_NUM; i++)  
        {  
            //system("pause");  
            if ( !all_site[i].visited_all_site() )  
            {  
                cout << start_site  << " " <<cur_tour_index<< "222" << endl;  
                return false;  
            }  
            cout << start_site << " " <<cur_tour_index<< "3333" << endl;  
        }  
        all_finish_flag = true;  
        return true;  
}  
/************************************************************************************** 
 ************************* 输入界面 ************************************************** 
 **********************  只适用于该程序 ******************************************** 
 *************************************************************************************/  
class Viewer  
{  
private:  
     Ant processor;  
     char flag;  
public:  
    void input();  
    void process();  
    void print_result();  
};  
void Viewer::input()  
{  
    //string input;  
    char input[30];  
    istringstream filter;  
    int site_one, site_two, dist;  
    cout << "///////////////////////////////////////////////////////////////////////////n"  
         << "/////////***********************2011-5-3*************************//////////n"  
         << "//////////////////////////////数学建模/////////////////////////////////////n"  
         << "///////////////////////////////////////////////////////////////////////////n/n"  
         << "请输入各个站点之间数据... /n";  
    while (1)  
    {  
        //getline(cin, input, '/n');  
        gets(input);  
        filter.clear();  
        filter.str(input);  
        filter>>flag >> site_one >>flag >> site_two >> dist;  
        cout << site_one << " " << site_two<< " " <<dist <<endl;  
        ::distance[site_one-1][site_two-1] = dist;  
        ::distance[site_two-1][site_one-1] = dist;  
        if (input[0] == '0')  
            break;  
    }  
    cout << endl;  
}  
void Viewer::process()  
{  
    string start_site;  
    cout << " 请输入从哪个站点开始/n";  
    cin >> start_site;  
    processor.start(start_site);  
    processor.find_min_path();  
}  
void Viewer::print_result()  
{  
    for (int i = 0; i < SITE_NUM; i++)  
        if (i!=SITE_NUM-1)  
            cout << min_trace[i] << "---->";  
        else   
            cout << min_trace[i] << endl;  
    cout << "最短距离为：" << min_distance << endl;  
}  
int main()  
{  
    Viewer panel;  
    panel.input();  
//  for (int i = 0; i < SITE_NUM; i++)  
//  {  
    //  for (int j = 0; j < SITE_NUM; j++)  
    //      cout << ::distance[i][j];  
    //  cout << endl;  
//  }  
    panel.process();  
    panel.print_result();  
} 
