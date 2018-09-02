/*
归并排序
时间复杂度O(nlogn)
归并排序是一种稳定的排序方法。和选择排序一样，归并排序的性能不受输入数据的影响，
但表现比选择排序好的多，因为始终都是O(nlogn）的时间复杂度。
代价是需要额外的内存空间。

归并排序是建立在归并操作上的一种有效的排序算法。
该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。
将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，
再使子序列段间有序。若将两个有序表合并成一个有序表，称为2-路归并。

归并排序的中心思想是将两个已经排序好的序列，合并成一个排序的序列。


*/


#include<iostream>
#include <algorithm> // has copy
using namespace std;

template <class T>
void merge(T c[], T d[], int startOfFirst, int endOfFirst,
                         int endOfSecond)
{// Merge two adjacent segments from c to d.
   int first = startOfFirst,       // cursor for first segment
       second = endOfFirst + 1,    // cursor for second
       result = startOfFirst;      // cursor for result

   // merge until one segment is done
   while ((first <= endOfFirst) && (second <= endOfSecond))
      if (c[first] <= c[second])
         d[result++] = c[first++];
      else
         d[result++] = c[second++];

   // take care of leftovers
   if (first > endOfFirst)
      for (int q = second; q <= endOfSecond; q++)
          d[result++] = c[q];
   else
      for (int q = first; q <= endOfFirst; q++)
          d[result++] = c[q];
}
template <class T>
void mergePass(T x[], T y[], int n, int segmentSize)
{// Merge adjacent segments from x to y.
   int i = 0;   // start of the next segment
   while (i <= n - 2 * segmentSize)
   {// merge two adjacent segments from x to y
      merge(x, y, i, i + segmentSize - 1, i + 2 * segmentSize - 1);
      i = i + 2 * segmentSize;
   }

   // fewer than 2 full segments remain
   if (i + segmentSize < n)
      // 2 segments remain
      merge(x, y, i, i + segmentSize - 1, n - 1);
   else
      // 1 segment remains, copy to y
      for (int j = i; j < n; j++)
         y[j] = x[j];
}
template <class T>
void mergeSort(T a[], int n)
{// Sort a[0 : n - 1] using the merge sort method.
   T *b = new T [n];
   int segmentSize = 1;
   while (segmentSize < n)
   {
      mergePass(a, b, n, segmentSize); // merge from a to b
      segmentSize += segmentSize;
      mergePass(b, a, n, segmentSize); // merge from b to a
      segmentSize += segmentSize;
   }
}




int main()
{
   int a[10] = {10,7,8,9,4, 2, 3, 6, 5,1};

   // output the elements
   cout << "a[0:9] = ";
   copy(a, a+10, ostream_iterator<int>(cout, " "));
   cout << endl;

   // sort
   mergeSort(a,10);

   // output the sorted sequence
   cout << "After the sort, a[0:9] = ";
   copy(a, a+10, ostream_iterator<int>(cout, " "));
   cout << endl;
   return 0;
}
// int main(){
//     vector<int> vec1;
//     vector<int> vec2;
//     srand(time(NULL));
//     for(int i=0;i<10000;++i){
//         int num=(rand()*rand())%100003;
//         vec1.push_back(num);
//         vec2.push_back(num);
//     }
//     merge_sort(vec1);
//     sort(vec2.begin(),vec2.end());
//     assert(vec1.size()==vec2.size());  //assert.h
//     for(int i=0;i<vec1.size();++i){
//         assert(vec1[i]==vec2[i]);
//     }
//     return 0;
// }