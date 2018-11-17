#include <iostream>
#include <boost/asio.hpp>

int main() {
    boost::asio::io_context io; // 使用asio的所有程序都需要至少有一个io_context 对象。
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5)); // 对计时器执行阻塞等待。
    t.wait(); // 调用steady_timer :: wait（）函数
    std::cout << "Hello, world" << std::endl;
    return 0;
}