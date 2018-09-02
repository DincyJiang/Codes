/*
选择排序：
时间复杂度：O(n2)
选最大的数放在后面
选择排序与冒泡排序的区别在于：选最大数的方法

这是分而治之的思想，是一种二路划分，将原序列划分为两个序列A和B
将最大的数放在序列B，剩下的数放入A，然后对序列A递归排序

*/

#include <iostream>
#include <algorithm> 
using namespace std;

template<class T>
int indexOfMax(T a[], int n)
{// Locate the largest element in a[0:n-1].
   int indexOfMax = 0;
   for (int i = 1; i < n; i++)
     if (a[indexOfMax] < a[i])
        indexOfMax = i;
   return indexOfMax;
}
template<class T>
void selectionSort(T a[], int n)
{// Sort the n elements a[0:n-1].
   for (int size = n; size > 1; size--)
   {
      int j = indexOfMax(a, size);
      swap(a[j], a[size - 1]);
   }
}
int main()
{
   int a[10] = {3, 2, 4, 1, 6, 9, 8, 7, 5, 0};

   // output the elements
   cout << "a[0:9] = ";
   copy(a, a+10, ostream_iterator<int>(cout, " "));
   cout << endl;

   // sort
   selectionSort(a,10);

   // output the sorted sequence
   cout << "After the sort, a[0:9] = ";
   copy(a, a+10, ostream_iterator<int>(cout, " "));
   cout << endl;
   return 0;
}
