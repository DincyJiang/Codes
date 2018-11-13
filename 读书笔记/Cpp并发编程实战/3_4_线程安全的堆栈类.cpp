#include <exception>
#include <memory> // For std::shared_ptr<>


struct empty_stack : std::exception {
    const char *what() const throw();
};
template <typename T>
class threadsafe_stack {
public:
    threadsafe_stack();
    threadsafe_stack(const threadsafe_stack &);
    threadsafe_stack &operator=(const threadsafe_stack &) = delete; // 1 赋值操作被删除
    void push(T new_value);
    std::shared_ptr<T> pop(); // 重载了pop()，使用一个局部引用去存储弹出值，并返回一个 std::shared_ptr<> 对象
    void pop(T &value);
    bool empty() const;
};