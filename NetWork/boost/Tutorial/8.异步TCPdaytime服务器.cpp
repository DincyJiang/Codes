#include <ctime>
#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

// 创建要发送回客户端的字符串
std::string make_daytime_string() {
    using namespace std;
    time_t now = time(0);
    return ctime(&now);
}

class tcp_connection
    : public boost::enable_shared_from_this<tcp_connection>
{
public:
    typedef boost::shared_ptr<tcp_connection> pointer;
    static pointer create(boost::asio::io_context& io_context) {
        return pointer(new tcp_connection(io_context));
    }
    tcp::socket& socket() {
        return socket_;
    }
    // 在函数中start()，我们调用boost :: asio :: async_write（）来将数据提供给客户端。
    void start() {
        // 要发送的数据存储在类成员中，message_因为我们需要保持数据有效，直到异步操作完成。
        message_ = make_daytime_string();
        // 在启动异步操作时，如果使用boost :: bind（），则必须仅指定与处理程序的参数列表匹配的参数。
        boost::asio::async_write(socket_, boost::asio::buffer(message_),
            boost::bind(&tcp_connection::handle_write, shared_from_this(),
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
    }
private:
    tcp_connection(boost::asio::io_context& io_context) : socket_(io_context) {

    }
    // 此客户端连接的任何进一步操作现在都是由此负责的handle_write()。
    void handle_write(const boost::system::error_code& /*error*/, size_t /*bytes_transferred*/) {

    }
    tcp::socket socket_;
    std::string message_;
};

class tcp_server {
public:
    // 构造函数初始化一个接受器以侦听TCP端口13。
    tcp_server(boost::asio::io_context& io_context) 
        : acceptor_(io_context, tcp::endpoint(tcp::v4(), 13))
    {   
        start_accept();
    }
private:
    // 该函数start_accept()创建一个套接字并启动异步接受操作以等待新连接。
    void start_accept() {
        tcp_connection::pointer new_connection =
            tcp_connection::create(acceptor_.get_executor().context());
        
        acceptor_.async_accept(new_connection->socket(),
            boost::bind(&tcp_server::handle_accept, this, new_connection,
            boost::asio::placeholders::error));
    }
    // 完成handle_accept()启动的异步接受操作时调用 该函数start_accept()。它为客户端请求提供服务，然后调用start_accept()以启动下一个接受操作。
    void handle_accept(tcp_connection::pointer new_connection,
        const boost::system::error_code& error) {
        if (!error)
            new_connection->start();
        start_accept();
    }
    tcp::acceptor acceptor_;
};

int main() {
    try {
        boost::asio::io_context io_context;
        tcp_server server(io_context);

        io_context.run();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}