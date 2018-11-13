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