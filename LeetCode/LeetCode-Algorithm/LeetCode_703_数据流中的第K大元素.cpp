// 设计一个找到数据流中第K大元素的类（class）。注意是排序后的第K大元素，不是第K个不同的元素。

// 你的 KthLargest 类需要一个同时接收整数 k 和整数数组nums 的构造器，它包含数据流中的初始元素。每次调用 KthLargest.add，返回当前数据流中第K大的元素。

// 示例:

// int k = 3;
// int[] arr = [4,5,8,2];
// KthLargest kthLargest = new KthLargest(3, arr);
// kthLargest.add(3);   // returns 4
// kthLargest.add(5);   // returns 5
// kthLargest.add(10);  // returns 5
// kthLargest.add(9);   // returns 8
// kthLargest.add(4);   // returns 8
// 说明: 
// 你可以假设 nums 的长度≥ k-1 且k ≥ 1。

#include <vector>
#include <queue>

using namespace std;

// 最大堆
class KthLargest {
public:
    KthLargest(int k, vector<int> nums) {
        for (int &num : nums) {
            q.push(num);
            if (q.size() > k) q.pop();
        }
        K = k;
    }
    
    int add(int val) {
        q.push(val);
        if (q.size() > K) q.pop();
        return q.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> q{}; // 最小堆，里面保存的是前K大个数
    int K;
};
