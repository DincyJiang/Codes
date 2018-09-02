/*
计数排序：
时间复杂度为:平均和最坏都是Ο(n+k)（其中k是整数的范围）
计数排序是一个非基于比较的排序算法，该算法于1954年由 Harold H. Seward 提出。
它的优势在于在对一定范围内的整数排序时，快于任何比较排序算法。 
当然这是一种牺牲空间换取时间的做法，而且当O(k)>O(n*log(n))的时候其效率反而不如基于比较的排序。

计数排序不是基于比较的排序算法，其核心在于将输入的数据值转化为键存储在额外开辟的数组空间中。 
作为一种线性时间复杂度的排序，计数排序要求输入的数据必须是有确定范围的整数。

计数排序的步骤如下:
查找待排序数组中最大和最小的元素
统计每个值为i的元素的出现次数
对所有计数开始累加(从min开始,每一项和前一项相加)
反向填充目标数组,将每个元素i放在新数组的第C[i]项,每放一个元素,计数-1.
*/

#include <iostream>

using namespace std;

void print(int a[], int sz) {
    for (int i = 0; i < sz;  i++ ) cout << a[i] << " ";
    cout << endl;
}

void CountingSort(int arr[], int sz) {
    int i, j, k;
    int idx = 0;
    int min, max;

    min = max = arr[0];
    for(i = 1; i < sz; i++) {
        min = (arr[i] < min) ? arr[i] : min;
        max = (arr[i] > max) ? arr[i] : max;
    }

    k = max - min + 1;
    /* creates k buckets */
    int *B = new int [k]; 
    for(i = 0; i < k; i++) B[i] = 0;

    for(i = 0; i < sz; i++) B[arr[i] - min]++;
    for(i = min; i <= max; i++) 
        for(j = 0; j < B[i - min]; j++) arr[idx++] = i;

    print(arr,sz);

    delete [] B;
}

int main()
{
    int a[] = {5,9,3,9,10,9,2,4,13,10};
    const size_t sz = sizeof(a)/sizeof(a[0]);
    print(a,sz);
    cout << "----------------------\n" ;
    CountingSort(a, sz);
}