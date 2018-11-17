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

std::stack容器的实现：

```c
#include <deque>
template <typename T, typename Container = std::deque<T>>
class stack {
public:
    explicit stack(const Container &);
    explicit stack(Container && = Container());
    template <class Alloc>
    explicit stack(const Alloc &);
    template <class Alloc>
    stack(const Container &, const Alloc &);
    template <class Alloc>
    stack(Container &&, const Alloc &);
    template <class Alloc>
    stack(stack &&, const Alloc &);
    bool empty() const;
    size_t size() const;
    T &top();
    T const &top() const;
    void push(T const &);
    void push(T &&);
    void pop();
    void swap(stack &&);
};
```

当栈实例是非共享的，如果栈非空，使用empty()检查再调用top()访问栈顶部的元素是安全的：

```c
stack<int> s;
if (! s.empty()){ // 1
    int const value = s.top(); // 2
    s.pop(); // 3
    do_something(value);
}
```

以上是单线程安全代码：对一个空栈使用top()是未定义行为。对于共享的栈对象，这样的调用顺序就不再安全了，因为在调用empty()①和调用top()②之间，可能有来自另一个线程的pop()调用并删除了最后一个元素。这是一个经典的条件竞争，使用互斥量对栈内部数据进行保护，但依旧不能阻止条件竞争的发生，这就是接口固有的问题。

问题发生在接口设计上，所以解决的方法也就是改变接口设计。

选项1：传入一个引用

选项2：无异常抛出的拷贝构造函数或移动构造函数

选项3：返回指向弹出值的指针

选项4：“选项1 + 选项2”或 “选项1 + 选项3”

线程安全的堆栈类：

```c
#include <exception>
#include <memory> // For std::shared_ptr<>
struct empty_stack : std::exception {
    const char *what() const throw();
};
template <typename T>
class threadsafe_stack {
public:
    threadsafe_stack();
    threadsafe_stack(const threadsafe_stack &);
    threadsafe_stack &operator=(const threadsafe_stack &) = delete; // 1 赋值操作被删除
    void push(T new_value);
    std::shared_ptr<T> pop(); // 重载了pop()，使用一个局部引用去存储弹出值，并返回一个 std::shared_ptr<> 对象
    void pop(T &value);
    bool empty() const;
};
```

扩充线程安全的堆栈类：

```c
#include <exception>
#include <memory>
#include <mutex>
#include <stack>
struct empty_stack : std::exception {
    const char *what() const throw() {
        return "empty stack!";
    };
};
template <typename T>
class threadsafe_stack {
private:
    std::stack<T> data;
    mutable std::mutex m;
public:
    threadsafe_stack()
        : data(std::stack<T>()) {}
    threadsafe_stack(const threadsafe_stack &other) {
        std::lock_guard<std::mutex> lock(other.m); // 拷贝构造函数对互斥量上锁
        data = other.data; // 1 在构造函数体中的执行拷贝
    }
    threadsafe_stack &operator=(const threadsafe_stack &) = delete;
    void push(T new_value) {
        std::lock_guard<std::mutex> lock(m);
        data.push(new_value);
    }
    std::shared_ptr<T> pop() {
        std::lock_guard<std::mutex> lock(m);
        if (data.empty())
            throw empty_stack(); // 在调用pop前，检查栈是否为空
        std::shared_ptr<T> const res(std::make_shared<T>(data.top())); // 在修改堆栈前，分配出返回值
        data.pop();
        return res;
    }
    void pop(T &value) {
        std::lock_guard<std::mutex> lock(m);
        if (data.empty())
            throw empty_stack();
        value = data.top();
        data.pop();
    }
    bool empty() const {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
};
```

#### 3.2.4 死锁：问题描述及解决方案

一对线程需要对他们所有的互斥量做一些操作，其中每个线程都有一个互斥量，且等待另一个解锁。这样没有线程能工作，因为他们都在等待对方释放互斥量。这种情况就是死锁，它的最大问题就是由两个或两个以上的互斥量来锁定一个操作。

std::lock可以一次性锁住多个(两个以上)的互斥量，并且没有副作用(死锁风险)。std::lock要么将两个锁都锁住，要不一个都不锁。

```c
#include <mutex>

class some_big_object;
void swap(some_big_object &lhs, some_big_object &rhs);
class X {
private:
    some_big_object some_detail;
    std::mutex m;

public:
    X(some_big_object const &sd) : some_detail(sd) {}

    friend void swap(X &lhs, X &rhs)
    {
        if (&lhs == &rhs) // 检查参数是否是不同的实例，因为操作试图获取std::mutex对象上的锁，所以当其被获取时，结果很难预料
            return;
        std::lock(lhs.m, rhs.m);                                    // 1 调用std::lock()锁住两个互斥量
        std::lock_guard<std::mutex> lock_a(lhs.m,std::adopt_lock);  // 2 std::adopt_lock参数除了表示std::lock_guard对象可获取锁之外，
        std::lock_guard<std::mutex> lock_b(rhs.m, std::adopt_lock); // 3 还将锁交由std::lock_guard对象管理，而不需要std::lock_guard对象再去构建新的锁。
        swap(lhs.some_detail, rhs.some_detail);
    }
};
```

#### 3.2.5 避免死锁的进阶指导

虽然锁是产生死锁的一般原因，但也不排除死锁出现在其他地方。无锁的情况下，仅需要每个std::thread对象调用join()，两个线程就能产生死锁。这种情况下，没有线程可以继续运行，因为他们正在互相等待。

* 避免嵌套锁

一个线程已获得一个锁时，再别去获取第二个。

* 避免在持有锁时调用用户提供的代码

* 使用固定顺序获取锁

* 使用锁的层次结构

* 超越锁的延伸扩展

#### 3.2.6 std::unique_lock——灵活的锁

std::unqiue_lock使用更为自由的不变量，这样std::unique_lock实例不会总与互斥量的数据类型相关，使用起来要比std:lock_guard更加灵活。首先，可将std::adopt_lock作为第二个参数传入构造函数，对互斥量进行管理；也可以将std::defer_lock作为第二个参数传递进去，表明互斥量应保持解锁状态。这样，就可以被std::unique_lock对象(不是互斥量)的lock()函数的所获取，或传递std::unique_lock对象到std::lock()中。保证灵活性要付出代价，这个代价就是允许std::unique_lock实例不带互斥量：信息已被存储，且已被更新。

```c
#include <mutex>

class some_big_object;
void swap(some_big_object &lhs, some_big_object &rhs);
class X {
  private:
    some_big_object some_detail;
    std::mutex m;

  public:
    X(some_big_object const &sd) : some_detail(sd) {}
    friend void swap(X &lhs, X &rhs) {
        if (&lhs == &rhs)
            return;
        std::unique_lock<std::mutex> lock_a(lhs.m, std::defer_lock); // 1
        std::unique_lock<std::mutex> lock_b(rhs.m, std::defer_lock); // 1 std::def_lock 留下未上锁的互斥量
        std::lock(lock_a, lock_b);                                   // 2 互斥量在这里上锁
        swap(lhs.some_detail, rhs.some_detail);
    }
};
```

#### 3.2.7 不同域中互斥量所有权的传递

std::unique_lock实例没有与自身相关的互斥量，一个互斥量的所有权可以通过移动操作，在不同的实例中进行传递。std::unique_lock是可移动，但不可赋值的类型。一种使用可能是允许一个函数去锁住一个互斥量，并且将所有权移到调用者上，所以调用者可以在这个锁保护的范围内执行额外的动作。

```c
std::unique_lock<std::mutex> get_lock() {
    extern std::mutex some_mutex;
    std::unique_lock<std::mutex> lk(some_mutex);
    prepare_data();
    return lk;  // 1  lk在函数中被声明为自动变量，它不需要调用std::move()，可以直接返回(编译器负责调用移动构造函数)。
}
void process_data() {
    std::unique_lock<std::mutex> lk(get_lock());  // 2
    do_something();
}
```

#### 3.2.8 锁的粒度

锁的粒度是一个摆手术语(hand-waving term)，用来描述通过一个锁保护着的数据量大小。一个细粒度锁(a fine-grained lock)能够保护较小的数据量，一个粗粒度锁(a coarse-grained lock)能够保护较多的数据量。

如果很多线程正在等待同一个资源，当有线程持有锁的时间过长，这就会增加等待的时间。在可能的情况下，锁住互斥量的同时只能对共享数据进行访问。

std::unique_lock在这种情况下工作正常，在调用unlock()时，代码不需要再访问共享数据；而后当再次需要对共享数据进行访问时，就可以再调用lock()了。

```c
void get_and_process_data() {
    std::unique_lock<std::mutex> my_lock(the_mutex);
    some_class data_to_process=get_next_data_chunk();
    my_lock.unlock();  // 1 不要让锁住的互斥量越过process()函数的调用
    result_type result=process(data_to_process);
    my_lock.lock();    // 2 为了写入数据，对互斥量再次上锁
    write_result(data_to_process,result);
}
```

锁不仅是能锁住合适粒度的数据，还要控制锁的持有时间，以及什么操作在执行的同时能够拥有锁。一般情况下，执行必要的操作时，尽可能将持有锁的时间缩减到最小。

### 3.3 保护共享数据的替代设施

互斥量是最通用的机制，但其并非保护共享数据的唯一方式。

#### 3.3.1 保护共享数据的初始化过程

std::once_flag和std::call_once。每个线程只需要使用std::call_once，在std::call_once的结束时，就能安全的知道指针已经被其他的线程初始化了。

```c
std::shared_ptr<some_resource> resource_ptr;
std::once_flag resource_flag;  // 1
void init_resource() {
    resource_ptr.reset(new some_resource);
}
void foo() {
    std::call_once(resource_flag,init_resource);  // 可以完整的进行一次初始化
    resource_ptr->do_something();
}
```

一个局部变量被声明为static类型。这种变量在声明后就已经完成初始化；对于多线程调用的函数，这就意味着这里有条件竞争——抢着去定义这个变量。在C++11标准中，这些问题都被解决了：初始化及定义完全在一个线程中发生，并且没有其他线程可在初始化完成前对其进行处理，条件竞争终止于初始化阶段，这样比在之后再去处理好的多。在只需要一个全局实例（单例模式）情况下，这里提供一个std::call_once的替代方案：

```c
class my_class;
my_class& get_my_class_instance() {
    static my_class instance;  // 线程安全的初始化过程
    return instance;
}
```

#### 3.3.2 保护很少更新的数据结构

这种互斥量常被称为“读者-作者锁”，因为其允许两种不同的使用方式：一个“作者”线程独占访问和共享访问，让多个“读者”线程并发访问。C++标准库依旧不会提供这样的互斥量。使用的是Boost库提供的实现，比起使用std::mutex实例进行同步，不如使用boost::shared_mutex来做同步。

下面的代码清单展示了一个简单的DNS缓存，使用std::map持有缓存数据，使用boost::shared_mutex进行保护。

```c
#include <map>
#include <string>
#include <mutex>
#include <boost/thread/shared_mutex.hpp>

class dns_entry;

class dns_cache {
     std::map<std::string,dns_entry> entries;
     mutable boost::shared_mutex entry_mutex;
public:
    dns_entry find_entry(std::string const& domain) const {
        boost::shared_lock<boost::shared_mutex> lk(entry_mutex);  // 1
        std::map<std::string,dns_entry>::const_iterator const it=
        entries.find(domain);
        return (it==entries.end())?dns_entry():it->second;
    }
    void update_or_add_entry(std::string const& domain,
                           dns_entry const& dns_details) {
        std::lock_guard<boost::shared_mutex> lk(entry_mutex);  // 2
        entries[domain]=dns_details;
    }
};
```

#### 嵌套锁

当一个线程已经获取一个std::mutex时(已经上锁)，并对其再次上锁，这个操作就是错误的，并且继续尝试这样做的话，就会产生未定义行为。然而，在某些情况下，一个线程尝试获取同一个互斥量多次，而没有对其进行一次释放是可以的。之所以可以，是因为C++标准库提供了std::recursive_mutex类。其功能与std::mutex类似，除了你可以从同一线程的单个实例上获取多个锁。互斥量锁住其他线程前，你必须释放你拥有的所有锁，所以当你调用lock()三次时，你也必须调用unlock()三次。正确使用std::lock_guard<std::recursive_mutex>和std::unique_lock<std::recursive_mutex>可以帮你处理这些问题。

## 第4章 同步并发操作

### 4.1 等待一个事件或其他条件

当一个线程等待另一个线程完成任务时，它会有很多选择。

第一，它可以持续的检查共享数据标志(用于做保护工作的互斥量)，直到另一线程完成工作时对这个标志进行重设。不过，就是一种浪费：线程消耗宝贵的执行时间持续的检查对应标志，并且当互斥量被等待线程上锁后，其他线程就没有办法获取锁，这样线程就会持续等待。

第二个选择是在等待线程在检查间隙，使用std::this_thread::sleep_for()进行周期性的间歇。

第三个选择(也是优先的选择)是，使用C++标准库提供的工具去等待事件的发生。通过另一线程触发等待事件的机制是最基本的唤醒方式(例如：流水线上存在额外的任务时)，这种机制就称为“条件变量”。从概念上来说，一个条件变量会与多个事件或其他条件相关，并且一个或多个线程会等待条件的达成。当某些线程被终止时，为了唤醒等待线程(允许等待线程继续执行)终止的线程将会向等待着的线程广播“条件达成”的信息。

#### 4.1.1 等待条件达成

C++标准库对条件变量有两套实现：std::condition_variable和std::condition_variable_any。这两个实现都包含在<condition_variable>头文件的声明中。两者都需要与一个互斥量一起才能工作(互斥量是为了同步)；前者仅限于与std::mutex一起工作，而后者可以和任何满足最低标准的互斥量一起工作，从而加上了_any的后缀。因为std::condition_variable_any更加通用，这就可能从体积、性能，以及系统资源的使用方面产生额外的开销，所以std::condition_variable一般作为首选的类型，当对灵活性有硬性要求时，我们才会去考虑std::condition_variable_any。


### 4.2 使用期望等待一次性事件

C++标准库模型将这种一次性事件称为期望(future)。当一个线程需要等待一个特定的一次性事件时，在某种程度上来说它就需要知道这个事件在未来的表现形式。之后，这个线程会周期性(较短的周期)的等待或检查，事件是否触发；在检查期间也会执行其他任务。另外，在等待任务期间它可以先执行另外一些任务，直到对应的任务触发，而后等待期望的状态会变为就绪(ready)。一个“期望”可能是数据相关的，也可能不是。当事件发生时(并且期望状态为就绪)，这个“期望”就不能被重置。

在C++标准库中，有两种“期望”，使用两种类型模板实现，声明在头文件中: 唯一期望(unique futures)(std::future<>)和共享期望(shared futures)(std::shared_future<>)。std::future的实例只能与一个指定事件相关联，而std::shared_future的实例就能关联多个事件。后者的实现中，所有实例会在同时变为就绪状态，并且他们可以访问与事件相关的任何数据。这种数据关联与模板有关，比如std::unique_ptr 和std::shared_ptr的模板参数就是相关联的数据类型。在与数据无关的地方，可以使用std::future<void>与std::shared_future<void>的特化模板。虽然，我希望用于线程间的通讯，但是“期望”对象本身并不提供同步访问。当多个线程需要访问一个独立“期望”对象时，他们必须使用互斥量或类似同步机制对访问进行保护。

#### 4.2.1 带返回值的后台任务

假设，你有一个需要长时间的运算，你需要其能计算出一个有效的值，但是你现在并不迫切需要这个值。你可以启动一个新线程来执行这个计算，但是这就意味着你必须关注如何传回计算的结果，因为std::thread并不提供直接接收返回值的机制。这里就需要std::async函数模板(也是在<future>中声明的)了。
    
当任务的结果你不着急要时，你可以使用std::async启动一个异步任务。与std::thread对象等待的方式不同，std::async会返回一个std::future对象，这个对象持有最终计算出来的结果。当你需要这个值时，你只需要调用这个对象的get()成员函数；并且会阻塞线程直到“期望”状态为就绪为止；之后，返回计算结果。
    
```c
#include <future>
#include <iostream>

int find_the_answer_to_ltuae();
void do_other_stuff();
int main() {
    std::future<int> the_answer=std::async(find_the_answer_to_ltuae);
    do_other_stuff();
    std::cout<<"The answer is "<<the_answer.get()<<std::endl;
}
```
    
与std::thread 做的方式一样，std::async允许你通过添加额外的调用参数，向函数传递额外的参数。
    
#### 4.2.2 任务与期望

std::packaged_task<>对一个函数或可调用对象，绑定一个期望。当std::packaged_task<> 对象被调用，它就会调用相关函数或可调用对象，将期望状态置为就绪，返回值也会被存储为相关数据。

### 4.3 限定等待时间

两种指定的超时方式：一种是“时延”的超时方式，另一种是“绝对”超时方式。第一种方式，需要指定一段时间(例如，30毫秒)；第二种方式，就是指定一个时间点(例如，协调世界时[UTC]17:30:15.045987023，2011年11月30日)。多数等待函数提供变量，对两种超时方式进行处理。处理持续时间的变量以“_for”作为后缀，处理绝对时间的变量以"_until"作为后缀。

### 4.4 使用同步操作简化代码

## 第5章 C++内存模型和原子类型操作








































































































