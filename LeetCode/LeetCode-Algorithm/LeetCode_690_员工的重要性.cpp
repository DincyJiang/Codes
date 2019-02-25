// 给定一个保存员工信息的数据结构，它包含了员工唯一的id，重要度 和 直系下属的id。

// 比如，员工1是员工2的领导，员工2是员工3的领导。他们相应的重要度为15, 10, 5。那么员工1的数据结构是[1, 15, [2]]，员工2的数据结构是[2, 10, [3]]，员工3的数据结构是[3, 5, []]。注意虽然员工3也是员工1的一个下属，但是由于并不是直系下属，因此没有体现在员工1的数据结构中。

// 现在输入一个公司的所有员工信息，以及单个员工id，返回这个员工和他所有下属的重要度之和。

// 示例 1:

// 输入: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
// 输出: 11
// 解释:
// 员工1自身的重要度是5，他有两个直系下属2和3，而且2和3的重要度均为3。因此员工1的总重要度是 5 + 3 + 3 = 11。
// 注意:

// 一个员工最多有一个直系领导，但是可以有多个直系下属
// 员工数量不超过2000。

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

// 所有下属：直系下属+子下属
class Solution1 {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_set<int> s{};
        unordered_map<int, Employee*> hash{};
        for (auto &employee : employees)
            hash[employee->id] = employee;
        return func(id, hash, s);
    }
    int func(int id, unordered_map<int, Employee*>& hash, unordered_set<int>& s) {
        if (s.count(id)) return 0; // 该员工已经计算过
        s.insert(id);
        int res = hash[id]->importance;
        for (int &num : hash[id]->subordinates) { // 对所有下属累计重要度
            res += func(num, hash, s);
        }
        return res;
    }
};

// BFS, 用queue
class Solution2 {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int res{0};
        queue<int> q{{id}};
        unordered_set<int> s{};
        unordered_map<int, Employee*> hash{};
        for (auto &e : employees)
            hash[e->id] = e;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (s.count(t)) continue; // 该员工已经计算过
            s.insert(t);
            res += hash[t]->importance;
            for (int &num : hash[t]->subordinates) {
                q.push(num);
            }
        }
        return res;
    }
};