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