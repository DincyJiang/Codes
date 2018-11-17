#include <ctime>
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

std::string make_daytime_string() {
    using namespace std;
    time_t now = time(0);
    return ctime(&now);
}

class udp_server {
public:
    udp_server(boost::asio::io_context& io_context)
        : socket_(io_context, udp::endpoint(udp::v4(), 13))
    {
        start_receive();
    }
private:
    void start_receive() {
        // 函数ip :: udp :: socket :: async_receive_from（） 将使应用程序在后台侦听新请求。
        // 当接收到这样的请求时，io_context 对象将调用handle_receive()函数
        socket_.async_receive_from(
            boost::asio::buffer(recv_buffer_), remote_endpoint_,
            boost::bind(&udp_server::handle_receive, this,
                boost::asio::placeholders::error,
                boost::asio::placeholders::bytes_transferred)
        );
    }
    // 该功能handle_receive()将为客户端请求提供服务。
    void handle_receive(const boost::system::error_code* error,
        std::size_t /*bytes_transferred*/) {
        if (!error) {
            boost::shared_ptr<std::string> message(
                new std::string(make_daytime_string())
            );
            // 调用ip :: udp :: socket :: async_send_to（） 来向客户端提供数据。
            socket_.async_send_to(boost::asio::buffer(*message), remote_endpoint_,
                boost::bind(&udp_server::handle_send, this, message,
                    boost::asio::placeholders::error,
                    boost::asio::placeholders::bytes_transferred
                )
            );
            start_receive(); // 开始侦听下一个客户端请求。
        }
    }
    void handle_send(boost::shared_ptr<std::string> /*message*/,
        const boost::system::error_code& /*error*/,
        std::size_t /*bytes_transferred*/) {

    }
    udp::socket socket_;
    udp::endpoint remote_endpoint_;
    boost::array<char, 1> recv_buffer_;
};

int main() {
    try {
        boost::asio::io_context io_context;
        udp_server server(io_context);
        io_context.run();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}