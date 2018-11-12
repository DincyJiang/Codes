#include <iostream>
#include <thread> // 管理线程的函数和类在<thread>中声明

void hello() { // 每个线程都必须具有一个初始函数(initial function)，新线程的执行从这里开始。
    std::cout << "Hello, Concurrent World" << std::endl;
}

int main() { // 对于应用程序来说，初始线程是main()
    std::thread t(hello); // std::thread对象 t 拥有新函数hello()作为其初始函数。
    t.join(); // 调用线程(在main()中)等待与std::thread对象 t 相关联的线程
    return 0;
}