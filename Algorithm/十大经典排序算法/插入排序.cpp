/*
插入排序:

平均时间复杂度是O(N^2), 最坏时间复杂度是O(N^2)

通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
一般来说，插入排序都采用in-place在数组上实现。具体算法描述如下：
从第一个元素开始，该元素可以认为已经被排序；
取出下一个元素，在已经排序的元素序列中从后向前扫描；
如果该元素（已排序）大于新元素，将该元素移到下一位置；
重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
将新元素插入到该位置后；
重复步骤2~5。
*/

#include<iostream>
#include<vector>
//#include<algorithm>
using namespace std;


void InsertSort(vector<int>& a){
    int j,key; 
    for(int i=1;i<a.size();++i){
        key=a[i]; //key暂时存放待排序的数
        j=i-1; //j是key的前一个数的索引
        while(j>=0 && a[j]>key){
            a[j+1]=a[j]; //把j的数往后移一个
            --j;
        }
        a[j+1]=key; //把key插入j位置的后面
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
    InsertSort(a);

    cout<<"插入排序结果："<<endl;
    for(auto i : a){
        cout<<i<<' ';
    }
    cout<<endl;

    return 0;
}

