#pragma once

#ifndef THREAD_GROUP_H_MQSLWGKD
#define THREAD_GROUP_H_MQSLWGKD

#include <vector>
#include <thread>

namespace callme {
namespace detail {

class thread_group {
public:
    thread_group() {}
    thread_group(thread_group const &) = delete;

    void create_threads(std::size_t thread_count, std::function<void()> func) {
        for (std::size_t i = 0; i < thread_count; ++i) {
            threads_.push_back(std::thread(func));
        }
    }

    void join_all() {
        for (auto &t : threads_) {
            t.join();
        }
    }

    ~thread_group() { join_all(); }

private:
    std::vector<std::thread> threads_;
};

} /* detail */
} /* callme  */

#endif /* end of include guard: THREAD_GROUP_H_MQSLWGKD */
