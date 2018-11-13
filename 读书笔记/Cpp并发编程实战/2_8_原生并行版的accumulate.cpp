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