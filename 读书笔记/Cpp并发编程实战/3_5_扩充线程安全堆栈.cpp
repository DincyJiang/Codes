#include <exception>
#include <memory>
#include <mutex>
#include <stack>
struct empty_stack : std::exception {
    const char *what() const throw() {
        return "empty stack!";
    };
};
template <typename T>
class threadsafe_stack {
private:
    std::stack<T> data;
    mutable std::mutex m;
public:
    threadsafe_stack()
        : data(std::stack<T>()) {}
    threadsafe_stack(const threadsafe_stack &other) {
        std::lock_guard<std::mutex> lock(other.m); // 拷贝构造函数对互斥量上锁
        data = other.data; // 1 在构造函数体中的执行拷贝
    }
    threadsafe_stack &operator=(const threadsafe_stack &) = delete;
    void push(T new_value) {
        std::lock_guard<std::mutex> lock(m);
        data.push(new_value);
    }
    std::shared_ptr<T> pop() {
        std::lock_guard<std::mutex> lock(m);
        if (data.empty())
            throw empty_stack(); // 在调用pop前，检查栈是否为空
        std::shared_ptr<T> const res(std::make_shared<T>(data.top())); // 在修改堆栈前，分配出返回值
        data.pop();
        return res;
    }
    void pop(T &value) {
        std::lock_guard<std::mutex> lock(m);
        if (data.empty())
            throw empty_stack();
        value = data.top();
        data.pop();
    }
    bool empty() const {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
};
