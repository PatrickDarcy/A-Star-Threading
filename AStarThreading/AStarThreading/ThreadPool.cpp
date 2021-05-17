#include "ThreadPool.h"

ThreadPool::ThreadPool() {
	int cores = thread::hardware_concurrency() - 1;
	for (int i = 0; i < cores; i++)
	{
		m_threads.push_back(thread(infiniteLoop,ref(*this)));

	}
}

ThreadPool::~ThreadPool() {}


void ThreadPool::addTask(function<void()> task) 
{
	m_tasks.push(task);
}

void ThreadPool::infiniteLoop(ThreadPool& t_threadPool)
{
	while (true)
	{
		{
			unique_lock<mutex> lock(t_threadPool.s_lock);

			t_threadPool.m_condition.wait(lock, [&] {return !t_threadPool.m_tasks.empty() || t_threadPool.terminate; });
			t_threadPool.Job = t_threadPool.m_tasks.front();
			t_threadPool.m_tasks.pop();
		}
		t_threadPool.Job();
	}

}
