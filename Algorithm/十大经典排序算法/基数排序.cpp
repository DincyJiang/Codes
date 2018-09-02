/*
基数排序
时间复杂度：平均和最坏都是O(n*k)

基数排序是按照低位先排序，然后收集；再按照高位排序，然后再收集；依次类推，直到最高位。
有时候有些属性是有优先级顺序的，先按低优先级排序，再按高优先级排序。
最后的次序就是高优先级高的在前，高优先级相同的低优先级高的在前。

算法描述
取得数组中的最大数，并取得位数；
arr为原始数组，从最低位开始取每个位组成radix数组；
对radix进行计数排序（利用计数排序适用于小范围数的特点)

基数排序基于分别排序，分别收集，所以是稳定的。但基数排序的性能比桶排序要略差，
每一次关键字的桶分配都需要O(n)的时间复杂度，而且分配之后得到新的关键字序列又需要O(n)的时间复杂度。
假如待排数据可以分为d个关键字，则基数排序的时间复杂度将是O(d*2n) ，
当然d要远远小于n，因此基本上还是线性级别的。

基数排序的空间复杂度为O(n+k)，其中k为桶的数量。一般来说n>>k，因此额外空间需要大概n个左右。

Least significant digit（LSD）
短的关键字被认为是小的，排在前面，然后相同长度的关键字再按照词典顺序或者数字大小等进行排序。
比如1，2，3，4，5，6，7，8，9，10，11或者”b, c, d, e, f, g, h, i, j, ba” 。

Most significance digit（MSD）
直接按照字典的顺序进行排序，对于字符串、单词或者是长度固定的整数排序比较合适。
比如：1, 10, 2, 3, 4, 5, 6, 7, 8, 9和 “b, ba, c, d, e, f, g, h, i, j”。
*/


// 基于LSD的基数排序算法：
#include <iostream>

using namespace std;
const int MAX = 10;

void print(int *a,int sz) {               
    for(int i = 0; i < sz; i++)
        cout << a[i] << " ";
    cout << endl;
}

void RadixSortLSD(int *a, int arraySize)
{
    int i, bucket[MAX], maxVal = 0, digitPosition =1 ;
    for(i = 0; i < arraySize; i++) {
        if(a[i] > maxVal) maxVal = a[i];
    }

    int pass = 1;  // used to show the progress
    /* maxVal: this variable decide the while-loop count 
               if maxVal is 3 digits, then we loop through 3 times */
    while(maxVal/digitPosition > 0) {
        /* reset counter */
        int digitCount[10] = {0};

        /* count pos-th digits (keys) */
        for(i = 0; i < arraySize; i++)
            digitCount[a[i]/digitPosition%10]++;

        /* accumulated count */
        for(i = 1; i < 10; i++)
            digitCount[i] += digitCount[i-1];

        /* To keep the order, start from back side */
        for(i = arraySize - 1; i >= 0; i--)
            bucket[--digitCount[a[i]/digitPosition%10]] = a[i];

        /* rearrange the original array using elements in the bucket */
        for(i = 0; i < arraySize; i++)
            a[i] = bucket[i];

        /* at this point, a array is sorted by digitPosition-th digit */
        cout << "pass #" << pass++ << ": ";
        print(a,arraySize);

        /* move up the digit position */
        digitPosition *= 10;
    }   
 }

int main()
{
    int a[] = {170, 45, 75, 90, 2, 24, 802, 66};
    const size_t sz = sizeof(a)/sizeof(a[0]);

    cout << "pass #0: ";
    print(a,sz);
    RadixSortLSD(&a[0],sz);
    return 0;
}






