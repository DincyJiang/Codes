/*
希尔排序（shell):

希尔排序的平均时间复杂度为O(N^1.3),最坏时间复杂度是O(N^2)

1959年Shell发明，第一个突破O(n2)的排序算法，是简单插入排序的改进版。
它与插入排序的不同之处在于，它会优先比较距离较远的元素。希尔排序又叫缩小增量排序。

希尔排序的核心在于间隔序列的设定。既可以提前设定好间隔序列，也可以动态的定义间隔序列。
希尔排序是直接插入排序的改进，它的插入增量可以变化，
增量为2的shell排序的时间代价可以达到θ(n的3/2次方)，
有的增量可以达到θ(n的7/6次方)，很接近θ(n)。 

基本思想：算法先将要排序的一组数按某个增量d（n/2,n为要排序数的个数）分成若干组，
每组中记录的下标相差d.对每组中全部元素进行直 接插入排序，
然后再用一个较小的增量（d/2）对它进行分组，在每组中再进行直接插入排序。
当增量减到1时，进行直接插入排序后，排序完成。
*/

#include<iostream>
#include<vector>
using namespace std;

void ShellSort(vector<int>& a){  
    for(int gap=a.size()/2;gap>0;gap/=2){
        for(int i=gap;i<a.size();i++){
            for(int j=i-gap;j>=0 && a[j]>a[j+gap];j-=gap){ //从小到大排序
                swap(a[j],a[j+gap]);
            }
        }
    }
}

int main(){
    vector<int> a;
    a.push_back(23);
    a.push_back(466);
    a.push_back(5);
    a.push_back(26);
    a.push_back(87);
    a.push_back(63);
    a.push_back(8);
    a.push_back(34);
    a.push_back(267);
    a.push_back(2424);
    a.push_back(5);
    a.push_back(646);
    cout<<"原来的顺序："<<endl;
    for(auto i : a){
        cout<<i<<' ';
    }
    cout<<endl;
    ShellSort(a);

    cout<<"希尔排序结果："<<endl;
    for(auto i : a){
        cout<<i<<' ';
    }
    cout<<endl;

    return 0;
}
