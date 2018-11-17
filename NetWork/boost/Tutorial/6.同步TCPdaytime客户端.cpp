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