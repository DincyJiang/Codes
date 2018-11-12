#include <thread>

struct func;

void f() {
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread t(my_func);

    // 使用了try/catch块确保访问本地状态的线程退出后，函数才结束。
    try {
        do_something_in_current_thread();
    } catch(...) {
        t.join(); // 当函数执行过程中抛出异常
        throw;
    }
    t.join(); // 当函数正常退出时
}