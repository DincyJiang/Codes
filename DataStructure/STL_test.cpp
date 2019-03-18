#include <algorithm>
#include <iostream>
#include <list>

using std::cout;
using std::endl;

int main() {
    // list列表
    std::list<int> l{7, 5, 16, 8}; // 7 5 16 8
    l.push_front(25); // 25 7 5 16 8
    l.push_back(13); // 25 7 5 16 8 13
    // 找到16的所在的迭代器，在前面插入一个数
    auto it = std::find(l.begin(), l.end(), 16);
    if (it != l.end()) {
        l.insert(it, 42); // 25 7 5 42 16 8 13
    }
    // 打印出列表中所有数字
    for (int num : l) {
        cout << num << ' ';
    }
    cout << endl;
    cout << "l的第一个数: " << l.front() << endl; // 25
    cout << "l的最后一个数: " << l.back() << endl; // 13
    cout << "l中有几个数字: " << l.size() << endl; // 7
    if (!l.empty()) {
        l.clear();
    }













    return 0;
}