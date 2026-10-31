#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>
#include <stdexcept>
#include <type_traits>

using namespace std;

class ThreadPool {
private:
    vector<thread> workers;
    queue<function<void()>> tasks;

    mutex queueMutex;
    condition_variable condition;
    bool stopped = false;

public:
    explicit ThreadPool(size_t threadCount) {
        if (threadCount == 0)
            throw invalid_argument("Thread count must be positive.");

        for (size_t i = 0; i < threadCount; i++) {
            workers.emplace_back([this]() {
                while (true) {
                    function<void()> task;

                    {
                        unique_lock<mutex> lock(queueMutex);

                        condition.wait(lock, [this]() {
                            return stopped || !tasks.empty();
                        });

                        if (stopped && tasks.empty())
                            return;

                        task = move(tasks.front());
                        tasks.pop();
                    }

                    task();
                }
            });
        }
    }

    template<class F, class... Args>
    auto submit(F&& f, Args&&... args)
        -> future<typename invoke_result<F, Args...>::type> {

        using ReturnType = typename invoke_result<F, Args...>::type;

        auto task = make_shared<packaged_task<ReturnType()>>(
            bind(
                forward<F>(f),
                forward<Args>(args)...
            )
        );

        future<ReturnType> result = task->get_future();

        {
            lock_guard<mutex> lock(queueMutex);

            if (stopped)
                throw runtime_error("Thread pool is stopped.");

            tasks.emplace([task]() {
                (*task)();
            });
        }

        condition.notify_one();
        return result;
    }

    ~ThreadPool() {
        {
            lock_guard<mutex> lock(queueMutex);
            stopped = true;
        }

        condition.notify_all();

        for (thread& worker : workers) {
            if (worker.joinable())
                worker.join();
        }
    }

    ThreadPool(const ThreadPool&) = delete;
    ThreadPool& operator=(const ThreadPool&) = delete;
};

long long calculateSquareSum(int n) {
    long long sum = 0;

    for (int i = 1; i <= n; i++)
        sum += 1LL * i * i;

    return sum;
}

int main() {
    ThreadPool pool(4);

    vector<future<long long>> results;

    for (int i = 1; i <= 8; i++) {
        results.push_back(
            pool.submit(calculateSquareSum, i * 1000)
        );
    }

    cout << "Thread Pool Results:\n";

    for (size_t i = 0; i < results.size(); i++) {
        cout << "Task " << i + 1
             << ": " << results[i].get() << '\n';
    }

    cout << "\nAll tasks completed.\n";

    return 0;
}
