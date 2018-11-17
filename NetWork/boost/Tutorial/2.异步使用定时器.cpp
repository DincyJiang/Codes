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
