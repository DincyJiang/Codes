// 不使用任何内建的哈希表库设计一个哈希集合

// 具体地说，你的设计应该包含以下的功能

// add(value)：向哈希集合中插入一个值。
// contains(value) ：返回哈希集合中是否存在这个值。
// remove(value)：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。

// 示例:

// MyHashSet hashSet = new MyHashSet();
// hashSet.add(1);         
// hashSet.add(2);         
// hashSet.contains(1);    // 返回 true
// hashSet.contains(3);    // 返回 false (未找到)
// hashSet.add(2);          
// hashSet.contains(2);    // 返回 true
// hashSet.remove(2);          
// hashSet.contains(2);    // 返回  false (已经被删除)

// 注意：

// 所有的值都在 [1, 1000000]的范围内。
// 操作的总数目在[1, 10000]范围内。
// 不要使用内建的哈希集合库。

#include <vector>

using namespace std;

// 数字范围不会超过1000000，就使用一个1000000的数组来存放
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        data.resize(1000000, false);
    }
    
    void add(int key) {
        data[key] = true;
    }
    
    void remove(int key) {
        data[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return data[key] == true;
    }
private:
    vector<bool> data{}; // data中存放的是是否有这个值
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */