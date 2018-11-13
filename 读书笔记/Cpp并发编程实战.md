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
std::thread t(&X::do_lengthy_work, &my_x);
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

### 2.3 转移线程所有权

执行线程的所有权可以在std::thread实例中移动：

```c
void some_function();
void some_other_function();
std::thread t1(some_function);          // 创建新线程t1
std::thread t2=std::move(t1);           // 把t1的所有权转移给t2，执行some_function的函数现在与t2关联
t1=std::thread(some_other_function);    // 
std::thread t3;                         // 创建临时std::thread对象t3
t3=std::move(t2);                       // 把t2的所有权转移给t3，执行some_function的函数现在与t3关联
t1=std::move(t3);                       // 赋值操作将使程序崩溃
```

函数返回std::thread对象：

```c
std::thread f() {
    void some_function();
    return std::thread(some_function);
}
std::thread g() {
    void some_other_function(int);
    std::thread t(some_other_function, 42);
    return t;
}
```

允许std::string实例可作为参数进行传递：

```c
void f(std::thread t);
void g() {
    void some_function();
    f(std::thread(some_function));
    std::thread t(some_function);
    f(std::move(t));
}
```

scoped_thread的用法：

```c
class scoped_thread {
private:
    std::thread t;
public:
    explicit scoped_thread(std::thread t_) : t(std::move(t_)) {
        if (!t.joinable())
            throw std::logic_error("No  thread");
    }
    ~scoped_thread() {
        t.join(); 
    }
    scoped_thread(const scoped_thread&) = delete;
    scoped_thread& operator=(const scoped_thread&) = delete;
};

struct func;

void f() {
    int some_local_state;
    scoped_thread t(std::thread(func(some_local_state))); // 新线程直接传递到scope_thread中
    do_something_in_current_thread();
} // f()到达末尾时，逆序销毁
```

量产线程，等待它们结束：

```c
void do_work(unsigned id);
void f() {
    std::vector<std::thread> threads;
    for (unsigned i = 0; i < 20; ++i)
        threads.push_back(std::thread(do_work, i)); //产生线程
    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join)); // 对每个线程调用join
}
```

### 2.4 运行时决定线程数量

std::thread::hardware_concurrency()将返回能同时并发在一个程序中的线程数量。

```c
#include <thread>
#include <vector>
#include <numeric>

template<typename Iterator, typename T>
struct accumulate_block {
    void operator()(Iterator first, Iterator last, T& result) {
        result = std::accumulate(first, last, result);
    }
};

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init) {
    unsigned long const length = std::distance(first, last);
    if (!length) // 如果输入的范围为空，就会得到init的值。
        return init;
    unsigned long const min_per_thread = 25; // 线程(块)中最小任务数
    // 用范围内元素的总数量除以线程(块)中最小任务数，从而确定启动线程的最大数量
    unsigned long const max_threads =
        (length + min_per_thread - 1) / min_per_thread;

    unsigned long const hardware_threads = std::thread::hardware_concurrency();

    // 计算量的最大值和硬件支持线程数中，较小的值为启动线程的数量
    unsigned long const num_threads =
        std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);

    // 每个线程中处理的元素数量,是范围中元素的总量除以线程的个数得出的
    unsigned long const block_size = length / num_threads;

    std::vector<T> results(num_threads); // 创建一个 std::vector<T> 容器存放中间结果
    std::vector<std::thread> threads(num_threads - 1); // 为线程创建一个 std::vector<std::thread> 容器

    Iterator block_start = first;
    for (unsigned long i = 0; i < (num_threads - 1); ++i) {
        Iterator block_end = block_start;
        std::advance(block_end, block_size); // block_end迭代器指向当前块的末尾
        threads[i] = std::thread( // 启动一个新线程为当前块累加结果
            accumulate_block<Iterator, T>(),
            block_start, block_end, std::ref(results[i])
        );
        block_start = block_end; // 当迭代器指向当前块的末尾时，启动下一个块
    }
    accumulate_block<Iterator, T>()( // 启动所有线程后，中的线程会处理最终块的结果
        block_start, last, results[num_threads - 1] // 对于分配不均，因为知道最终块是哪一个，那么这个块中有多少个元素就无所谓了。
    );
    // 累加最终块的结果后，可以等待 std::for_each 创建线程的完成
    std::for_each(threads.begin(), threads.end(), std::men_fn(&std::thread::join));
    // 使用 std::accumulate 将所有结果进行累加
    return std::accumulate(results.begin(), results.end(), init);
}
```

因为不能直接从一个线程中返回一个值，所以需要传递results容器的引用到线程中去。另一个办法，通过地址来获取线程执行的结果；第4章中，我们将使用期望(futures)完成这种方案。

### 2.5 识别线程

线程标识类型是 std::thread::id ，可以通过两种方式进行检索：

第一种，可以通过调用 std::thread 对象的成员函数 get_id() 来直接获取。

第二种，当前线程中调用 std::this_thread::get_id() (这个函数定义在 <thread> 头文件中)也可以获得线程标识。

std::thread::id 对象可以自由的拷贝和对比,因为标识符就可以复用。如果两个对象的 std::thread::id 相等，那它们就是同一个线程。

std::thread::id 类型对象提供相当丰富的对比操作；比如，提供为不同的值进行排序。

算法核心部分(所有线程都一样的),每个线程都要检查一下，其拥有的线程ID是否与初始线程的ID相同。

```c
std::thread::id master_thread;
void some_core_part_of_algorithm() {
    if (std::this_thread::get_id() == master_thread)
        do_master_thread_work();
    do_common_work();
}
```

## 第3章 线程间共享数据

### 3.1 共享数据带来的问题

线程间潜在问题就是修改共享数据，致使不变量遭到破坏。

#### 3.1.1 条件竞争（Race Condition）

并发中竞争条件的形成，取决于一个以上线程的相对执行顺序，每个线程都抢着完成自己的任务。

并发中对数据的条件竞争通常表示为恶性条件竞争。条件竞争很难查找，也很难复现。C++ 标准中也定义了数据竞争这个术语，一种特殊的条件竞争：并发的去修改一个独立对象，数据竞争是(可怕的)未定义行为的起因。

#### 3.1.2 避免恶性条件竞争

最简单的办法就是对数据结构采用某种保护机制，确保只有进行修改的线程才能看到不变量被破坏时的中间状态。从其他访问线程的角度来看，修改不是已经完成了，就是还没开始。

另一个选择是对数据结构和不变量的设计进行修改，修改完的结构必须能完成一系列不可分割的变化，也就是保证每个不变量保持稳定的状态，这就是所谓的无锁编程。

另一种处理条件竞争的方式是，使用事务的方式去处理数据结构的更新(这里的"处理"就如同对数据库进行更新一样)。

### 3.2 使用互斥量保护共享数据

当访问共享数据前，使用互斥量将相关数据锁住，再当访问结束后，再将数据解锁。

#### 3.2.1 C++中使用互斥量

C++中通过实例化 std::mutex 创建互斥量，通过调用成员函数lock()进行上锁，unlock()进行解锁。

C++标准库为互斥量提供了一个RAII语法的模板类 std::lock_guard ，其会在构造的时候提供已锁的互斥量，并在析构的时候进行解锁，从而保证了一个已锁的互斥量总是会被正确的解锁。

```c
#include <list>
#include <mutex>
#include <algorithm>

std::list<int> some_list; // 全局变量
std::mutex some_mutex; // 这个全局变量被一个全局的互斥量保护

void add_to_list(int new_value) {
    std::lock_guard<std::mutex> guard(some_mutex);
    some_list.push_back(new_value);
}

bool list_contains(int value_to_find) {
    std::lock_guard<std::mutex> guard(some_mutex);
    return std::find(some_list.begin(), some_list.end(), value_to_find) != some_list.end();
}
```

add_to_list()和list_contains()函数中使用 std::lock_guard<std::mutex> ，使得这两个函数中对数据的访问是互斥的：list_contains()不可能看到正在被add_to_list()修改的列表。

当其中一个成员函数返回的是保护数据的指针或引用时，会破坏对数据的保护。具有访问能力的指针或引用可以访问(并可能修改)被保护的数据，而不会被互斥锁限制。互斥量保护的数据需要对接口的设计相当谨慎，要确保互斥量能锁住任何对保护数据的访问，并且不留后门。

#### 3.2.2 精心组织代码来保护共享数据

无意中传递了保护数据的引用：

```c
class some_data {
    int a;
    std::string b;
public:
    void do_something();
};
class data_wrapper {
private:
    some_data data;
    std::mutex m;
public:
    template <typename Function>
    void process_data(Function func) {
        std::lock_guard<std::mutex> l(m);
        func(data); // 1 传递“保护”数据给用户函数
    }
};
some_data *unprotected;
void malicious_function(some_data &protected_data) {
    unprotected = &protected_data;
}
data_wrapper x;
void foo() {
    x.process_data(malicious_function); // 2 传递一个恶意函数
    unprotected->do_something();        // 3 在无保护的情况下访问保护数据
}
```

这段代码的问题在于根本没有保护，只是将所有可访问的数据结构代码标记为互斥。C++线程库无法提供任何帮助，只能由程序员来使用正确的互斥锁来保护数据。从乐观的角度上看，还是有方法可循的：切勿将受保护数据的指针或引用传递到互斥锁作用域之外，无论是函数返回值，还是存储在外部可见内存，亦或是以参数的形式传递到用户提供的函数中去。

#### 3.2.3 发现接口内在的条件竞争







```c

```

```c

```

```c

```
































