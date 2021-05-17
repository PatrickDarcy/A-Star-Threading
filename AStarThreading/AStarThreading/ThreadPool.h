#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <iostream>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <chrono>
#include "AStar.h"
#include <condition_variable>

using namespace std;

static bool s_finished = false;

class ThreadPool {
public:
	ThreadPool();
	~ThreadPool();
	void addTask(std::function<void()>);
	static void infiniteLoop(ThreadPool& t_threadPool);
	condition_variable m_condition;
	std::function<void()> Job;
private:
	bool terminate = false;
	mutex s_lock;
	vector<std::thread> m_threads;
	queue<std::function<void()>> m_tasks;
};
#endif // !THREAD_POOL_H

