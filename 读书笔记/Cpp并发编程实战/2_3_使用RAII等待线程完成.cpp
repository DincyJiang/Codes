#include <thread>

class thread_guard {
private:
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_) : t(t_) {}
    ~thread_guard() {
        if (t.joinable()) t.join();
    }
    // 拷贝构造函数和拷贝赋值操作被标记为=delete，是为了不让编译器自动生成它们。
    // 直接对一个对象进行拷贝或赋值是危险的，因为这可能会弄丢已经加入的线程。
    thread_guard(const thread_guard &) = delete;
    thread_guard& operator=(const thread_guard&) = delete;
};

struct func;

void f() {
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread t(my_func);
    thread_guard g(t); // thread_guard对象g是第一个被销毁的，这时线程在析构函数中被加入到原始线程中。
    do_something_in_current_thread();
} // 当线程执行到此处时，局部对象就要被逆序销毁了。