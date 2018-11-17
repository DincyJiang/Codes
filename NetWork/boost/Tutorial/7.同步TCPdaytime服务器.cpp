#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

// 创建要发送回客户端的字符串
std::string make_daytime_string() {
    using namespace std;
    time_t now = time(0);
    return ctime(&now);
}

int main() {
    try {
        boost::asio::io_context io_context;

        // 一个ip::tcp::acceptor 对象需要来监听新的连接。它被初始化为侦听TCP端口13，用于IP版本4。
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 8991));

        // 这是一个迭代服务器，这意味着它将一次处理一个连接。创建一个代表与客户端连接的套接字，然后等待连接。
        for (;;) {
            tcp::socket socket(io_context);
            acceptor.accept(socket);

            // 客户正在访问我们的服务。确定当前时间并将此信息传输到客户端。
            std::string message = make_daytime_string();

            boost::system::error_code ignored_error;
            boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}