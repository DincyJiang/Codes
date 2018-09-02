/*
桶排序
时间复杂度：平均O(n+k),最坏O(n2)

桶排序是计数排序的升级版。它利用了函数的映射关系，高效与否的关键就在于这个映射函数的确定。
桶排序 (Bucket sort)的工作的原理：假设输入数据服从均匀分布，将数据分到有限数量的桶里，
每个桶再分别排序（有可能再使用别的排序算法或是以递归方式继续使用桶排序进行排）。

算法描述
设置一个定量的数组当作空桶；
遍历输入数据，并且把数据一个一个放到对应的桶里去；
对每个不是空的桶进行排序；
从不是空的桶里把排好序的数据拼接起来。 
桶排序最好情况下使用线性时间O(n)，桶排序的时间复杂度，取决与对各个桶之间数据进行排序的时间复杂度，
因为其它部分的时间复杂度都为O(n)。很显然，桶划分的越小，各个桶之间的数据越少，
排序所用的时间也会越少。但相应的空间消耗就会增大。 


*/

#include <iostream>
#include <iomanip>
using namespace std;

#define NARRAY 8  /* array size */
#define NBUCKET 5 /* bucket size */
#define INTERVAL 10 /* bucket range */

struct Node 
{ 
    int data;  
    struct Node *next; 
};

void BucketSort(int arr[]);
struct Node *InsertionSort(struct Node *list);
void print(int arr[]);
void printBuckets(struct Node *list);
int getBucketIndex(int value);

void BucketSort(int arr[])
{   
    int i,j;
    struct Node **buckets;  

    /* allocate memory for array of pointers to the buckets */
    buckets = (struct Node **)malloc(sizeof(struct Node*) * NBUCKET); 

    /* initialize pointers to the buckets */
    for(i = 0; i < NBUCKET;++i) {  
        buckets[i] = NULL;
    }

    /* put items into the buckets */
    for(i = 0; i < NARRAY; ++i) {   
        struct Node *current;
        int pos = getBucketIndex(arr[i]);
        current = (struct Node *) malloc(sizeof(struct Node));
        current->data = arr[i]; 
        current->next = buckets[pos];  
        buckets[pos] = current;
    }

    /* check what's in each bucket */
    for(i = 0; i < NBUCKET; i++) {
        cout << "Bucket[" << i << "] : ";
            printBuckets(buckets[i]);
        cout << endl;
    }

    /* sorting bucket using Insertion Sort */
    for(i = 0; i < NBUCKET; ++i) {  
        buckets[i] = InsertionSort(buckets[i]); 
    }

    /* check what's in each bucket */
    cout << "-------------" << endl;
    cout << "Bucktets after sorted" << endl;
    for(i = 0; i < NBUCKET; i++) {
        cout << "Bucket[" << i << "] : ";
            printBuckets(buckets[i]);
        cout << endl;
    }

    /* put items back to original array */
    for(j =0, i = 0; i < NBUCKET; ++i) {    
        struct Node *node;
        node = buckets[i];
        while(node) {
            arr[j++] = node->data;
            node = node->next;
        }
    }

    /* free memory */
    for(i = 0; i < NBUCKET;++i) {   
        struct Node *node;
        node = buckets[i];
        while(node) {
            struct Node *tmp;
            tmp = node; 
            node = node->next; 
            free(tmp);
        }
    }
    free(buckets); 
    return;
}

/* Insertion Sort */
struct Node *InsertionSort(struct Node *list)
{   
    struct Node *k,*nodeList;
    /* need at least two items to sort */
    if(list == 0 || list->next == 0) { 
        return list; 
    }

    nodeList = list; 
    k = list->next; 
    nodeList->next = 0; /* 1st node is new list */
    while(k != 0) { 
        struct Node *ptr;
        /* check if insert before first */
        if(nodeList->data > k->data)  { 
            struct Node *tmp;
            tmp = k;  
            k = k->next; 
            tmp->next = nodeList;
            nodeList = tmp; 
            continue;
        }

        for(ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
            if(ptr->next->data > k->data) break;
        }

        if(ptr->next!=0){  
            struct Node *tmp;
            tmp = k;  
            k = k->next; 
            tmp->next = ptr->next;
            ptr->next = tmp; 
            continue;
        }
        else{
            ptr->next = k;  
            k = k->next;  
            ptr->next->next = 0; 
            continue;
        }
    }
    return nodeList;
}

int getBucketIndex(int value)
{
    return value/INTERVAL;
}

void print(int ar[])
{   
    int i;
    for(i = 0; i < NARRAY; ++i) { 
        cout << setw(3) << ar[i]; 
    }
    cout << endl;
}

void printBuckets(struct Node *list)
{
    struct Node *cur = list;
    while(cur) {
        cout << setw(3) << cur->data;
        cur = cur->next;
    }
}

int main(void)
{   
    int array[NARRAY] = {29,25,3,49,9,37,21,43};

    cout << "Initial array" << endl;
    print(array);
    cout << "-------------" << endl;

    BucketSort(array); 
    cout << "-------------" << endl;
    cout << "Sorted array"  << endl;
    print(array); 
    return 0;
}