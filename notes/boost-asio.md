官方教程：https://www.boost.org/doc/libs/1_68_0/doc/html/boost_asio/tutorial.html

1.同步使用定时器

#include <iostream>
#include <boost/asio.hpp>

int main() {
    boost::asio::io_context io; // 使用asio的所有程序都需要至少有一个io_context 对象。
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5)); // 对计时器执行阻塞等待。
    t.wait(); // 调用steady_timer :: wait（）函数
    std::cout << "Hello, world" << std::endl;
    return 0;
}
编译：g++ test.cpp -o test -lboost_system -lboost_chrono

2.异步使用定时器

#include <iostream>
#include <boost/asio.hpp>

// 在异步等待完成时调用的函数。
void print(const boost::system::error_code& /*e*/) {
    std::cout << "Hello, world!" << std::endl;
}

int main() {
    boost::asio::io_context io;
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
    t.async_wait(print); // 调用steady_timer :: async_wait（） 函数来执行异步等待

    // asio库提供了一种保证，即只能从当前调用io_context :: run（）的线程调用回调处理程序。
    // 因此，除非调用io_context :: run（） 函数，否则永远不会调用异步等待完成的回调。
    io.run();
    return 0;
}
编译：g++ test.cpp -o test -lboost_system -lboost_chrono

3.将参数绑定到处理程序

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

void print(const boost::system::error_code& /*e*/,
    boost::asio::steady_timer *t, // 指向计时器对象的指针
    int *count) // 计数器，以便我们可以在计时器第六次触发时停止程序。
{
    if (*count < 5) {
        std::cout << *count << std::endl;
        ++(*count);
        // 将计时器的到期时间从前一个到期时间开始移动一秒钟。
        t->expires_at(t->expiry() + boost::asio::chrono::seconds(1));
        // 然后我们在计时器上启动一个新的异步等待。
        t->async_wait(boost::bind(print,
            boost::asio::placeholders::error, t, count)); // 必须仅指定与处理程序的参数列表匹配的参数
    }
}

int main() {
    boost::asio::io_context io;
    int count = 0;
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(1));
    t.async_wait(boost::bind(print,
        boost::asio::placeholders::error, &t, &count));
    io.run();
    std::cout << "Final count is " << count << std::endl;
    return 0;
}
编译：g++ test.cpp -o test -lboost_system -lboost_chrono

4.使用成员函数作为处理程序

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

class printer {
public:
    printer(boost::asio::io_context& io)
        : timer_(io, boost::asio::chrono::seconds(1)),
          count_(0)
    {
        timer_.async_wait(boost::bind(&printer::print, this));
    }
    ~printer() {
        std::cout << "Final count is " << count_ << std::endl;
    }
    void print() {
        if (count_ < 5) {
            std::cout << count_ << std::endl;
            ++count_;
            timer_.expires_at(timer_.expiry() + boost::asio::chrono::seconds(1));
            timer_.async_wait(boost::bind(&printer::print, this));
        }
    }
private:
    boost::asio::steady_timer timer_;
    int count_;
};

int main() {
    boost::asio::io_context io;
    printer p(io);
    io.run();
    return 0;
}
编译：g++ test.cpp -o test -lboost_system -lboost_chrono

5.同步多线程程序中的处理程序

#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>

class printer {
public:
    printer(boost::asio::io_context& io)
        : strand_(io),
          timer1_(io, boost::asio::chrono::seconds(1)),
          timer2_(io, boost::asio::chrono::seconds(1)),
          count_(0)
    {
        // 在启动异步操作时，每个回调处理程序都“绑定”到io_context :: strand 对象。
        // boost :: asio :: io_context :: strand :: bind_executor（）函数返回一个新的处理程序，
        // 它通过io_context :: strand 对象自动调度其包含的处理程序。
        // 通过将处理程序绑定到同一个io_context :: strand，我们确保它们不能并发执行。
        timer1_.async_wait(boost::asio::bind_executor(strand_,
            boost::bind(&printer::print1, this)));
        timer2_.async_wait(boost::asio::bind_executor(strand_,
            boost::bind(&printer::print2, this)));
    }
    ~printer() {
        std::cout << "Final count is " << count_ << std::endl;
    }
    void print1() {
        if (count_ < 10) {
            std::cout << "Timer 1: " << count_ << std::endl;
            ++count_;
            timer1_.expires_at(timer1_.expiry() + boost::asio::chrono::seconds(1));
            timer1_.async_wait(boost::asio::bind_executor(strand_,
                boost::bind(&printer::print1, this)));
        }
    }
    void print2() {
        if (count_ < 10) {
            std::cout << "Timer 2: " << count_ << std::endl;
            ++count_;
            timer2_.expires_at(timer2_.expiry() + boost::asio::chrono::seconds(1));
            timer2_.async_wait(boost::asio::bind_executor(strand_,
                boost::bind(&printer::print2, this)));
        }
    }
private:
    // 一个io_context::strand 是保证，对于通过它来分派的处理程序，正在执行的处理程序将允许进入下一个开始之前完成执行。
    // 无论调用io_context :: run（）的线程数是多少，都可以保证这一点。
    boost::asio::io_context::strand strand_;
    boost::asio::steady_timer timer1_;
    boost::asio::steady_timer timer2_;
    int count_;
};

int main() {
    // 从两个线程调用io_context :: run（）：主线程和一个额外线程。这是使用boost :: thread对象完成的。
    // 就像从单个线程调用一样，对io_context :: run（）的并发调用将继续执行，同时还有“工作”要做。
    // 在完成所有异步操作之前，后台线程不会退出。
    boost::asio::io_context io;
    printer p(io);
    boost::thread t(boost::bind(&boost::asio::io_context::run, &io));
    io.run();
    t.join();
    return 0;
}
编译：g++ test.cpp -o test -lboost_system -lboost_chrono -lboost_thread

6.
