官方教程：https://www.boost.org/doc/libs/1_68_0/doc/html/boost_asio/tutorial.html

1.同步使用定时器

```c++
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
```

2.异步使用定时器

```c++
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
```

3.将参数绑定到处理程序

```c++
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
```

4.使用成员函数作为处理程序

```c++
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
```

5.同步多线程程序中的处理程序

```c++
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
```

6.同步TCPdaytime客户端

```c++
#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(int argc, char* argv[]) {
    try { // 需要用户指定服务器，访问daytime服务
        if (argc != 2) {
            std::cerr << "Usage: client <host>" << std::endl;
            return 1;
        }
        boost::asio::io_context io_context;

        // 将指定为参数的服务器名称转换为TCP端点
        tcp::resolver resolver(io_context); 
        tcp::resolver::results_type endpoints = resolver.resolve(argv[1], "daytime");

        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);

        for (;;) {
            boost::array<char, 128> buf;
            boost::system::error_code error;

            //boost :: asio :: buffer（）函数自动确定数组的大小，以帮助防止缓冲区溢出。
            size_t len = socket.read_some(boost::asio::buffer(buf), error);

            if (error == boost::asio::error::eof) // 当服务器关闭连接时，ip :: tcp :: socket :: read_some（） 函数将以boost :: asio :: error :: eof错误退出，
                break; // 正常关闭
            else if (error)
                throw boost::system::system_error(error); // 其他错误
            
            std::cout.write(buf.data(), len);
        }
    } catch (std::exception& e) { // 处理可能抛出的任何异常。
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
编译：g++ client.cpp -o client -lboost_system
运行：./client localhost
```

7.同步TCPdaytime服务端

```c++
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

        // 一个ip::tcp::acceptor 对象需要来监听新的连接。它被初始化为侦听TCP端口8991，用于IP版本4。
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
编译：g++ server.cpp -o server -lboost_system
运行：sudo ./server
问题：bind: Address already in use，端口被占用
解决办法：换个端口号，或者找到占用该端口的进程然后杀死进程
```

8.异步TCPdaytime服务端

```c++
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
编译：g++ server.cpp -o server -lboost_system
```

9.同步UDPdaytime客户端

```c++

```

10.同步UDPdaytime服务端

```c++

```
