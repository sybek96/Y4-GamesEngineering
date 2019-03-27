#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H


#include <condition_variable>
#include <functional>
#include <thread>
#include <future>
#include <queue>
#include <array>


class ThreadPool
{
public:
	using Task = std::function<void()>;

	explicit ThreadPool(std::size_t numThreads);

	~ThreadPool();

	template<class T>
	auto enqueue(T task)->std::future<decltype(task())>
	{
		auto wrapper = std::make_shared<std::packaged_task<decltype(task()) ()>>(std::move(task));
		{
			std::unique_lock<std::mutex> lock{ m_eventMutex };
			m_tasks.emplace([=] {
				(*wrapper)();
			});
		}

		m_eventVar.notify_one();
		return wrapper->get_future();
	}
private:
	std::vector<std::thread> m_threads;
	std::condition_variable m_eventVar;
	std::mutex m_eventMutex;
	bool m_stopping = false;
	std::queue<Task> m_tasks;

	void start(std::size_t numThreads);

	void stop() noexcept;

};
#endif // !_THREAD_POOL_H