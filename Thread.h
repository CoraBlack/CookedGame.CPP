//线程类
#ifndef THREAD_H
#define THREAD_H
#include<thread>
#include<mutex>
#include"Customer.h"
#include <functional> 
class Thread{
public:
	std::mutex mtx;									//线程锁，用于暂停线程函数
	Thread(std::function <void()> func);			//构造函数，构造后台线程
	std::thread::id GetThreadID();					//获取线程的ID
	void PauseThread();								//暂停线程
	void StopThread();								//终止进程
private:
	std::thread* trdworker;						//线程
	bool state = 0;								//线程状态，0为停止，1为运行
};
#endif
