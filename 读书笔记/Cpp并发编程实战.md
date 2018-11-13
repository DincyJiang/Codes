gitbook地址：https://chenxiaowei.gitbooks.io/cpp_concurrency_in_action/content/

## 第1章 你好，C++的并发世界!

### 1.1 何谓并发

最简单和最基本的并发,是指两个或更多独立的活动同时发生。

#### 1.1.1 计算机系统中的并发

计算机领域的并发指的是在单个系统里同时执行多个独立的任务，而非顺序的进行一些活动。

任务切换：只有一个处理器的计算机只能在某一时刻执行一个任务，不过它可以每秒进行多次任务切换。通过“这个任务做一会，再切换到别的任务，再做一会儿”的方式，让任务看起来是并行执行的。任务切换会给用户和应用程序造成一种“并发的假象”。

硬件并发：多处理器计算机用于服务器和高性能计算已有多年。基于单芯多核处理器(多核处理器)的台式机，也越来越大众化。无论拥有几个处理器，这些机器都能够真正的并行多个任务。

#### 1.1.2 并发的途径

多进程并发

多线程并发（本书讨论）

### 1.2 为什么使用并发？

主要原因有两个：关注点分离(SOC)和性能。

#### 1.2.1 为了分离关注点

编写软件时，分离关注点是个好主意；通过将相关的代码与无关的代码分离，可以使程序更容易理解和测试，从而减少出错的可能性。

#### 1.2.2 为了性能

两种方式利用并发提高性能：

第一，将一个单个任务分成几部分，且各自并行运行，从而降低总运行时间。这就是任务并行（task parallelism）。

第二，每个线程在不同的数据部分上执行相同的操作。这就是数据并行（data parallelism）。

#### 1.2.3 什么时候不使用并发

基本上，不使用并发的唯一原因就是，收益比不上成本。

### 1.3 C++中的并发和多线程

只有在C++11标准下，才能编写不依赖平台扩展的多线程代码。

#### 1.3.1 C++多线程历史

C++98(1998)标准不承认线程的存在。有一些与平台无关的C++类库(例如:Boost和ACE)。缺乏统一标准的支持。

#### 1.3.2 新标准支持并发

#### 1.3.3 C++线程库的效率

在实现相同功能的前提下，直接使用底层API并不会带来过多的性能收益。

#### 1.3.4 平台相关的工具

C++线程库中提供一个native_handle()成员函数，允许通过使用平台相关API直接操作底层实现。

### 1.4 开始入门

#### 1.4.1 你好，并发世界

```c
#include <iostream>
#include <thread> // 管理线程的函数和类在<thread>中声明

void hello() { // 每个线程都必须具有一个初始函数(initial function)，新线程的执行从这里开始。
    std::cout << "Hello, Concurrent World" << std::endl;
}

int main() { // 对于应用程序来说，初始线程是main()
    std::thread t(hello); // std::thread对象 t 拥有新函数hello()作为其初始函数。
    t.join(); // 调用线程(在main()中)等待与std::thread对象 t 相关联的线程
    return 0;
}
```

### 1.5 本章总结

本章中，提及了并发与多线程的含义,以及在你的应用程序中为什么你会选择使用(或不使用)它。还提及了多线程在C++中的发展历程，从1998标准中完全缺乏支持，经历了各种平台相关的扩展，再到新的C++11标准中具有合适的多线程支持。芯片制造商选择了以多核心的形式，使得更多任务可以同时执行的方式来增加处理能力，而不是增加单个核心的执行速度。在这个趋势下，C++多线程来的正是时候，它使得程序员们可以利用新的CPU，带来的更加强大的硬件并发。

使用1.4节中例子，展示C++标准库中的类和函数有多么的简单。C++中使用多线程并不复杂，复杂的是如何设计代码以实现其预期的行为。

## 第2章 线程管理

### 2.1 线程管理的基础

每个程序至少有一个线程：执行main()函数的线程，其余线程有其各自的入口函数。

#### 2.1.1 启动线程

使用C++线程库启动线程，可以归结为构造std::thread对象。

如同大多数C++标准库一样，std::thread可以用可调用类型构造，将带有函数调用符类型的实例传入std::thread类中，替换默认的构造函数。

注意：如果你传递了一个临时变量，而不是一个命名的变量；C++编译器会将其解析为函数声明，而不是类型对象的定义。例如：

```c
std::thread my_thread(background_task());
```

使用新统一的初始化语法可以避免这个问题。

```c
std::thread my_thread{background_task()};
```

使用lambda表达式也能避免这个问题。

```c
std::thread my_thread([]{
  do_something();
  do_something_else();
});
```

启动了线程，你需要明确是要等待线程结束，还是让其自主运行。

如果不等待线程，就必须保证线程结束之前，可访问的数据得有效性。

```c
#include <thread>

void do_something(int& i) {}

struct func {
    int &i;
    func(int& i_) : i(i_) {}
    void operator() () {
        for (unsigned j = 0; j < 1000000; ++j) {
            do_something(i); // 潜在访问隐患：悬空引用
        }
    }
};

void oops() {
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread my_thread(my_func);
    my_thread.detach(); // 不等待线程结束
} // 新线程可能还在运行
```

#### 2.1.2 等待线程完成

如果需要等待线程，相关的std::thread实例需要使用join()。

join()是简单粗暴的等待线程完成或不等待。当你需要对等待中的线程有更灵活的控制时，需要使用其他机制来完成，比如条件变量和期待(futures).

调用join()的行为，还清理了线程相关的存储部分，这样std::thread对象将不再与已经完成的线程有任何关联。这意味着，只能对一个线程使用一次join().

#### 2.1.3 特殊情况下的等待

避免应用被抛出的异常所终止，就需要作出一个决定。通常，当倾向于在无异常的情况下使用join()时，需要在异常处理过程中调用join()，从而避免生命周期的问题。

```c
#include <thread>

struct func;

void f() {
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread t(my_func);

    // 使用了try/catch块确保访问本地状态的线程退出后，函数才结束。
    try {
        do_something_in_current_thread();
    } catch(...) {
        t.join(); // 当函数执行过程中抛出异常
        throw;
    }
    t.join(); // 当函数正常退出时
}
```

一种方式是使用“资源获取即初始化方式”(RAII，Resource Acquisition Is Initialization)，并且提供一个类，在析构函数中使用join().

```c
#include <thread>

class thread_guard {
private:
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_) : t(t_) {}
    ~thread_guard() {
        if (t.joinable()) t.join();
    }
    // 拷贝构造函数和拷贝赋值操作被标记为=delete，是为了不让编译器自动生成它们。
    // 直接对一个对象进行拷贝或赋值是危险的，因为这可能会弄丢已经加入的线程。
    thread_guard(const thread_guard &) = delete;
    thread_guard& operator=(const thread_guard&) = delete;
};

struct func;

void f() {
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread t(my_func);
    thread_guard g(t); // thread_guard对象g是第一个被销毁的，这时线程在析构函数中被加入到原始线程中。
    do_something_in_current_thread();
} // 当线程执行到此处时，局部对象就要被逆序销毁了。
```

#### 2.1.4 后台运行线程

使用detach()会让线程在后台运行，这就意味着主线程不能与之产生直接交互。

不过C++运行库保证，当线程退出时，相关资源的能够正确回收，后台线程的归属和控制C++运行库都会处理。

通常称分离线程为守护线程(daemon threads),UNIX中守护线程是指，没有任何显式的用户接口，并在后台运行的线程。这种线程的特点就是长时间运行；线程的生命周期可能会从某一个应用起始到结束，可能会在后台监视文件系统，还有可能对缓存进行清理，亦或对数据结构进行优化。另一方面，分离线程的另一方面只能确定线程什么时候结束，发后即忘(fire and forget)的任务就使用到线程的这种方式。

使用分离线程去处理其他文档:

```c
void edit_document(std::string const& filename) {
    open_document_and_display_gui(filename);

    while (!done_editing()) {
        user_command cmd = get_user_input();
        if (cmd.type == open_new_document) {
            std::string const new_name = get_filename_from_user();
            std::thread t(edit_document, new_name);  // 如果用户选择打开一个新文档，需要启动一个新线程去打开新文档
            t.detach();  // 并分离线程
        } else {
            process_user_input(cmd);
        }
    }
}
```

### 2.2 向线程函数传递参数

默认参数要拷贝到线程独立内存中，即使参数是引用的形式，也可以在新线程中进行访问：

```c
void f(int i, std::string const& s);
std::thread t(f, 3, "hello");
```

在传递到std::thread构造函数之前就将字面值转化为std::string对象，不要依赖隐式转换：

```c
std::thread t(f,3,std::string(buffer));  // 使用std::string，避免悬垂指针
```

可以使用std::ref将参数转换成引用的形式：

```c
std::thread t(update_data_for_widget,w,std::ref(data));
```

可以传递一个成员函数指针作为线程函数，并提供一个合适的对象指针作为第一个参数：

```c
class X;
X my_x;
std::thread t(&X::do_lengthy_work,&my_x);
```

std::thread构造函数的第三个参数就是成员函数的第一个参数：

```c
int num(0);
std::thread t(&X::do_lengthy_work, &my_x, num);
```

提供的参数可以移动，但不能拷贝：

```c
void process_big_object(std::unique_ptr<big_object>);
std::unique_ptr<big_object> p(new big_object);
p->prepare_data(42);
std::thread t(process_big_object, std::move(p)); // p的所有权就被首先转移到新创建线程的的内部存储中，之后传递给process_big_object函数。
```
























