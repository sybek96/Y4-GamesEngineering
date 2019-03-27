#include "ThreadPool.h"

ThreadPool::ThreadPool(std::size_t numThreads)
{
	start(numThreads);
}

ThreadPool::~ThreadPool()
{
	stop();
}

void ThreadPool::start(std::size_t numThreads)
{
	for (auto i = 0u; i < numThreads; ++i)
	{
		m_threads.emplace_back([=] {
			while (true)
			{
				Task task;

				{
					//Critical section kept as small as possible
					std::unique_lock<std::mutex> lock{ m_eventMutex };

					m_eventVar.wait(lock, [=] {return m_stopping || !m_tasks.empty(); });

					if (m_stopping && m_tasks.empty())
					{
						break;
					}
					//take first task from queue and execute it
					task = std::move(m_tasks.front());
					m_tasks.pop();
					//lock released on scope exit
					//taks executed without mutex lock
					task();

				}
			}
		});
	}
}

void ThreadPool::stop() noexcept
{
	{
		std::unique_lock<std::mutex> lock{ m_eventMutex };
		m_stopping = true;
	}

	m_eventVar.notify_all();
	for (auto &thread : m_threads)
	{
		thread.join();
	}
}
