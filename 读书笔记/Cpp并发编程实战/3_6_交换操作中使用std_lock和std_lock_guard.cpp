#include <mutex>

class some_big_object;
void swap(some_big_object &lhs, some_big_object &rhs);
class X {
private:
    some_big_object some_detail;
    std::mutex m;

public:
    X(some_big_object const &sd) : some_detail(sd) {}

    friend void swap(X &lhs, X &rhs)
    {
        if (&lhs == &rhs) // 检查参数是否是不同的实例，因为操作试图获取std::mutex对象上的锁，所以当其被获取时，结果很难预料
            return;
        std::lock(lhs.m, rhs.m);                                    // 1 调用std::lock()锁住两个互斥量
        std::lock_guard<std::mutex> lock_a(lhs.m,std::adopt_lock);  // 2 std::adopt_lock参数除了表示std::lock_guard对象可获取锁之外，
        std::lock_guard<std::mutex> lock_b(rhs.m, std::adopt_lock); // 3 还将锁交由std::lock_guard对象管理，而不需要std::lock_guard对象再去构建新的锁。
        swap(lhs.some_detail, rhs.some_detail);
    }
};