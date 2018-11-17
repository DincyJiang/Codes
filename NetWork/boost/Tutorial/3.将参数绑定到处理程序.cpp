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